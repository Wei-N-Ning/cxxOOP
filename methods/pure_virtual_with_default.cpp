//
// Created by wein on 3/09/18.
//

#include <cassert>

// more exception Item 27
// P162:
// force conscious acceptance of default behavior
//  - the base class is abstract
//  - a derived class does not choose to override a
//    a normal virtual function, it just inherits the
//    base version's behavior by default
//  - (P163) it is often useful to provide partial behavior
//    to a derived class which the derived class must still
//    complete; the idea is that the derived class executes
//    the base class's implementation as part of its own

// in the GOF book, the state pattern demonstrates
// one example of how this technique can be put
// to good use

namespace abstract_with_default_behavior {

class Base {
public:
    virtual int compute() = 0;
    virtual int repeat() = 0;
};

int Base::compute() {
    return 0x3;
}

// to demonstrate case 3
class Worker : virtual public Base {
public:
    int compute() override {
        return 0x8;
    }

    int repeat() override {

        // if the derived class wants the default,
        // it has to say so
        return 0xA * (1 + Base::compute());
    }
};

void test() {
    assert(40 == Worker().repeat());
}

} // namespace abstract_with_default_behavior

int main() {
    abstract_with_default_behavior::test();
    return 0;
}
