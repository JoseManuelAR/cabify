#include <controller/discount2x1.hpp>
#include <memory>
#include <model/memory.hpp>
#include <model/stock.hpp>
#include <view/rest.hpp>

int main(int argc, char **argv) {
  std::unique_ptr<model::Stock> stock = std::make_unique<model::Stock>();
  std::unique_ptr<model::Model> model = std::make_unique<model::Memory>();
  std::unique_ptr<view::View> view = std::make_unique<view::Rest>(9000);
  std::vector<std::unique_ptr<controller::Discount>> discounts;

  stock->add("VOUCHER", "Cabify Voucher", 5.00);
  stock->add("TSHIRT", "Cabify T-Shirt", 20.00);
  stock->add("MUG", "Cabify Coffee Mug", 7.50);

  discounts.emplace_back(std::make_unique<controller::Discount2x1>());

  view->start(std::move(stock), std::move(model), std::move(discounts));
  return 0;
}