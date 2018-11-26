#include <model/amount.hpp>

namespace model {

nlohmann::json Amount::toJson() {
  nlohmann::json val = nlohmann::json::object();

  val["total"] = _total;
  return val;
}

} // namespace model