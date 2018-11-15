#include <controller/checkoutcreator.hpp>
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

  void doPostCheckout(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
  void doGetCheckoutAmount(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
};

Rest::RestImpl::RestImpl(std::uint16_t port) : RestImpl(Pistache::Ipv4::any().toString(), port) {}

Rest::RestImpl::RestImpl(const std::string &host, std::uint16_t port) : _host{host}, _port{port}, _model{nullptr} {}

void Rest::RestImpl::start(std::unique_ptr<model::Model> model) {
  _model = std::move(model);

  Pistache::Address addr(_host, _port);
  Pistache::Http::Endpoint httpEndpoint(addr);
  Pistache::Rest::Router router;

  Pistache::Rest::Routes::Post(router, "/checkout/", Pistache::Rest::Routes::bind(&RestImpl::doPostCheckout, this));
  Pistache::Rest::Routes::Get(router, "/checkout/amount", Pistache::Rest::Routes::bind(&RestImpl::doGetCheckoutAmount, this));

  auto opts = Pistache::Http::Endpoint::options().threads(4).flags(Pistache::Tcp::Options::ReuseAddr);
  httpEndpoint.init(opts);
  httpEndpoint.setHandler(router.handler());
  httpEndpoint.serve();
}

void Rest::RestImpl::doGetCheckoutAmount(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
  response.send(Pistache::Http::Code::Ok, std::to_string(1111));
}

void Rest::RestImpl::doPostCheckout(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
  controller::CheckoutCreator checkoutCreator;
  auto id = checkoutCreator.execute(_model);
  response.send(Pistache::Http::Code::Ok, std::to_string(id));
}

Rest::Rest(std::uint16_t port) : Rest(Pistache::Ipv4::any().toString(), port) {}

Rest::Rest(const std::string &host, std::uint16_t port) : _impl{std::make_unique<RestImpl>(host, port)} {}

Rest::~Rest() {}

void Rest::start(std::unique_ptr<model::Model> model) { _impl->start(std::move(model)); }

} // namespace view