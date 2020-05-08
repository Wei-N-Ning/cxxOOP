
// source: mastering c++ programming L2086
// c++20 introduces the spaceship operator, which allows us to skip the 
// definition of comparison operators
// operator<=>()
// also known as the three-way comparison operator, requests the compiler
// to generate relational operators

// see also:
// https://en.cppreference.com/w/cpp/language/default_comparisons

// NOTE: can not compile on clang-10
#include <compare>

class Money {
public:
    auto operator<=>(const Money&) const = default;
private:
    int v{0};
};

int main() {
    Money m1{}, m2{};
    if (m1 == m2) {
        return 0;
    } else {
        return 1;
    }
}
