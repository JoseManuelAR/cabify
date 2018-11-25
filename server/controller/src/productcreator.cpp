#include <controller/productcreator.hpp>
#include <iostream>
#include <thread>

namespace controller
{

std::tuple<common::Error, std::optional<model::Product>>
ProductCreator::execute(std::shared_ptr<model::Model> model)
{
  return model->createProduct(_basketId, _code);
}
} // namespace controller