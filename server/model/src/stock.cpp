#include <model/stock.hpp>

namespace model {

common::Error Stock::add(const std::string &code, const std::string &name, float price) {
  if (not get(code)) {
    StockItem stockItem{code, name, price};
    _items.insert(std::make_pair<std::string, StockItem>(code.c_str(), std::move(stockItem)));
    return common::Error::Success;
  }
  return common::Error::StockExistsCode;
}

} // namespace model