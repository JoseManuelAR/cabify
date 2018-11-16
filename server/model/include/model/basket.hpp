#ifndef _SERVER_MODEL_BASKET_HPP_
#define _SERVER_MODEL_BASKET_HPP_

#include <cstdint>

namespace model {

using BasketId = std::uint64_t;

class Basket {
public:
private:
  static const BasketId _currentId;
  BasketId _id = 0;
};

} // namespace model

#endif //_SERVER_MODEL_BASKET_HPP_