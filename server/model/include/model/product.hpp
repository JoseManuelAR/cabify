#ifndef _SERVER_MODEL_PRODUCT_HPP_
#define _SERVER_MODEL_PRODUCT_HPP_

#include <cstdint>
#include <json.hpp>

namespace model {

using ProductId = std::uint64_t;

class Product {
public:
  Product(const std::string &code, const std::string &name, float price)
      : _code{code}, _name{name}, _price{price} {}

  nlohmann::json toJson() {
    nlohmann::json val = nlohmann::json::object();

    val["code"] = _code;
    val["name"] = _name;
    val["price"] = _price;
    return val;
  }

private:
  std::string _code;
  std::string _name;
  float _price;
};

} // namespace model

#endif //_SERVER_MODEL_PRODUCT_HPP_