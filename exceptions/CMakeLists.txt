
add_tinytest_executable(ctor_exception ctor_exception.cpp)
set_target_properties(ctor_exception
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "exceptions::constructor-exception-consequence"
    COMMAND ctor_exception)