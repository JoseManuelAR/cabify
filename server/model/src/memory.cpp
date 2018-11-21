#include <model/memory.hpp>

#include <shared_mutex>
#include <unordered_map>

namespace model {

class Memory::MemoryImpl {
public:
  MemoryImpl();

  void start();

  Basket createBasket();
  std::optional<Product> createProduct(BasketId basketId);

private:
  mutable std::shared_mutex mutex_;
  std::unordered_map<BasketId, Basket> _baskets;
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

std::optional<Product> Memory::MemoryImpl::createProduct(BasketId basketId) {
  std::unique_lock<std::shared_mutex> lock(mutex_);
  auto itBasket = _baskets.find(basketId);
  if (itBasket == _baskets.end()) {
    return std::nullopt;
  }
  return itBasket->second.createProduct();
}

Memory::Memory() : _impl{std::make_unique<MemoryImpl>()} {}

Memory::~Memory() {}

void Memory::start() { _impl->start(); }

Basket Memory::createBasket() { return _impl->createBasket(); }

std::optional<Product> Memory::createProduct(BasketId basketId) {
  return _impl->createProduct(basketId);
}

} // namespace model
