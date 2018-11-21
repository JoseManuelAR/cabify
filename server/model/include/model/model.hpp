#ifndef _SERVER_MODEL_MODEL_HPP_
#define _SERVER_MODEL_MODEL_HPP_

#include <model/basket.hpp>
#include <model/product.hpp>
#include <model/amount.hpp>

#include <optional>

namespace model
{

class Model
{
public:
  virtual ~Model() = default;

  virtual void start() = 0;

  virtual Basket createBasket() = 0;
  virtual std::optional<Product> createProduct(BasketId basketId) = 0;
};

} // namespace model

#endif //_SERVER_MODEL_MODEL_HPP_
