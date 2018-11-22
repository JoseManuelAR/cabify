#include <controller/amountgetter.hpp>
#include <iostream>
#include <thread>

namespace controller {

std::tuple<common::Error, std::optional<model::Amount>>
AmountGetter::execute(std::shared_ptr<model::Model> model) {
  return model->getAmount(_basketId);
}
} // namespace controller