#include <controller/checkoutcreator.hpp>
#include <iostream>
#include <model/model.hpp>
#include <thread>

namespace controller {

std::uint64_t CheckoutCreator::execute(std::shared_ptr<model::Model> model) {
  std::cout << std::this_thread::get_id() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(5));
  return model->createCheckout();
}
} // namespace controller