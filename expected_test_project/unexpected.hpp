#pragma once
#include <tl/expected.hpp>

#include "current_function.hpp"
#include "error.hpp"

#define E_UNEXPECTED(ExceptionType, ErrorMessage) \
  ::tl::make_unexpected(::e::Error{               \
    ::e::type_identity<ExceptionType>{},          \
    #ExceptionType,                               \
    __FILE__,                                     \
    E_CURRENT_FUNCTION,                           \
    static_cast<std::uint64_t>(__LINE__),         \
    ErrorMessage})
