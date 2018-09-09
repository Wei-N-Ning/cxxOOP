//
// Created by wein on 5/27/18.
//
// source:
// EMC++ Item 11 P74

#include <sstream>

// this is not related to deleted member functions item
// this example is to document that in C++98, basic_ios
// and its child classes can be implicitly casted to
// bool
// this is problematic and is disallowed in C++11 onward,
// therefore the proper way is to call the bool operator
// explicitly
// see:
// http://en.cppreference.com/w/cpp/io/basic_ios/operator_bool
// the bool operator is explicit
namespace ImplicitBool {

#ifdef CXX_STANDARD_98
bool foo() {
    return std::stringstream();
}
#else

bool foo() {
    return bool(std::stringstream());
}

#endif

void runTests() {
    bool flag = foo();
    if (flag) {
        ;
    }
}

}

int main() {
    ImplicitBool::runTests();
    return 0;
}