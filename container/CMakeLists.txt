
add_tinytest_executable(test_customHash
    test_customHash.cpp)
set_target_properties(test_customHash
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "container::custom-hash"
    COMMAND test_customHash)

add_executable(test_sorting
    test_sorting.cpp)
set_property(TARGET test_sorting
    PROPERTY CXX_STANDARD 11)
add_test(NAME "container::sorting"
    COMMAND test_sorting)

add_executable(test_stringInMap
    test_stringInMap.cpp)
set_property(TARGET test_stringInMap
    PROPERTY CXX_STANDARD 98)
add_test(NAME "container::string-in-map"
    COMMAND test_stringInMap)

add_executable(test_containerOfSmartPtrs
    test_containerOfSmartPtrs.cpp)
set_property(TARGET test_containerOfSmartPtrs
    PROPERTY CXX_STANDARD 14)
add_test(NAME "container::vector-of-smartptrs"
    COMMAND test_containerOfSmartPtrs)

add_executable(dequeStudy vector_vs_deque_pp.cpp)
set_target_properties(dequeStudy
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "container::deque-study"
    COMMAND dequeStudy)

add_tinytest_executable(bitArrayTest bit_container_test.cpp)
set_target_properties(bitArrayTest
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME
    "container::bit-array"
    COMMAND
    bitArrayTest)

add_tinytest_executable(stdDequeTest std_deque.cpp)
set_target_properties(stdDequeTest
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME
    "container::deque-test-and-comparison"
    COMMAND
    stdDequeTest)

add_tinytest_executable(associative_containers
    associative_containers.cpp)
set_target_properties(associative_containers
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "container::associative-container-modification"
    COMMAND associative_containers)

add_executable(vector_as_carray vector_as_carray.cpp)
set_target_properties(vector_as_carray
    PROPERTIES
    CXX_STANDARD 14)
add_test(NAME "container::use-vector-as-c-array"
    COMMAND vector_as_carray)
