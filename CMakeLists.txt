# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
set_property(GLOBAL PROPERTY CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("D:/projects/vcpkg/installed/x64-windows/include")
project ("prime_generator")

# Add source to this project's executable.
add_executable (prime_generator "prime_generator.cpp" )
