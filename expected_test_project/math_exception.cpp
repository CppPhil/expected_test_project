#include "math_exception.hpp"

namespace e {
std::unique_ptr<Exception> MathException::clone() const
{
  return std::make_unique<MathException>(*this);
}
} // namespace e
