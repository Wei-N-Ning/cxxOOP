
#include <complex>
#include <cassert>

// source
// exceptional P138
//
// overload resolution happens before accessibility checking
// when the compiler has to resolve the call to a method, it does three 
// main things in order
// 1) Name look up
// 2) Overload resolution
// 3) Accessibility checking

void RunTinyTests();

// original implementation: P138
void test_function_resolution_order() {
    static char token = '\0';

    class Calc {
    public:
        double twice(double d) {
            token = 'd';
            return d * 2;
        };

    private:
        int twice(int i) {
            token = 'i';
            return i * 2;
        }

        // P137
        // even though this version of twice() is not accessible to
        // the caller, it is still visible and constitutes a source
        // dependency,
        // In particular, even though the caller can't possibly care
        // about complex, there still at minimum must be at least a
        // forward declaration of complex for this code to compile
        //
        // "A private member is visible to all code that sess the
        // class's definition. This means that its parameter types must
        // be declared even if they can never be needed in this
        // translation unit"
        std::complex<float> twice(std::complex<float> c) {
            token = 'c';
            return c * 2.0f;
        }
    };

    // can not compile:
    // summary of why: P138
    // what happens at compilation time:
    // 1) name look up Calc::twice()
    // 2) overload resolution: int Calc::twice(int)
    // 3) accessibility test **FAIL**
    // Calc().twice(21);

}

void test_ambiguity() {
    static char token = '\0';

    class Calc {
    public:
        double twice(double d) {
            token = 'd';
            return d * 2;
        };

    private:
        unsigned int twice(unsigned int i) {
            token = 'i';
            return i * 2;
        }

        std::complex<float> twice(std::complex<float> c) {
            token = 'c';
            return c * 2.0f;
        }
    };

    // P138
    // In this case we never get past the second step:
    // overload resolution fails to find a unique best match out of the
    // candidate list, because the actual parameter type (21) int could
    // be converted to either unsigned int or double and those two
    // conversions are considered equally good according to the language
    // rules.
    // because the two functions are equally good matches, the compiler
    // can not choose between them and the call is ambiguous
    // the compiler never even gets to the accessibility check
    // Calc().twice(21);
}

namespace ns_test_name_hiding {

int twice(int i) {
    return i * 2;
}

class String {};

class Calc {
private:
    // hides global symbol: int twice(int)
    String twice(String s) { return {}; };

public:
    void test() {
        // P139
        // we never get past the second step:
        // overload resolution fails to find any viable match out of the
        // candidate lsts (which now is only Calc::twice(String)),
        // because the actual parameter int(21) can not be converted to
        // String.
        // The compiler again never gets to the accessibility check;
        // int result = twice(21);
    }
};

// P138
// //////////// as soon as a scope is found that contains at least one
// entity with the given name, the search ends, even if that candidate
// turns out to be uncallable or inaccessible. Other potential matches
// in enclosing scopes will never be considered ////////////

} // namespace test_name_hiding

void test_name_hiding() {
    ns_test_name_hiding::Calc().test();
}

// P140
// use function pointer to bypass accessibility control
void test_grant_access_method_pointer() {
    static char token = '\0';

    class Calc {
    public:
        using Method = int(Calc::*)(int);

        double twice(double d) {
            token = 'd';
            return d * 2;
        };

        // NOTE
        // the function pointer is explicitly set to:
        // int Calc::twice(int)
        Method getMethod() {
            return &Calc::twice;
        }

    private:
        int twice(int i) {
            token = 'i';
            return i * 2;
        }

        float twice(float f) {
            token = 'f';
            return f * 2.0f;
        }
    };

    Calc c;
    Calc::Method method = c.getMethod();
    assert(token == '\0');
    assert(42 == (c.*method)(21));
    assert(token == 'i');

    // the function pointer is explicitly set to:
    // int Calc::twice(int)
    // there is no overload resolution happening!
    token = '\0';
    assert(42.0f == (c.*method)(21.0f));
    assert(token == 'i');
}

// P141
// exceptional book demos this technique twices
// see also cxxDebugGem project
// in short:
// any member template can be specialized for any type;
// specialize it on a type that you know nobody else will ever
// specialize it on (say a type in your own namespace / anonymous
// namespace)
// you have just written a member, and members have access to all parts
// of the class
namespace ns_test_grant_access_template_exploit {

static char token = '\0';

class Calc {
public:
    double twice(double d) {
        token = 'd';
        return d * 2;
    };

    template<class T>
    void f(const T& t) {
        ;
    }

private:
    int twice(int i) {
        token = 'i';
        return i * 2;
    }

    float twice(float f) {
        token = 'f';
        return f * 2.0f;
    }
};

struct Exploit {
    int param;
    int result;
};

template<>
void Calc::f(const Exploit& t) {
    const_cast<Exploit&>(t).result = twice(t.param);
}

void test() {
    Calc c;
    Exploit ep{21, 0};
    c.f(ep);
    assert(42 == ep.result);
}

} // ns_test_grant_access_template_exploit

void test_grant_access_template_exploit() {
    ns_test_grant_access_template_exploit::test();
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}