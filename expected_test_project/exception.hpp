#pragma once
#include <cstdint>

#include <iosfwd>
#include <memory>
#include <stdexcept>
#include <string_view>

namespace e {
class Exception : public std::domain_error {
public:
  friend std::ostream& operator<<(
    std::ostream& outputStream,
    const Exception& exception);

  Exception(
    std::string_view exceptionName,
    std::string_view file,
    std::string_view function,
    std::uint64_t line,
    std::string_view message);

  virtual std::unique_ptr<Exception> clone() const;

  std::string_view exceptionName() const noexcept;

  std::string_view file() const noexcept;

  std::string_view function() const noexcept;

  std::uint64_t line() const noexcept;

private:
  std::string_view m_exceptionName;
  std::string_view m_file;
  std::string_view m_function;
  std::uint64_t m_line;
};
} // namespace e
