
add_executable(inline_member_functions inline_member_functions.cpp)
set_target_properties(inline_member_functions
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::inline-member-functions"
    COMMAND inline_member_functions)

add_test(NAME "methods::reference-qualifiers"
    COMMAND
    ${BASH_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/reference_qualifiers.sh)

add_executable(moveCtorTest move_ctor.cpp)
set_target_properties(moveCtorTest
    PROPERTIES
    CXX_STANDARD 11)
add_test(NAME "methods::move-ctor"
    COMMAND moveCtorTest)

add_executable(braceInitializerTest brace_initialize.cpp)
set_target_properties(braceInitializerTest
    PROPERTIES
    CXX_STANDARD 11)
add_test(NAME "methods::brace-init"
    COMMAND braceInitializerTest)

add_executable(explicitBoolConv explicitBoolConv.cpp)
set_target_properties(explicitBoolConv
    PROPERTIES
    CXX_STANDARD 11)
add_test(NAME "methods::explicit-boolean-conversion"
    COMMAND explicitBoolConv)
add_test(NAME "methods::explicit-boolean-conversion-sh"
    COMMAND
    ${BASH_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/explicitBoolConvTest.sh
    )

add_executable(boolean_operator operator_bool.cpp)
add_test(NAME "methods::boolean-operator"
    COMMAND boolean_operator)

add_executable(stream_operator operator_stream.cpp)
add_test(NAME "methods::stream-operator"
    COMMAND stream_operator)

add_tinytest_executable(virtual_dtor_or_protected_dtor
    virtual_dtor_or_protected_dtor.cpp)
set_target_properties(virtual_dtor_or_protected_dtor
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::virtual-dtor-or-protected-nonvirtual-dtor"
    COMMAND virtual_dtor_or_protected_dtor)

add_executable(conceptual_constness
    conceptual_constness.cpp)
set_target_properties(conceptual_constness
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::conceptual-constness"
    COMMAND conceptual_constness)

add_tinytest_executable(ctor_order ctor_order.cpp)
set_target_properties(ctor_order
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::constructor-execution-order"
    COMMAND ctor_order)

add_tinytest_executable(illegal_member_initialization
    illegal_member_initialization.cpp)
set_target_properties(illegal_member_initialization
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::illegal-member-initialization"
    COMMAND illegal_member_initialization)

add_executable(virtual_function_override_keyword virtual_function_override_keyword.cpp)
set_target_properties(virtual_function_override_keyword
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::virtual-function-override-keyword"
    COMMAND virtual_function_override_keyword)

add_executable(pure_virtual_with_default pure_virtual_with_default.cpp)
set_target_properties(pure_virtual_with_default
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::pure-virtual-with-default"
    COMMAND pure_virtual_with_default)

add_tinytest_executable(accessibility_and_visibility
    accessibility_and_visibility.cpp)
set_target_properties(accessibility_and_visibility
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::accessibility-and-visibility"
    COMMAND accessibility_and_visibility)