
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
    "classes::nested-and-local-classes"
    COMMAND
    nested_and_local_classes
)

add_executable(diamond_inheritance diamond_inheritance.cpp)
set_target_properties(diamond_inheritance
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "classes::diamond-inheritance"
    COMMAND diamond_inheritance)

add_executable(multi_inheritance multi_inheritance.cpp)
set_target_properties(multi_inheritance
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "classes::multiple-inheritance"
    COMMAND multi_inheritance)


add_tinytest_executable(demo_geometry_polymorphism
    demo_geometry_polymorphism.cpp)
set_target_properties(demo_geometry_polymorphism
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "classes::geometry-polymorphism"
    COMMAND demo_geometry_polymorphism)