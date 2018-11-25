#include <model/memory.hpp>

#include <shared_mutex>
#include <unordered_map>

namespace model {

class StockItem {
public:
  StockItem(const std::string &code, const std::string &name, float price)
      : _code{code}, _name{name}, _price{price} {}

  nlohmann::json toJson() {
    nlohmann::json val = nlohmann::json::object();

    val["code"] = _code;
    val["name"] = _name;
    val["price"] = _price;
    return val;
  }

  const std::string &code() const { return _code; }
  const std::string &name() const { return _name; }
  float price() const { return _price; }

private:
  std::string _code;
  std::string _name;
  float _price;
};

class Memory::MemoryImpl {
public:
  MemoryImpl();

  void start();

  Basket createBasket();
  std::tuple<common::Error, std::optional<model::Product>>
  createProduct(BasketId basketId, const std::string &code);
  std::tuple<common::Error,
             std::optional<std::unordered_map<std::string, std::uint64_t>>>
  getProducts(BasketId basketId);
  common::Error addStock(const std::string &code, const std::string &name,
                         float price);

private:
  mutable std::shared_mutex mutex_;
  std::unordered_map<BasketId, Basket> _baskets;
  std::unordered_map<std::string, StockItem> _stock;
};

Memory::MemoryImpl::MemoryImpl() {}

void Memory::MemoryImpl::start() {}

Basket Memory::MemoryImpl::createBasket() {
  std::unique_lock<std::shared_mutex> lock(mutex_);
  Basket basket;
  _baskets.insert(
      std::make_pair<BasketId, Basket>(basket.id(), std::move(basket)));
  return basket;
}

std::tuple<common::Error, std::optional<model::Product>>
Memory::MemoryImpl::createProduct(BasketId basketId, const std::string &code) {
  std::unique_lock<std::shared_mutex> lock(mutex_);
  auto itBasket = _baskets.find(basketId);
  if (itBasket == _baskets.end()) {
    return std::make_tuple(common::Error::BasketNotFound, std::nullopt);
  }
  {
    auto item = _stock.find(code);
    if (item != _stock.end()) {
      itBasket->second.createProduct(code);
      return std::make_tuple(common::Error::Success,
                             Product{item->second.code(), item->second.name(),
                                     item->second.price()});
    } else {
      return std::make_tuple(common::Error::BasketNotFound, std::nullopt);
    }
  }
}

std::tuple<common::Error,
           std::optional<std::unordered_map<std::string, std::uint64_t>>>
Memory::MemoryImpl::getProducts(BasketId basketId) {
  std::shared_lock<std::shared_mutex> lock(mutex_);
  auto itBasket = _baskets.find(basketId);
  if (itBasket == _baskets.end()) {
    return std::make_tuple(common::Error::BasketNotFound, std::nullopt);
  }
  return std::make_tuple(common::Error::Success,
                         itBasket->second.getProducts());
}

common::Error Memory::MemoryImpl::addStock(const std::string &code,
                                           const std::string &name,
                                           float price) {
  auto item = _stock.find(code);
  if (item == _stock.end()) {
    StockItem stockItem{code, name, price};
    _stock.insert(std::make_pair<std::string, StockItem>(code.c_str(),
                                                         std::move(stockItem)));
    return common::Error::Success;
  }
  return common::Error::StockExistsCode;
}

Memory::Memory() : _impl{std::make_unique<MemoryImpl>()} {}

Memory::~Memory() {}

void Memory::start() { _impl->start(); }

Basket Memory::createBasket() { return _impl->createBasket(); }

std::tuple<common::Error, std::optional<model::Product>>
Memory::createProduct(BasketId basketId, const std::string &code) {
  return _impl->createProduct(basketId, code);
}

std::tuple<common::Error,
           std::optional<std::unordered_map<std::string, std::uint64_t>>>
Memory::getProducts(BasketId basketId) {
  return _impl->getProducts(basketId);
}

common::Error Memory::addStock(const std::string &code, const std::string &name,
                               float price) {
  return _impl->addStock(code, name, price);
}

} // namespace model
