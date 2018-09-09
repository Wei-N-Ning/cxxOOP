
// exceptional P52
// ptr into array is iterator but not the other way around

#include <numeric>
#include <algorithm>
#include <iterator>
#include <cassert>

void RunTinyTests();

void test_range_based_for() {
    int arr[16];
    for (auto& elem : arr) {
        elem = 1;
    }
    assert(arr[15] == 1);
}

void test_mutable_ptr() {
    int arr[16];
    for (auto it = std::begin(arr); it != std::end(arr); ++it) {
        *it = 1;
    }
    assert(arr[15] == 1);
}

void test_mutable_ptr_algorithm() {
    int arr[16];
    std::generate(std::begin(arr), std::end(arr), []()->int{return 1;});
    assert(arr[15] == 1);
}

void test_const_ptr_algorithm() {
    int arr[4] = {1, 3, 3, 7};
    int dest[4];
    const int* begin = std::begin(arr);
    const int* end = std::end(arr);
    std::transform(begin, end, std::begin(dest), [](const int& v)->int{return v+1;});
    assert(2 == dest[0]);
    assert(8 == dest[3]);
}


int main() {
    RunTinyTests();
    return 0;
}
