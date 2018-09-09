//
// Created by wein on 26/08/18.
//

// source
// https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container

#include <iostream>

#include <algorithm>
#include <deque>
#include <vector>

void RunTinyTests();

template<typename T>
void prt(const T& ctn) {
    auto it = ctn.begin(), end = ctn.end();
    while (it != end) {
        std::cout <<
        std::hex <<
        -(&(*it++) - &(*it)) <<
        ", ";
    }
    std::cout << std::endl;
}

void test_nothing() {
    std::deque<int> d(125, 0);
    std::vector<int> v(125, 0);
    std::cout << std::endl;
    prt(d);
    prt(v);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}