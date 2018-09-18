// source
//
// virtual inheritance and virtual function are two different concept
//
// virtual function
// https://en.cppreference.com/w/cpp/language/virtual
// 
// virtual base class / virtual inheritance
// https://en.cppreference.com/w/cpp/language/derived_class
//

#include <cassert>
#include <set>

//////////////// interface ////////////////

class IStream {
public:
    unsigned int m_value = 0x1;

private:
    virtual unsigned int transcode(char* buf) = 0;
};

unsigned int IStream::transcode(char *buf) {
    return 0;
}

///////////////////////////////////////////

class Input : virtual public IStream {
public:
    Input& operator>> (char* buf);

private:
    unsigned int transcode(char* buf) override;
};

Input& Input::operator>>(char *buf) {
    return *this;
}

unsigned int Input::transcode(char *buf) {
    return 1;
}

///////////////////////////////////////////

class Output : virtual public IStream {
public:
    Output& operator<< (char* buf);

private:
    unsigned int transcode(char* buf) override;
};

Output& Output::operator<<(char *buf) {
    return *this;
}

unsigned int Output::transcode(char *buf) {
    return 2;
}

///////////////////////////////////////////

class IO : public Input, public Output {
public:
    unsigned int test();

private:
    unsigned int transcode(char* buf) override;
};

unsigned int IO::test() {
    char buf[5] = {'a', 'b', 'c'};
    (*this) << buf;
    (*this) >> buf;
    return transcode(buf);
}

unsigned int IO::transcode(char *buf) {
    return Input::m_value + Output::m_value;
}

///////////////////////////////////////////

namespace member_variables {

// Virtual inheritance is a C++ technique that ensures only one copy
// of a base class's member variables are inherited by grandchild
// derived classes.

// This feature is most useful for multiple inheritance, as it makes
// the virtual base a common subobject for the deriving class and all
// classes that are derived from it.

// This can be used to avoid the diamond problem by clarifying
// ambiguity over which ancestor class to use, as from the perspective
// of the deriving class (C in the example above) the virtual base (X)
// acts /////// as though it were the direct base class of C, not a class
// derived indirectly through its base (A) /////////

class Base {
public:
    int m_value = 0x1;
};

class Input : virtual public Base {
    ;
};

class Output : virtual public Base {
    ;
};

// The Base portion of Doer::Input is the same Base instance as the one
// used by Doer::Output (verified by memory address)
// this is to say Doer has only one shared Base instance in its
// representation (no ambiguity)

class Doer : public Input, public Output {
public:
    std::set<int *> values() {
        std::set<int *> ptrs;
        ptrs.insert(&m_value);
        ptrs.insert(&(Input::m_value));
        ptrs.insert(&(Output::m_value));
        return ptrs;
    }
};

// Without virtual inheritance, if classes A and B both inherit from
// class X, and class C inherits from classes A and B, then class C
// will contain two copies of X's member variables: one via A, and one
// via B. These will be accessible independently, using scope resolution.

struct BITMAP {
    int uuid = 0x1;
};

struct PNG : public BITMAP {
    ;
};

struct JPG : public BITMAP {
    ;
};

struct IMAGE : PNG, JPG {
    std::set<int *> values() {
        std::set<int *> ptrs;

        // this won't compile!
        // error: reference to ‘uuid’ is ambiguous
        // ptrs.insert(&uuid);

        ptrs.insert(&(PNG::uuid));
        ptrs.insert(&(JPG::uuid));
        return ptrs;
    }
};

}

void RunTinyTests();

void test_ensure_one_member_variable() {
    using namespace member_variables;

    member_variables::Doer doer;
    assert(1 == doer.values().size());
}

void test_multiple_member_variable_copies() {
    using namespace member_variables;

    IMAGE image;
    assert(2 == image.values().size());

    // this won't compile
    // error: ‘member_variables::BITMAP’ is an ambiguous base of
    // ‘member_variables::IMAGE’
    // BITMAP& bitmap = image;

    // the workaround is to explicitly disambiguate
    BITMAP& bitmap = static_cast<JPG &>(image);
    assert(bitmap.uuid == 1);

    // similarly this is also to explicitly disambiguate
    // instead of this image.uuid == 1, do:
    assert(image.JPG::uuid == 1);
}

void test_access_by_object() {
    IO io;
    assert(0x2 == io.test());
}

void test_access_by_own_pointer() {
    IO io;
    IO* ptr(&io);
    assert(0x2 == ptr->test());
}

int main(int argc, char **argv) {
    RunTinyTests();
    return 0;
}
