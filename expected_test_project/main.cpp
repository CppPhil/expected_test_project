#include <cstdio>

#include <iostream>
#include <string_view>

#include <fmt/format.h>
#include <fmt/ostream.h>

#include "expected.hpp"
#include "math_exception.hpp"
#include "unexpected.hpp"

namespace e {
namespace {
Expected<int> divide(int a, int b)
{
  if (b == 0) {
    return E_UNEXPECTED(MathException, "Can't divide by 0!");
  }

  const int result{a / b};
  return result;
}

template<typename ToRead>
ToRead read(std::istream& inputStream, std::string_view prompt)
{
  ToRead toRead{};

  while (std::fwrite(prompt.data(), sizeof(char), prompt.size(), stdout),
         !(inputStream >> toRead)) {
    inputStream.clear();
    inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    fmt::print(stderr, "That didn't work. Try again.\n");
  }

  return toRead;
}
} // anonymous namespace
} // namespace e

int main()
{
  const e::Expected<int> expected1{e::divide(1, 0)};

  if (!expected1.has_value()) {
    const e::Error& error{expected1.error()};
    fmt::print(stderr, "{}\n", error);
  }
  else {
    fmt::print(stderr, "expected1 had a value!\n");
  }

  const e::Expected<int> expected2{e::divide(10, 2)};

  // operator-> also works.
  if (expected2.has_value()) {
    fmt::print("*expected2: {}\n", *expected2);
  }
  else {
    fmt::print(stderr, "expected2 had no value!\n");
  }

  const int value1{e::read<int>(std::cin, "Please enter the first number: ")};
  const int value2{e::read<int>(std::cin, "Please enter the second number: ")};
  const e::Expected<int> result{e::divide(value1, value2)};

  // monadic APIs
  // and_then: for operations that return an expected.
  const int doubleTheResult{
    result.map([](int calculationResult) { return calculationResult * 2; })
      .value()};
  fmt::print("result: {}\n", doubleTheResult);

  try {
    result.map_error([](const e::Error& error) { error.raise(); });
  }
  catch (const e::Exception& exception) {
    fmt::print(stderr, "{}\n", exception);
  }
  // or_else: Calls the given callable if there is no value.

  fmt::print("value_or: {}\n", result.value_or(-1));
}
