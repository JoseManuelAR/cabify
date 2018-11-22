#include <model/amount.hpp>

namespace model {

nlohmann::json Amount::toJson() {
  nlohmann::json val = nlohmann::json::object();

  val["value"] = 69.56;
  return val;
}

} // namespace model