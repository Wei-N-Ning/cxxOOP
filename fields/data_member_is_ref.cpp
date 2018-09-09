//
// Created by wein on 11/28/17.
//

#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <memory>

class WeaponSpec;

typedef std::shared_ptr<WeaponSpec> WeaponSpecPtrT;
typedef std::vector<WeaponSpecPtrT> VecWeaponSpecPtrsT;
typedef std::map<std::string, WeaponSpecPtrT> NameToSpecPtrT;


class WeaponSpec {
public:
    WeaponSpec(size_t clipSize, double barrel);
    size_t clipSize;
    double barrel;
};


WeaponSpec::WeaponSpec(size_t clipSize, double barrel)
: clipSize(clipSize), barrel(barrel) {
}


class Operation {
public:
    Operation(NameToSpecPtrT &primary, NameToSpecPtrT &secondary);
    bool start();
private:
    NameToSpecPtrT &m_primary;
    NameToSpecPtrT &m_secondary;
};


Operation::Operation(NameToSpecPtrT &primary, NameToSpecPtrT &secondary)
: m_primary(primary), m_secondary(secondary) {
}


bool Operation::start() {
    for (NameToSpecPtrT::iterator it = m_primary.begin(); it != m_primary.end(); ++it) {
        std::cout << "shoot main weapon " << it->first << " for " << it->second->clipSize << " rounds, using "
                  << it->second->barrel << "mm bullets" << std::endl;
    }
    for (NameToSpecPtrT::iterator it = m_secondary.begin(); it != m_secondary.end(); ++it) {
        std::cout << "shoot sidearm " << it->first << " for " << it->second->clipSize << " rounds, using "
                  << it->second->barrel << "mm bullets" << std::endl;
    }
    return true;
}


void runTests() {
    NameToSpecPtrT primary, secondary;
    VecWeaponSpecPtrsT weapons;
    weapons.push_back(WeaponSpecPtrT(new WeaponSpec(30, 7.62)));
    weapons.push_back(WeaponSpecPtrT(new WeaponSpec(42, 4.7)));
    primary[std::string("ak47CBQ")] = weapons[0];
    secondary[std::string("mp7a3")] = weapons[1];
    Operation op(primary, secondary);
    op.start();
}


int main(int argc, char** argv) {
    runTests();

    return 0;
}
