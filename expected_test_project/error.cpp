#include <ostream>

#include "error.hpp"

namespace e {
std::ostream& operator<<(std::ostream& outputStream, const Error& error)
{
  return outputStream << "Error:\n" << *error.m_exception;
}

Error::Error(const this_type& other) : m_exception{other.m_exception->clone()}
{
}

Error::Error(this_type&& other) noexcept = default;

Error& Error::operator=(const this_type& other)
{
  m_exception = other.m_exception->clone();
  return *this;
}

Error& Error::operator=(this_type&& other) noexcept = default;

void Error::raise() const
{
  throw *m_exception;
}

std::string_view Error::exceptionName() const noexcept
{
  return m_exception->exceptionName();
}

std::string_view Error::file() const noexcept
{
  return m_exception->file();
}

std::string_view Error::function() const noexcept
{
  return m_exception->function();
}

std::uint64_t Error::line() const noexcept
{
  return m_exception->line();
}
} // namespace e
