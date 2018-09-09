#include <iostream>
#include <sstream>

// source
// cpp reference
// see stackoverflow "should operator<< be implemented as a friend..."


// note, it is suggested to put the overloaded stream op in the SAME
// namespace that declares the class SUT
// caller does not need to be in this namespace in order to take 
// advantage of the stream overloading - there is a named look-up
// mechanism
namespace example {

struct SUT {
};

std::ostream& operator <<(std::ostream& o_stream, const SUT& sut) {
    o_stream << "asd";
    return o_stream;
}

}

int main() {
    std::stringstream ss;

    // named look-up will make sure the overloaded stream op inside 
    // namespace "example" is called
    ss << example::SUT() << std::endl;
    std::cout << ss.str();

    // note how to "clear" the content of sstream
    // source: stackoverflow
    ss.str("");
    std::cout << ss.str();
    return 0;
}
