#include <common/error.hpp>
#include <model/model.hpp>

#include <cstdint>
#include <memory>
#include <string>
#include <tuple>

namespace controller {

class ProductCreator {
public:
  ProductCreator(std::uint64_t basketId, const std::string &code)
      : _basketId{basketId}, _code{code} {};
  std::tuple<common::Error, std::optional<model::Product>>
  execute(std::shared_ptr<model::Model> model);

private:
  std::uint64_t _basketId;
  std::string _code;
}; // namespace controller

} // namespace controller