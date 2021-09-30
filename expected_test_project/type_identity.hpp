#pragma once

namespace e {
template <typename Type>
struct type_identity {
  using type = Type;
};

template <typename Type>
using type_identity_t = typename type_identity<Type>::type;
} // namespace e
