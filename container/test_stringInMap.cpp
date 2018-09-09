//
// Created by wein on 11/27/17.
//

#include <cassert>
#include <string>
#include <map>


struct Bone {
    std::string name;
    const std::string &getName();
};


const std::string& Bone::getName() {
    return name;
}


void runTests() {
    Bone *pBone = new Bone();
    pBone->name = "asd";

    std::map<std::string, int> some;
    some[pBone->getName()] = 1;

    delete(pBone);

}


int main(int argc, char** arv) {
    runTests();

    return 0;
}