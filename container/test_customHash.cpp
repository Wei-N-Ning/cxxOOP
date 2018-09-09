
#include <functional>
#include <unordered_set>
#include <string>
#include <cassert>

namespace recipes {

class Node {

public:

    Node() = default;

    Node(int value)
        : value(value),
          name{"unnamed"}{
    }

    Node(std::string name)
        : value(0),
          name(name){
    }

    Node(std::string name, int value)
        : name(name),
          value(value){
    }

    std::string getName() { return name; }

    int getValue() { return value; }

private:
    std::string name{};
    int value{};
};

}

namespace std {

template<>
class hash<recipes::Node> {
public:
    size_t operator()(recipes::Node n) {
        return std::hash<std::string>()(n.getName());
    }
};

}

void RunTinyTests();

void test_expectNodeHashValue() {
    recipes::Node n{"asd"};
    assert(std::hash<recipes::Node>()(n) ==
        std::hash<std::string>()(n.getName()));
}

int main() {
    RunTinyTests();
    return 0;
}