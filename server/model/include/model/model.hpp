#ifndef _SERVER_MODEL_MODEL_HPP_
#define _SERVER_MODEL_MODEL_HPP_

#include <common/error.hpp>
#include <model/amount.hpp>
#include <model/basket.hpp>

#include <optional>

namespace model {

class Model {
public:
  virtual ~Model() = default;

  virtual void start() = 0;

  virtual Basket createBasket() = 0;
  virtual common::Error createProduct(BasketId basketId,
                                      const std::string &code) = 0;
  virtual std::tuple<
      common::Error,
      std::optional<std::unordered_map<std::string, std::uint64_t>>>
  getProducts(BasketId basketId) = 0;
};

} // namespace model

#endif //_SERVER_MODEL_MODEL_HPP_
