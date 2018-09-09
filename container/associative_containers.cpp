#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <cassert>

// source: more exception item 8 P53
// an essential requirement (of associative containers) is once a key 
// has been inserted into the container, that key had better not be 
// changed in any way that would change its relative position in the 
// container
// (see also P57: beware of direct and indirect ways by which a key 
// might change its relative order), such as indirect ways include 
// external forces (file content, db, other code)
// 
// P54
// ... the problem here (cast away the const-ness and modify the key
// via the std map iterator) is that the code interferes with the map's 
// internal representation in a way that the map is not expecting and 
// can not deal with
// recall that std map as of C++11 uses RB tree as its internal storage 
// recall how RB tree works; how AVL tree works

// keys should not be modified at all - std::map<Key, Value>::iterator 
// points a std::pair<const Key, Value>

// P56
// one way to think of std::set is as just a std::map with the type of 
// value being void

void RunTinyTests();

void test_constness_violation() {
    using namespace std;
    map<int, double> m{{5, 1.0}, {1, 2.0}, {2, 3.0}, {3, 4.0}};

    // will not compile: const-ness violation
    // m.find(1)->first = 111;

    // but this will compile and cause trouble at runtime
    map<int, double>::iterator i = m.find(3);
    const_cast<int &>(i->first) = 999;

    // simplified runtime trouble:
    // 3 is lost
    assert(m.find(3) == m.end());

    // simplified runtime trouble #2:
    // expected order of keys: 1 2 3 5
    // actual order of keys: 1 2 999 5
    // (3 is lost; internal order is broken)
    std::for_each(m.begin(), m.end(),
        [](pair<const int, double>& elem){ std::cout << elem.first; });
}

// the correct way of doing this
void test_correction() {
    using namespace std;
    map<int, double> m{{5, 1.0}, {1, 2.0}, {2, 3.0}, {3, 4.0}};
    auto it = m.find(3);
    auto tmp = it->second;
    m.erase(it);
    m.insert(make_pair(999, tmp));
    std::for_each(m.begin(), m.end(),
        [](pair<const int, double>& elem){ std::cout << elem.first; });
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}


