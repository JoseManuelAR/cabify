#include <model/memory.hpp>

namespace model {

class Memory::MemoryImpl {
public:
  MemoryImpl();

  void start();

private:
};

Memory::MemoryImpl::MemoryImpl() {}

void Memory::MemoryImpl::start() {}

Memory::Memory() : _impl{std::make_unique<MemoryImpl>()} {}

Memory::~Memory() {}

void Memory::start() { _impl->start(); }

std::uint64_t Memory::createCheckout() { return 1234; }

} // namespace model
