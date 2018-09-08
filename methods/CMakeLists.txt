
add_executable(inline_member_functions inline_member_functions.cpp)
set_target_properties(inline_member_functions
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "methods::inline-member-functions"
    COMMAND inline_member_functions)

add_test(NAME "methods::reference-qualifiers"
    COMMAND
    ${BASH_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/reference_qualifiers.sh)