//
// Created by wein on 9/09/18.
//

// source
// exceptional P124

class Base {
public:
    int value() {
        return m_base;
    }

private:
    int m_base = 101;
};

class Derived : public Base {
public:
    // illegal
    // value() is executed before the base subobject is constructed
    // recall that one should not call non-static member functions,
    // virtual member functions in the initialization list
    // Derived() : m_derived(value()) {}

    // ok
    Derived() : m_derived(202) {}

private:
    int m_derived;
};

void test_demo_initialization_violation() {
    Derived d;
}

void RunTinyTests();

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
