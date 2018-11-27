#ifndef CONTROLLER_DISCOUNT_HPP
#define CONTROLLER_DISCOUNT_HPP

#include <cstdint>

namespace controller {

class Discount {
public:
  ~Discount() = default;
  virtual void execute(float &total) = 0;
};

} // namespace controller

#endif // CONTROLLER_DISCOUNT_HPP