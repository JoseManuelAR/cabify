#ifndef _SERVER_MODEL_STOCK_HPP_
#define _SERVER_MODEL_STOCK_HPP_

#include <common/error.hpp>

#include <json.hpp>

#include <string>
#include <unordered_map>

namespace model {

class Stock {
public:
  virtual ~Stock() = default;

  virtual common::Error add(const std::string &code, const std::string &name,
                            float price);
  virtual bool get(const std::string &code) {
    return (_items.find(code) != _items.end());
  }

  virtual std::optional<std::string> name(const std::string &code) {
    auto item = _items.find(code);
    if (item != _items.end()) {
      return item->second.name();
    }
    return std::nullopt;
  }

  virtual std::optional<float> price(const std::string &code) {
    auto item = _items.find(code);
    if (item != _items.end()) {
      return item->second.price();
    }
    return std::nullopt;
  }

private:
  class StockItem {
  public:
    StockItem(const std::string &code, const std::string &name, float price)
        : _code{code}, _name{name}, _price{price} {}

    nlohmann::json toJson() {
      nlohmann::json val = nlohmann::json::object();

      val["code"] = _code;
      val["name"] = _name;
      val["price"] = _price;
      return val;
    }

    const std::string &code() const { return _code; }
    const std::string &name() const { return _name; }
    float price() const { return _price; }

  private:
    std::string _code;
    std::string _name;
    float _price;
  };
  std::unordered_map<std::string, StockItem> _items;
};

} // namespace model

#endif //_SERVER_MODEL_MODEL_HPP_
