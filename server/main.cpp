#include <memory>
#include <model/memory.hpp>
#include <view/rest.hpp>

int main(int argc, char **argv) {
  std::unique_ptr<model::Model> model = std::make_unique<model::Memory>();
  std::unique_ptr<view::View> view = std::make_unique<view::Rest>(9000);

  model->addStock("VOUCHER", "Cabify Voucher", 5.00);
  model->addStock("TSHIRT", "Cabify T-Shirt", 20.00);
  model->addStock("MUG", "Cabify Coffee Mug", 7.50);

  view->start(std::move(model));
  return 0;
}