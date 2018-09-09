
#include <algorithm>
#include <cassert>
#include <cstring>

// source
// exceptional P124

void RunTinyTests();

// ctor order:
// virtual base
// direct base
// non static member subobjects
// the body of the ctor is executed
// see P125 for good examples

// P125
// whether the inheritance is public, protected or private does not
// affect initialization order

void test_demo_ctor_order() {
    static char log[16];
    static size_t logwhere = 0;

    std::generate(log, log + 16, []() -> char {return '\0';});
    logwhere = 0;

    class NVI {
    public:
        NVI() {
            log[logwhere++] = 'N';
        }
        int process() {
            return processImpl();
        }
    private:
        virtual int processImpl() {
            return 0;
        }
    };

    struct Mixin {
        Mixin() {
            log[logwhere++] = 'M';
        }

        int m_commonData = 1;
    };

    struct Param {
        Param() {
            log[logwhere++] = 'P';
        }

        int m_size = 101;
        int m_typeId = 202;
    };

    class Impl : public Mixin, virtual public NVI {
    public:
        Impl() {
            log[logwhere++] = 'I';
        }

    private:
        int processImpl() override {
            return m_commonData + m_param.m_size;
        }

        Param m_param;
    };
    assert(0 == strcmp(log, ""));
    Impl impl;
    assert(0 == strcmp(log, "NMPI"));

    // NVI 'N' - virtual base
    // Mixin 'M' -  direct base
    // Param 'P' - non static member subobjects
    // Impl::Impl() 'I' - the body of the ctor is executed
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}

