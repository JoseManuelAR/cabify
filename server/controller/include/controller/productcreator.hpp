#include <model/model.hpp>

#include <cstdint>
#include <memory>

namespace controller {

class ProductCreator {
public:
  ProductCreator(std::uint64_t basketId) : _basketId{basketId} {};
  std::optional<model::Product> execute(std::shared_ptr<model::Model> model);

private:
  std::uint64_t _basketId;
}; // namespace controller

} // namespace controller