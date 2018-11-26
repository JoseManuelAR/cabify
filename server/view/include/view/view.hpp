#include <memory>

namespace model {
class Stock;
class Model;
} // namespace model

namespace view {

class View {
public:
  virtual ~View();

  virtual void start(std::unique_ptr<model::Stock> stock, std::unique_ptr<model::Model> model) = 0;
};

} // namespace view
