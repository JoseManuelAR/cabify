#include <model/model.hpp>
#include <model/stock.hpp>

#include <cstdint>
#include <memory>

namespace controller {

class AmountGetter {
public:
  AmountGetter(std::uint64_t basketId) : _basketId{basketId} {};
  std::tuple<common::Error, std::optional<model::Amount>>
  execute(std::shared_ptr<model::Stock> stock,
          std::shared_ptr<model::Model> model);

private:
  std::uint64_t _basketId;
};

} // namespace controller