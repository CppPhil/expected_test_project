# CMakeList.txt : CMake project for expected_test_project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (expected_test_project "main.cpp" )

target_link_libraries(
	expected_test_project
	PRIVATE
	tl::expected)
