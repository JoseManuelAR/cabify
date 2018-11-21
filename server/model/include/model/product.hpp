#ifndef _SERVER_MODEL_PRODUCT_HPP_
#define _SERVER_MODEL_PRODUCT_HPP_

#include <cstdint>

namespace model {

using ProductId = std::uint64_t;

class Product {
public:
  Product() : _id{++_currentId} {};

  ProductId id() const { return _id; }

private:
  static ProductId _currentId;
  ProductId _id = 0;
};

class ProductHash {
public:
  std::size_t operator()(const Product &product) const { return product.id(); }
};

inline bool operator==(const Product &lhs, const Product &rhs) { return lhs.id() == rhs.id(); }

} // namespace model

#endif //_SERVER_MODEL_PRODUCT_HPP_