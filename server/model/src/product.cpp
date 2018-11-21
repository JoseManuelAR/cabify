#include <model/product.hpp>

namespace model {

ProductId Product::_currentId = 0;

nlohmann::json Product::toJson() {
  nlohmann::json val = nlohmann::json::object();

  val["id"] = _id;
  return val;
}
} // namespace model