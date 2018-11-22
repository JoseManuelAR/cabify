#ifndef _SERVER_MODEL_BASKET_HPP_
#define _SERVER_MODEL_BASKET_HPP_

#include <cstdint>
#include <json.hpp>

#include <model/amount.hpp>
#include <model/product.hpp>

namespace model {

using BasketId = std::uint64_t;

class Basket {
public:
  Basket() : _id{++_currentId} {};
  Basket(Basket &&other) = default;

  BasketId id() const { return _id; }

  std::optional<Product> createProduct();
  Amount getAmount() { return Amount{}; }

  nlohmann::json toJson();

private:
  static BasketId _currentId;
  BasketId _id = 0;
  std::vector<Product> _products = {};
};

} // namespace model

#endif //_SERVER_MODEL_BASKET_HPP_