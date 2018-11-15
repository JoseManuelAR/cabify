
#include <memory>
#include <model/model.hpp>

namespace model {

class Memory : public Model {
public:
  Memory();
  ~Memory();

  void start() override;

  std::uint64_t createCheckout() override;

private:
  class MemoryImpl;
  std::unique_ptr<MemoryImpl> _impl;
};

} // namespace model