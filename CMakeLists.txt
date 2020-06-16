cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc-9)
set(CMAKE_CXX_COMPILER g++-9)

project(C++Object-Oriented-Programming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(vendor/doctest)
enable_testing()
find_program(BASH_PROGRAM bash)
include(tinyCUnit/tinyCUnit.cmake)

add_subdirectory(classes)
add_subdirectory(container)
add_subdirectory(exceptions)
add_subdirectory(fields)
add_subdirectory(iterator)
add_subdirectory(methods)

