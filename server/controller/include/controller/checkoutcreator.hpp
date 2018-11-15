#include <cstdint>
#include <memory>

namespace model {
class Model;
}

namespace controller {
class CheckoutCreator {
public:
  std::uint64_t execute(std::shared_ptr<model::Model> model);
};
} // namespace controller