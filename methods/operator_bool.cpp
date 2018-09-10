
#include <cassert>

struct A {
    A(int v); 
    operator bool() {
        return value > 0;
    }
    int value;
};

A::A(int v)
    : value(v) {
}

int main() {
    assert(! A(-1));
    assert(A(1));
    return 0;
}
