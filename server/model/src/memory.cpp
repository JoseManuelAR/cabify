#include <model/memory.hpp>

#include <shared_mutex>
#include <unordered_map>

namespace model {

class Memory::MemoryImpl {
public:
  MemoryImpl();

  void start();

  Basket createBasket();
  std::tuple<common::Error, std::optional<model::Product>> createProduct(BasketId basketId);
  std::tuple<common::Error, std::optional<model::Amount>> getAmount(BasketId basketId);

private:
  mutable std::shared_mutex mutex_;
  std::unordered_map<BasketId, Basket> _baskets;
};

Memory::MemoryImpl::MemoryImpl() {}

void Memory::MemoryImpl::start() {}

Basket Memory::MemoryImpl::createBasket() {
  std::unique_lock<std::shared_mutex> lock(mutex_);
  Basket basket;
  _baskets.insert(std::make_pair<BasketId, Basket>(basket.id(), std::move(basket)));
  return basket;
}

std::tuple<common::Error, std::optional<model::Product>> Memory::MemoryImpl::createProduct(BasketId basketId) {
  std::unique_lock<std::shared_mutex> lock(mutex_);
  auto itBasket = _baskets.find(basketId);
  if (itBasket == _baskets.end()) {
    return std::make_tuple(common::Error::BasketNotFound, std::nullopt);
  }
  return std::make_tuple(common::Error::Success, itBasket->second.createProduct());
}

std::tuple<common::Error, std::optional<model::Amount>> Memory::MemoryImpl::getAmount(BasketId basketId) {
  std::shared_lock<std::shared_mutex> lock(mutex_);
  auto itBasket = _baskets.find(basketId);
  if (itBasket == _baskets.end()) {
    return std::make_tuple(common::Error::BasketNotFound, std::nullopt);
  }
  return std::make_tuple(common::Error::Success, itBasket->second.getAmount());
}

Memory::Memory() : _impl{std::make_unique<MemoryImpl>()} {}

Memory::~Memory() {}

void Memory::start() { _impl->start(); }

Basket Memory::createBasket() { return _impl->createBasket(); }

std::tuple<common::Error, std::optional<model::Product>> Memory::createProduct(BasketId basketId) { return _impl->createProduct(basketId); }

std::tuple<common::Error, std::optional<model::Amount>> Memory::getAmount(BasketId basketId) { return _impl->getAmount(basketId); }

} // namespace model
