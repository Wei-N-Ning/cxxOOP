
#include <cstdint>
#include <cstdlib>
#include <cassert>

void RunTinyTests();

struct BitContainer {
    
    explicit BitContainer(uint64_t* ptr)
        : m_data(ptr) {
    }
    
    uint8_t operator[] (size_t idx) {
        return ((1 << idx) & (*m_data)) >> idx;
    }

    uint64_t* m_data = nullptr;
};

void test_index_operator() {
    uint64_t v = 0b101;
    BitContainer c(&v);
    assert(1 == c[2]);
    v = 0b1010;
    assert(0 == c[2]);
}

int main() {
    RunTinyTests();
    return 0;
}
