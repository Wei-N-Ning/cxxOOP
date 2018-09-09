//
// Created by wein on 5/24/18.
//

#include <cassert>
#include <algorithm>
#include <memory>

struct Point {
    int x;

    Point()
        : Point(0)
    {
    }

    explicit Point(int x)
        : x(x)
    {
    }

    Point(const Point &other)
        : x(other.x)
    {
    }

    Point(Point &&other)
        : x(other.x)
    {
        other.x = 0;
    }
};

void test_moveAssignUserClass() {
    Point p1{12314};
    auto p2 = std::move(p1);
    assert(12314 == p2.x);
    assert(! p1.x);
}

void test_moveAssignUniquePtr_expectSourcePtrNullified() {
    std::unique_ptr<int> a{new int{12}};
    auto b = std::move(a);
    assert(! a.get());
}

int main() {
    test_moveAssignUserClass();
    test_moveAssignUniquePtr_expectSourcePtrNullified();
    return 0;
}