#ifndef _SERVER_MODEL_AMOUNT_HPP_
#define _SERVER_MODEL_AMOUNT_HPP_

#include <cstdint>
#include <json.hpp>

#include <model/product.hpp>

namespace model {

class Amount {
public:
  explicit Amount(float total) : _total{total} {}

  nlohmann::json toJson();

private:
  float _total;
};

} // namespace model

#endif //_SERVER_MODEL_AMOUNT_HPP_