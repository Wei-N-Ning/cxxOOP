
struct Value {};

class Lock {
public:
    void foo();

private:
    Value m_value;
};

void needReference(Value& value) {
    ;
}

void Lock::foo() {
    needReference(m_value);
}

int main() {
    Lock l;
    l.foo();
    return 0;
}
