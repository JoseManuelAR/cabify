#include <memory>

namespace model {
class Model;
}

namespace view {

class View {
public:
  virtual ~View();

  virtual void start(std::unique_ptr<model::Model> model) = 0;
};

} // namespace view
