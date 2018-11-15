
namespace model {

class Model {
public:
  virtual ~Model() = default;

  virtual void start() = 0;

  virtual std::uint64_t createCheckout() = 0;
};

} // namespace model
