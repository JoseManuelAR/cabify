#include <memory>
#include <model/memory.hpp>
#include <view/rest.hpp>

int main(int argc, char **argv) {
  std::unique_ptr<model::Model> model = std::make_unique<model::Memory>();
  std::unique_ptr<view::View> view = std::make_unique<view::Rest>(9000);

  view->start(std::move(model));
  return 0;
}