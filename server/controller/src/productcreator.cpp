#include <controller/productcreator.hpp>
#include <iostream>
#include <thread>

namespace controller {

std::optional<model::Product> ProductCreator::execute(std::shared_ptr<model::Model> model) { return model->createProduct(_basketId); }
} // namespace controller