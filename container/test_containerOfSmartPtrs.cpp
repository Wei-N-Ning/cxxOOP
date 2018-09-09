//
// Created by wein on 11/28/17.
//

// a basic example showing a vector of std::shared_ptr

#include <cassert>
#include <vector>

// #include <boost/shared_ptr.hpp>
#include <memory>

// typedef boost::shared_ptr<int> PInt;
typedef std::shared_ptr<int> PInt;

void zeroValues() {
    std::vector<PInt> v(10);
    assert(!v[0].get());

    PInt pInt(new int(10));
    v[0] = pInt;  // ref count + 1
    assert(v[0].get());
}


int main(int argc, char** argv) {
    zeroValues();

    return 0;
}
