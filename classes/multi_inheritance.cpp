//
// Created by wein on 3/09/18.
//

// source more exception Item 25
// P151
// if you couldn't use multiple inheritance, how could you emulate it?
// my own answer is: use composition and delegation, bridge, proxy, wrapper....

#include <string>
#include <cassert>

void emulate_multiple_inheritance() {
    class A {
    public:
        virtual ~A() = default;
        std::string name() {
            return doName();
        }

    private:
        virtual std::string doName() {
            return "A";
        }
    };

    // what happens: class B1 : virtual public A
    // https://en.wikipedia.org/wiki/Virtual_inheritance
    // Virtual inheritance is a C++ technique that ensures only one
    // copy of a base class's member variables are inherited by
    // grandchild derived classes.
    class B1 : virtual public A {
        std::string doName() override {
            return "B1";
        }
    };

    class B2 : virtual public A {
        std::string doName() override {
            return "B2";
        }
    };

    // note: if D does not override public member
    // function doName(), it won't compile:
    // D has more than one final-overrides
    class D : public B1, public B2 {
        std::string doName() override { return "D"; }
    };

    assert(D().name() == std::string("D"));


}

int main() {
    emulate_multiple_inheritance();
    return 0;
}
