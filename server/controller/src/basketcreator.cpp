#include <controller/basketcreator.hpp>
#include <iostream>
#include <thread>

namespace controller {

model::Basket BasketCreator::execute(std::shared_ptr<model::Model> model) { return model->createBasket(); }
} // namespace controller