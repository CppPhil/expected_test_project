#include <ostream>

#include "exception.hpp"

namespace e {
std::ostream& operator<<(std::ostream& outputStream, const Exception& exception)
{
  return outputStream << "Exception type:\"" << exception.exceptionName() << "\"\n"
                      << "File    : " << exception.file() << '\n'
                      << "Function: " << exception.function() << '\n'
                      << "Line    : " << exception.line() << '\n'
                      << "Message : " << exception.what();
}

Exception::Exception(
    std::string_view exceptionName,
    std::string_view file,
    std::string_view function,
    std::uint64_t line,
    std::string_view message)
  : std::domain_error{message.data()}
  , m_exceptionName{exceptionName}
  , m_file{file}
  , m_function{function}
  , m_line{line}
{
}

std::unique_ptr<Exception> Exception::clone() const
{
  return std::make_unique<Exception>(*this);
}

std::string_view Exception::exceptionName() const noexcept
{
  return m_exceptionName;
}

std::string_view Exception::file() const noexcept
{
  return m_file;
}

std::string_view Exception::function() const noexcept
{
  return m_function;
}

std::uint64_t Exception::line() const noexcept
{
  return m_line;
}
} // namespace e
