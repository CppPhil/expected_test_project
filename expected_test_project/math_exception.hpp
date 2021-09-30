#pragma once
#include "exception.hpp"

namespace e {
class MathException : public Exception {
public:
  using Exception::Exception;

  std::unique_ptr<Exception> clone() const override;
};
} // namespace e
