
add_executable(enum_class enum_class.cc)
set_target_properties(enum_class
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "classes::enum-class"
    COMMAND enum_class)