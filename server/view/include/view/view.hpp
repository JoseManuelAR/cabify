#include <controller/discount.hpp>
#include <memory>
#include <vector>

namespace model {
class Stock;
class Model;
} // namespace model

namespace view {

class View {
public:
  virtual ~View();

  virtual void
  start(std::unique_ptr<model::Stock> stock,
        std::unique_ptr<model::Model> model,
        std::vector<std::unique_ptr<controller::Discount>> discounts) = 0;
};

} // namespace view
