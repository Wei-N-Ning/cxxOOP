
// this example shows a case where
// a public class exposes a getter method, that returns a const ref
// to a object owned by the implementation class
// 
// however like EMC++ mentioned
// the implementation class does not make the const-promise, hence 
// the const-promise made by the public getter is weak
// (I can not find this chapter from EMC++, but here is an article)
// https://www.cprogramming.com/tutorial/const_correctness.html
// A note about Conceptual vs. Bitwise Constness

#include <memory>
#include <string>
#include <cstring>
#include <cassert>

// forward declaration
class Impl;
using PImpl = std::shared_ptr<Impl>;

// the public class
//
// getDoc() makes a promise that it won't modify its state hence 
// the constness of the returned reference, 
// ****but this promise is weak****;
//
// using pimpl idiom, wrapping the implementation class pointer in 
// a shared pointer
class Facade {
public:
    Facade();
    ~Facade() = default;
    const std::string& getDoc() const;
private:
    PImpl m_impl;
};

// the implementation class, must be seen by the compiler before 
// the definition of the ctor of the public class
// ----------------------------------------------

class Impl {
public:
    Impl();
    ~Impl() = default;
    std::string& getDoc();
private:
    std::string m_doc;
    int m_evilCounter = 0;
};

// define all the methods of the implementation class first
Impl::Impl()
    : m_doc("thereisacow")
{
}

// the getter method modifies its state for whatever evil reason...
std::string& Impl::getDoc()
{
    if (m_evilCounter++ > 0) {
        m_doc += "//";
    }
    return m_doc;
}

// ----------------------------------------------

// define the ctor of the public class
Facade::Facade()
    : m_impl(std::make_shared<Impl>()) 
{
}

const std::string& Facade::getDoc() const
{
    return m_impl->getDoc();
}

int main() {
    Facade f;
    assert(
        0 == std::strcmp("thereisacow", f.getDoc().c_str())
    );

    // state has been modified, even though the public getter promises 
    // to be const
    assert(
        0 != std::strcmp("thereisacow", f.getDoc().c_str())
    );
    return 0;
}
