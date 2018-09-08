
// source
// geek for geek: inline-functions-cpp
// it's a very good article

struct SUT {
    // declare the member function
    int getValue() const;
};

////////// in the source file ///////////
// add inline keyword to the definition
// (it is only a suggestion to the compiler)
inline int SUT::getValue() const {
    return 100;
}
/////////////////////////////////////////

int main() {
    if (SUT().getValue() == 100) {
        return 0;
    }
    return 1;
}
