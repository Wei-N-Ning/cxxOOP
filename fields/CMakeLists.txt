add_executable(data_member_is_ref
    data_member_is_ref.cpp)
set_property(TARGET data_member_is_ref
    PROPERTY CXX_STANDARD 14)
add_test(NAME "classes::data-member-is-ref"
    COMMAND data_member_is_ref)