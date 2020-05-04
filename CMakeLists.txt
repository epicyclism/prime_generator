# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
project ("prime_generator")

set_property(GLOBAL PROPERTY CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(/permissive /Zc:preprocessor)

#include_directories("D:/projects/vcpkg/installed/x64-windows/include")
find_path(RANGE_INCLUDE_DIR range/v3/range.hpp)
include_directories(${RANGE_INCLUDE_DIR})


# Add source to this project's executable.
add_executable (prime_generator "prime_generator.cpp" )
target_compile_features(prime_generator PRIVATE cxx_std_20)
