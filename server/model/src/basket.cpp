#include <model/basket.hpp>

namespace model {

BasketId Basket::_currentId = 0;

nlohmann::json Basket::toJson() {
  nlohmann::json val = nlohmann::json::object();

  val["id"] = _id;
  return val;
}

std::optional<Product> Basket::createProduct() { return Product{}; }

} // namespace model