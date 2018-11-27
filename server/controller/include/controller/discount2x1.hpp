#include <controller/discount.hpp>

namespace controller {

class Discount2x1 : public Discount {
public:
  void execute(float &total) override;
};

} // namespace controller