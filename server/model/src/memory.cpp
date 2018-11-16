#include <model/memory.hpp>

namespace model {

class Memory::MemoryImpl {
public:
  MemoryImpl();

  void start();

  BasketId createBasket();

private:
};

Memory::MemoryImpl::MemoryImpl() {}

void Memory::MemoryImpl::start() {}

BasketId Memory::MemoryImpl::createBasket() { return 0; }

Memory::Memory() : _impl{std::make_unique<MemoryImpl>()} {}

Memory::~Memory() {}

void Memory::start() { _impl->start(); }

BasketId Memory::createBasket() { return _impl->createBasket(); }

} // namespace model
