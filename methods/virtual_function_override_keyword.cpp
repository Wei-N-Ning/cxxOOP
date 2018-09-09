//
// Created by wein on 6/16/18.
//

// source
// EMC++ Item 12
// override keyword helps to spot interface violation and
// type mismatch
//
// see also referenceQualifiers.sh


class Base {
public:
    virtual int mf3() & = 0;
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    int mf3() & override;
    ~Derived() override = default;
};

int Derived::mf3() & {
    return 0xBEEF;
}

int _main() {
    int ret = 0;
    Base* sut = new Derived;
    if (0xBEEF != sut->mf3()) {
        ret = 1;
    }
    delete sut;
    return ret;
}

int main() {
    return _main();
}
