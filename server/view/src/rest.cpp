#include <controller/amountgetter.hpp>
#include <controller/basketcreator.hpp>
#include <controller/productcreator.hpp>
#include <model/model.hpp>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <view/rest.hpp>

namespace view {

class Rest::RestImpl {
public:
  RestImpl(std::uint16_t port);
  RestImpl(const std::string &host, std::uint16_t port);

  void start(std::unique_ptr<model::Model> model);

private:
  std::string _host;
  std::uint16_t _port = 0;
  std::shared_ptr<model::Model> _model;

  void doPostBasket(const Pistache::Rest::Request &request,
                    Pistache::Http::ResponseWriter response);
  void doPostProduct(const Pistache::Rest::Request &request,
                     Pistache::Http::ResponseWriter response);
  void doGetBasketAmount(const Pistache::Rest::Request &request,
                         Pistache::Http::ResponseWriter response);
};

Rest::RestImpl::RestImpl(std::uint16_t port)
    : RestImpl(Pistache::Ipv4::any().toString(), port) {}

Rest::RestImpl::RestImpl(const std::string &host, std::uint16_t port)
    : _host{host}, _port{port}, _model{nullptr} {}

void Rest::RestImpl::start(std::unique_ptr<model::Model> model) {
  _model = std::move(model);

  Pistache::Address addr(_host, _port);
  Pistache::Http::Endpoint httpEndpoint(addr);
  Pistache::Rest::Router router;

  Pistache::Rest::Routes::Post(
      router, "/basket/",
      Pistache::Rest::Routes::bind(&RestImpl::doPostBasket, this));
  Pistache::Rest::Routes::Post(
      router, "/basket/:basketid/product/",
      Pistache::Rest::Routes::bind(&RestImpl::doPostProduct, this));
  Pistache::Rest::Routes::Get(
      router, "/basket/:basketid/amount",
      Pistache::Rest::Routes::bind(&RestImpl::doGetBasketAmount, this));

  auto opts = Pistache::Http::Endpoint::options().threads(4).flags(
      Pistache::Tcp::Options::ReuseAddr);
  httpEndpoint.init(opts);
  httpEndpoint.setHandler(router.handler());
  httpEndpoint.serve();
}

void Rest::RestImpl::doGetBasketAmount(
    const Pistache::Rest::Request &request,
    Pistache::Http::ResponseWriter response) {
  auto basketId = request.param(":basketid").as<std::uint64_t>();
  controller::AmountGetter amountGetter;
  amountGetter.execute(_model);
  response.send(Pistache::Http::Code::Ok, std::to_string(basketId));
}

void Rest::RestImpl::doPostProduct(const Pistache::Rest::Request &request,
                                   Pistache::Http::ResponseWriter response) {
  auto basketId = request.param(":basketid").as<std::uint64_t>();
  controller::ProductCreator productCreator{basketId};
  auto product = productCreator.execute(_model);
  if (product) {
    response.send(Pistache::Http::Code::Ok, product->toJson().dump());
  } else {
    response.send(Pistache::Http::Code::Not_Found,
                  Pistache::Http::codeString(Pistache::Http::Code::Not_Found));
  }
}

void Rest::RestImpl::doPostBasket(const Pistache::Rest::Request &request,
                                  Pistache::Http::ResponseWriter response) {
  controller::BasketCreator basketCreator;
  auto basket = basketCreator.execute(_model);
  response.send(Pistache::Http::Code::Ok, basket.toJson().dump());
}

Rest::Rest(std::uint16_t port) : Rest(Pistache::Ipv4::any().toString(), port) {}

Rest::Rest(const std::string &host, std::uint16_t port)
    : _impl{std::make_unique<RestImpl>(host, port)} {}

Rest::~Rest() {}

void Rest::start(std::unique_ptr<model::Model> model) {
  _impl->start(std::move(model));
}

} // namespace view