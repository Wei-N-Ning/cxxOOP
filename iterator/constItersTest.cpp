//
// Created by wein on 6/1/18.
//
// source:
// EMC++ Item 13 P107
// Note C++11 does not provide std::cbegin and std::cend
// hence the template functions here

#include <cassert>

#include <algorithm>
#include <array>
#include <vector>

#if __cplusplus == 201103L
template<typename C>
auto cbegin(const C &container) -> decltype(std::begin(container)) {
    return std::begin(container);
}
template<typename C>
auto cend(const C &container) -> decltype(std::end(container)) {
    return std::end(container);
}
#elif __cplusplus > 201103L
using std::cbegin;
using std::cend;
#endif

template<typename C, typename V>
bool find(const C &container, const V &toSearchFor) {
    auto it = std::find(cbegin(container), cend(container), toSearchFor);
    return (it != cend(container));
};

template<typename C, typename V>
bool findAndInsert(C &container, const V &toSearchFor, const V &toInsert) {
    auto it = std::find(cbegin(container), cend(container), toSearchFor);
    if (it == cend(container)) {
        return false;
    }
    container.insert(it, toInsert);
    return true;
}

namespace CArray {

void runTests() {
    constexpr int sz = 45;
    int arr[sz];
    for (int i = sz; i--; arr[i] = i) ;
    assert(find(arr, 11));
    assert(! find(arr, 111));
}

}

namespace Vector {

void runTests() {
    std::vector<int> v{3, 1, 4, 5, 9, 2, 6};
    assert(! findAndInsert(v, 41, 101));
    assert(findAndInsert(v, 4, 101));
    assert(findAndInsert(v, 101, 202));
}

}

int main() {
    CArray::runTests();
    Vector::runTests();
    return 0;
}