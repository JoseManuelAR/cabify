#include <controller/amountgetter.hpp>
#include <iostream>
#include <thread>

namespace controller {

std::tuple<common::Error, std::optional<model::Amount>> AmountGetter::execute(std::shared_ptr<model::Model> model) {
  auto products = model->getProducts(_basketId);
  if (std::get<0>(products) == common::Error::Success) {
    model::Amount amount;
    auto listOfProducts = std::get<1>(products);
    if (listOfProducts) {
      for (auto p : listOfProducts.value()) {
        std::cout << p.first << "," << p.second << std::endl;
      }
    }
    return std::make_tuple(std::get<0>(products), amount);
  }
  return std::make_tuple(std::get<0>(products), std::nullopt);
}

}  // namespace controller