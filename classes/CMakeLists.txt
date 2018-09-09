
add_executable(enum_class enum_class.cc)
set_target_properties(enum_class
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "classes::enum-class"
    COMMAND enum_class)

add_executable(nested_and_local_classes
    nested_and_local_classes.cpp)
set_target_properties(nested_and_local_classes
    PROPERTIES
    CXX_STANDATD 98)
add_test(
    NAME
    "class-design::nested-and-local-classes"
    COMMAND
    nested_and_local_classes
)