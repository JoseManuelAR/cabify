#include <model/model.hpp>

#include <cstdint>
#include <memory>

namespace controller {

class BasketCreator {
public:
  model::Basket execute(std::shared_ptr<model::Model> model);
};

} // namespace controller