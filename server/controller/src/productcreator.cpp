#include <controller/productcreator.hpp>
#include <iostream>
#include <thread>

namespace controller {

std::tuple<common::Error, std::optional<model::Product>>
ProductCreator::execute(std::shared_ptr<model::Stock> stock,
                        std::shared_ptr<model::Model> model) {
  if (stock->get(_code)) {
    auto error = model->createProduct(_basketId, _code);
    if (error == common::Error::Success) {
      return std::make_tuple(common::Error::Success,
                             model::Product{_code, stock->name(_code).value(),
                                            stock->price(_code).value()});
    }
    return std::make_tuple(error, std::nullopt);
  }
  return std::make_tuple(common::Error::ProductNotFound, std::nullopt);
}
} // namespace controller