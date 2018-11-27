#include <controller/discount.hpp>
#include <model/model.hpp>
#include <model/stock.hpp>

#include <cstdint>
#include <memory>

namespace controller {

class AmountGetter {
 public:
  AmountGetter(std::uint64_t basketId, std::vector<std::unique_ptr<controller::Discount>> &discounts) : _basketId{basketId}, _discounts{discounts} {};
  std::tuple<common::Error, std::optional<model::Amount>> execute(std::shared_ptr<model::Stock> stock, std::shared_ptr<model::Model> model);

 private:
  std::uint64_t _basketId;
  std::vector<std::unique_ptr<controller::Discount>> &_discounts;
};

}  // namespace controller