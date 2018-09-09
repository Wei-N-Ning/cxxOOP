
add_tinytest_executable(c_array_iter c_array_iter.cpp)
set_target_properties(c_array_iter
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "iterator::c-array-iter"
    COMMAND c_array_iter)

add_executable(constIteratorTest constItersTest.cpp)
set_target_properties(constIteratorTest
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "iterator::const-iter"
    COMMAND constIteratorTest)
add_test(NAME "iterator::const-iter-sh"
    COMMAND
    ${BASH_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/constIterTest.sh)

