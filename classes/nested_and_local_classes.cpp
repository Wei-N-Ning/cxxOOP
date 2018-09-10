//
// Created by wein on 4/09/18.
//

// more exception Item 33, P197
// a nested class is a class enclosed within the scope of
// another class
// nested classes are useful for organizing code and controlling
// access and dependencies
// recall vector::_M_impl

// P198
// a local class is a class defined within the scope of a function
// can be a useful tool for managing code dependencies - an internal
// implementation detail that should never be advertised to other
// code

#include <vector>

void template_using_local_class() {
    int a = 0;

    class SUT {
    public:
        int operator() () {
            ///////////// IMPORTANT //////////////
            // P200 the local class object does not have access to
            // the enclosing function's variables
            // return a + 1;
            return 0;
        }
    };
    

    ///////////// on bsd (Mac OS) this causes a warning /////////////
    // not recommended
    // std::vector<SUT> s;
}

int main() {
    template_using_local_class();
    return 0;
}
