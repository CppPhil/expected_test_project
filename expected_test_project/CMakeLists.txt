# CMakeList.txt : CMake project for expected_test_project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (expected_test_project "main.cpp"  "current_function.hpp" "exception.hpp" "exception.cpp" "error.hpp" "type_identity.hpp" "error.cpp" "math_exception.hpp" "math_exception.cpp" "expected.hpp" "unexpected.hpp")

target_link_libraries(
	expected_test_project
	PRIVATE
	tl::expected
	fmt::fmt)
