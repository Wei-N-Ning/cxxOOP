//
// Created by wein on 9/09/18.
//

// P160
// a base class destructor should be either public and virtual, or
// protected and nonvirtual

// P161
// once execution reaches the body of a base class dtor, any derived
// object parts have already been destroyed and no longer exist
// if the base dtor body were to call a virtual function, the virtual
// dispatch would reach no further down the inheritance hierarchy than
// base itself

// std::unary_function, std::binary_function are intended to be
// instantiated as base classes and yet do not provide virtual dtor
// because they are not intended to be used for polymorphic deletion

#include <iterator>
#include <algorithm>
#include <numeric>
#include <cassert>

void RunTinyTests();

void test_mixin_class() {

    static int mixin_class_dtor_called = 0;

    ////////////////////////////////////
    // not used for polymorphic deletion
    // recall std::unary_function
    struct Mixin {
        using CommonSubType = int;

        void commonProcess_construct(int arg) {
            m_commonData = new int[m_commonDataSize];
            std::generate(
                m_commonData,
                m_commonData + m_commonDataSize,
                [&]() -> int { return arg; }
            );
        }

        void commonProcess_destruct() {
            delete[] m_commonData;
            m_commonData = nullptr;
        }

        size_t m_commonDataSize = 16;
        int* m_commonData = nullptr;

    protected:
        ~Mixin() {
            mixin_class_dtor_called++;
            commonProcess_destruct();
        }
    };

    ////////////////////////////////////
    // offer stable nonvirtual interface and the ability to
    // customize the implementation
    // allow interaction via base pointer
    // allow polymorphic deletion
    class NVI {
    public:
        int process() {
            return process_impl();
        }
        virtual ~NVI() = default;

    private:
        virtual int process_impl() = 0;
    };

    ////////////////////////////////////
    // a simple implementation
    class Impl : virtual public NVI {
    private:
        int process_impl() override {
            return 222;
        }
    };

    ////////////////////////////////////
    // customizer's implementation + mixin's common logic
    class Customized : public Mixin, virtual public NVI {
    public:
        // mix class's dtor is called via its subobject
        ~Customized() override = default;
    private:
        int process_impl() override {
            commonProcess_construct(22);
            return std::accumulate(
                m_commonData,
                m_commonData + m_commonDataSize,
                0);
        }
    };

    // creation via base pointer
    NVI* doers[2] = {
        new Impl,
        new Customized,
    };

    // interaction via base pointer
    assert(222 == doers[0]->process());
    assert(22 * 16 == doers[1]->process());

    // deletion via base pointer
    delete doers[0];
    delete doers[1];

    // verify that mixin class's dtor is called
    assert(mixin_class_dtor_called);
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}