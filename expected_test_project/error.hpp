#pragma once
#include <cstdint>

#include <iosfwd>
#include <memory>
#include <string_view>

#include "exception.hpp"
#include "type_identity.hpp"

namespace e {
class Error {
public:
  using this_type = Error;

  friend std::ostream& operator<<(
    std::ostream& outputStream,
    const Error&  error);

  template<typename ExceptionType>
  Error(
    [[maybe_unused]] type_identity<ExceptionType> typeIdentity,
    std::string_view                              exceptionName,
    std::string_view                              file,
    std::string_view                              function,
    std::uint64_t                                 line,
    std::string_view                              message)
    : m_exception{std::make_unique<ExceptionType>(
      exceptionName,
      file,
      function,
      line,
      message)}
  {
  }

  Error(const this_type& other);

  Error(this_type&& other) noexcept;

  this_type& operator=(const this_type& other);

  this_type& operator=(this_type&& other) noexcept;

  [[noreturn]] void raise() const;

  std::string_view exceptionName() const noexcept;

  std::string_view file() const noexcept;

  std::string_view function() const noexcept;

  std::uint64_t line() const noexcept;

private:
  std::unique_ptr<Exception> m_exception;
};
} // namespace e
