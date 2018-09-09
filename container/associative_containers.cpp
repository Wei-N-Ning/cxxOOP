#include <map>
#include <set>

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

void test_() {
    using namespace std;
    std::map<int, double> m{{1, 1.0}};
    // will not compile: const-ness violation
    // m.find(1)->first = 111;
    
}

int main() {
    return 0;
}
