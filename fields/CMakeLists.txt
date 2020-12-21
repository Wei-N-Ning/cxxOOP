add_executable(data_member_is_ref
    data_member_is_ref.cpp)
set_property(TARGET data_member_is_ref
    PROPERTY CXX_STANDARD 14)
add_test(NAME "classes::data-member-is-ref"
    COMMAND data_member_is_ref)

add_executable(field_static_inline_variables static_inline_variables.cpp)
target_link_libraries(field_static_inline_variables PRIVATE doctest)
add_test(NAME "fields::static_inline_variables" COMMAND field_static_inline_variables)

add_executable(field_initialize_aggregates intialize_aggregates.cpp)
target_link_libraries(field_initialize_aggregates PRIVATE doctest)
add_test(NAME "fields::initialize_aggregates" COMMAND field_initialize_aggregates)
