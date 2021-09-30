#pragma once
#include <tl/expected.hpp>

#include "error.hpp"

namespace e {
template <typename Type>
using Expected = tl::expected<Type, Error>;
} // namespace e
