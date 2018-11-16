#ifndef _SERVER_MODEL_MEMORY_HPP_
#define _SERVER_MODEL_MEMORY_HPP_

#include <memory>
#include <model/model.hpp>

namespace model {

class Memory : public Model {
public:
  Memory();
  ~Memory();

  void start() override;

  BasketId createBasket() override;

private:
  class MemoryImpl;
  std::unique_ptr<MemoryImpl> _impl;
};

} // namespace model

#endif //_SERVER_MODEL_MEMORY_HPP_