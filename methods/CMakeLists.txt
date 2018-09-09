
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