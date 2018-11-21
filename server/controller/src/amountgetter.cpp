#include <controller/amountgetter.hpp>
#include <iostream>
#include <thread>

namespace controller
{

model::Amount AmountGetter::execute(std::shared_ptr<model::Model> model)
{
    return model::Amount{};
}
} // namespace controller