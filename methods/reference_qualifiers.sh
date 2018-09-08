#!/usr/bin/env bash

# source:
# EMC++ Item 12
# compute() & applies only when the sut is an lvalue
# compute() && applies only when the sut is an rvalue

setUp() {
    rm -rf /tmp/sut
    mkdir /tmp/sut
}

buildProgram1() {
    cat > /tmp/sut/_.cpp <<"EOF"
struct C {
    int compute(int size) &;
    int compute(int size) &&;
};
int C::compute(int size) & {
    return 1;
}
int C::compute(int size) && {
    return 10;
}
int main() {
    C c;
    if (c.compute(0) == 1 && C().compute(0) == 10) {
        return 0;
    }
    return 1;
}
EOF
}

cxxCompileProgram1() {
    g++ -g -std=c++14 -Wall -Werror \
/tmp/sut/_.cpp \
-o /tmp/sut/_
}

runProgram1() {
    /tmp/sut/_
}

buildProgram2() {
    cat > /tmp/sut/_.cpp <<"EOF"
#include <iostream>
struct POD {
    void work() & {
        std::cout << "lvalue is working" << std::endl;
    }
    void work() && {
        std::cout << "rvalue is working" << std::endl;
    }
};
int main() {
    POD pod;
    pod.work();
    POD().work();
    pod.work();
    return 0;
}
EOF
}

cxxCompileProgram2() {
    g++ -g -std=c++14 -Wall -Werror \
/tmp/sut/_.cpp \
-o /tmp/sut/_
}

runProgram2() {
    /tmp/sut/_
}

setUp
buildProgram1
cxxCompileProgram1
runProgram1

buildProgram2
cxxCompileProgram2
runProgram2
