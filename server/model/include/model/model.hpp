#ifndef _SERVER_MODEL_MODEL_HPP_
#define _SERVER_MODEL_MODEL_HPP_

#include <model/basket.hpp>

namespace model {

class Model {
public:
  virtual ~Model() = default;

  virtual void start() = 0;

  virtual BasketId createBasket() = 0;
};

} // namespace model

#endif //_SERVER_MODEL_MODEL_HPP_
