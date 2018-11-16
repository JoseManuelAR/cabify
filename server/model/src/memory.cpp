#include <model/memory.hpp>

namespace model {

class Memory::MemoryImpl {
public:
  MemoryImpl();

  void start();

  std::uint64_t createCheckout();

private:
  std::uint64_t _checkoudId = 0;
};

Memory::MemoryImpl::MemoryImpl() {}

void Memory::MemoryImpl::start() {}

std::uint64_t Memory::MemoryImpl::createCheckout() { return _checkoudId++; }

Memory::Memory() : _impl{std::make_unique<MemoryImpl>()} {}

Memory::~Memory() {}

void Memory::start() { _impl->start(); }

std::uint64_t Memory::createCheckout() { return _impl->createCheckout(); }

} // namespace model
