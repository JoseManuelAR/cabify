#include <model/model.hpp>

#include <cstdint>
#include <memory>

namespace controller
{

class AmountGetter
{
  public:
    model::Amount execute(std::shared_ptr<model::Model> model);
};

} // namespace controller