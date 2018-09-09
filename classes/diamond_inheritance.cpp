//
// Created by wein on 3/09/18.
//

#include <cstdio>
#include <cassert>

// source
// more exception Item 24, why multiple inheritance
// P149
//
// the question at issue is:
// does the programmer want D to have one B base subobject or two?
//
//  - if the answer is one then B should be a virtual base class, and
// (the shape of inheritance) becomes the dreaded diamond of death;
//
//  - if the answer is two then B should be a normal (nonvirtual) base
// class

// Guideline:
// avoid multiple inheritance from more than one non-protocol class;
// a protocol class means an abstract base class, or ABC, composed
// entirely or pure virtual functions with no data

// Java-style (interface) inheritance
//
// https://www.geeksforgeeks.org/java-and-multiple-inheritance/
//
// Java 8 supports default methods where interfaces can provide
// default implementation of methods. And a class can implement two or
// more interfaces. In case both the implemented interfaces contain
// default methods with same method signature, the implementing class
// should explicitly specify which default method is to be used or it
// should override the default method.

// P151
// "In practice, I've found that knowing now to use MI to combine
// vendor libraries is an essential technique that belongs in every
// C++ programmer's toolchest. Whether you end up using it frequently
// or not, you should definitely know about it and understand it"

void non_virtual_inheritance() {

    struct B {
        int operator()() {
            return value;
        }

        int value = 0x1;
    };

    struct C1 : public B {
        int operator()() {
            return value;
        }

        int* base() {
            return &(B::value);
        }

        int value = 0x11;
    };

    struct C2 : public B {
        int operator()() {
            return value;
        }

        int* base() {
            return &(B::value);
        }

        int value = 0x12;
    };

    class D : public C1, C2 {
    public:
        int operator() () {
            assert(0x11 == C1::operator()());
            assert(0x12 == C2::operator()());
            assert(0x11 == C1::value);
            assert(0x12 == C2::value);

            // there are two B subobjects therefore the addresses
            // to the "value" data member of each B subobject are
            // different
            printf("%p\n%p\n", C1::base(), C2::base());

            return value;
        }

        int value = 0x101;
    };

    D d;
    assert(0x101 == d());
}


int main() {
    non_virtual_inheritance();
    return 0;
}