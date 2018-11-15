#include <cstdint>
#include <memory>
#include <string>
#include <view/view.hpp>

namespace view {

class Rest : public View {
public:
  Rest(std::uint16_t port);
  Rest(const std::string &host, std::uint16_t port);
  ~Rest();

  void start(std::unique_ptr<model::Model> model) override;

private:
  class RestImpl;
  std::unique_ptr<RestImpl> _impl;
};

} // namespace view