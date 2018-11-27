#include <controller/amountgetter.hpp>
#include <iostream>
#include <thread>

namespace controller {

std::tuple<common::Error, std::optional<model::Amount>> AmountGetter::execute(std::shared_ptr<model::Stock> stock, std::shared_ptr<model::Model> model) {
  auto products = model->getProducts(_basketId);
  if (std::get<0>(products) == common::Error::Success) {
    float total = 0;
    auto listOfProducts = std::get<1>(products);
    if (listOfProducts) {
      for (auto p : listOfProducts.value()) {
        total += (p.second * stock->price(p.first).value());
      }
    }
    for (auto discount : _discounts) {
      discount->execute(total);
    }
    return std::make_tuple(std::get<0>(products), model::Amount{total});
  }
  return std::make_tuple(std::get<0>(products), std::nullopt);
}

}  // namespace controller