
// source
// more exception P114
//
// a) the ctor returns normally by reaching its each or a return
// statement, and the object exists
// b) the ctor exists by emitting an exception and the object not only
// does not now exist, but it never existed as an object

#include <memory>
#include <cassert>

void RunTinyTests();

void test_constructor_exception_consequence() {
    static int danger_dtor_called = 0;

    struct Danger {
        explicit Danger(int arg) {
            if (arg == 101) {
                throw 101;
            }
        }

        ~Danger() {
            danger_dtor_called++;
        }
    };

    Danger* (* factory)(int arg) = [](int arg) -> Danger* {
        try {
            return new Danger(arg);
        }
        catch (const int& exc) {
            return nullptr;
        }
    };

    // object danger existed
    {
        std::shared_ptr<Danger> d1(factory(10));
    }
    assert(1 == danger_dtor_called);

    danger_dtor_called--;

    // object danger never existed
    {
        std::shared_ptr<Danger> d2(factory(101));
    }
    assert(0 == danger_dtor_called);

}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
