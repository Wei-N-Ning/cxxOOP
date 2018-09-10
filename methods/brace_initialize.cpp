///
// Created by wein on 5/27/18.
//
// source: EMC++ Item 7 P49

#include <cassert>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include <type_traits>

enum class InitType {
    Default,
    Value,
    InitializerList,
    CopyCtor,
    CopyAsgn,
};

struct POD {
    POD() noexcept
        :m_value(0), m_type(InitType::Default)
    {
    }
    explicit POD(int x) noexcept
        :m_value(x), m_type(InitType::Value)
    {
    }
    POD(std::initializer_list<int> i) noexcept {
        auto it = i.begin();
        m_value = *it;
        m_type = InitType::InitializerList;
    }
    POD(const POD &other) noexcept
        :m_value(other.m_value), m_type(InitType::CopyCtor)
    {
    }
    POD &operator=(const POD &other) noexcept {
        m_value = other.m_value;
        m_type = InitType::CopyAsgn;
        return *this;
    }
    int m_value;
    InitType m_type;
};

namespace Item7 {

void verifyInitType() {
    assert(InitType::Default == POD().m_type);
    assert(InitType::Value == POD(0).m_type);

    POD p1{9};
    assert(InitType::InitializerList == p1.m_type &&
           9 == p1.m_value);

    // "assign-braces" also invokes initializer ctor
    //
    // EMC++ P52: even though POD has a ctor that
    // takes one integer, the compiler still favors
    // the initializer list version
    POD p2 = {11};
    assert(InitType::InitializerList == p2.m_type &&
           11 == p2.m_value);

    // this invokes copy ctor; NOT AN ASSIGNMENT
    POD p3 = p1;
    assert(InitType::CopyCtor == p3.m_type &&
           9 == p3.m_value);

    // this invokes assignment operator
    p2 = p1;
    assert(InitType::CopyAsgn == p2.m_type &&
           9 == p2.m_value);
}

void mostVexingParse() {
    // this declares a function
    // note: on bsd this will throw most vexing warning
    // POD pp();
    // equivalent to:
    POD (* pp) () = nullptr;
    pp = []() -> POD { return POD{}; };

    // calls default ctor
    POD ppp{};
    assert(0 == ppp.m_value);
}

void vectorCtorGotchas() {
    // this is a shorter version of the conclusion of
    // Item 7 P57
    //
    // use braces-initializer and C++98 ctor as one
    // wish; the braces-init overshadows C++98 ctors
    // which is a design decision; one must know
    // the differences - think, before using it
    std::vector<int> v(10, 2);  // 10 copies of 2
    std::vector<int> vs{10, 2};  // elements 10 and 2
    assert(10 == v.size() && 2 == v[9] && 2 == v[0]);
}

}

int main() {
    Item7::verifyInitType();
    Item7::mostVexingParse();
    Item7::vectorCtorGotchas();
    return 0;
}
