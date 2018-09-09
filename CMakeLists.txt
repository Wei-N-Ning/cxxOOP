cmake_minimum_required(VERSION 3.8)
project(C++Object-Oriented-Programming)

enable_testing()
find_program(BASH_PROGRAM bash)
include(tinyCUnit/tinyCUnit.cmake)

add_subdirectory(classes)
add_subdirectory(container)
add_subdirectory(iterator)
add_subdirectory(methods)

