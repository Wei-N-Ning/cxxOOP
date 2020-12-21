//
// Created by weining on 22/12/20.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include <string>
#include <utility>

struct Pod
{
    int x;
    std::pair< char, size_t > pr;
};

struct Item
{
    Pod p;
    std::string label;
};

struct Box : public Item
{
    std::pair< int, int > kkk;
};

TEST_CASE( "initialize POD/aggregates with brace initializer" )
{
    // c++ 17 complete guide P/31
    // I have been using this syntax for a while but didn't realize it is
    // a new feature introduced by c++ 17

    // clion (the IDE) even displays the name of the fields for me, including
    // the nested field Pod.x
    // Pod.pr is initialized with zero-value
    Item i{ { 1 }, "e1m1" };

    // Pod.pr is initialized with an IL
    Item i2{ { 1, { 'a', 131 } }, "e2m2" };

    // the Item portion of Box is initialized with zero-value;
    // the new data member, kkk, a pair, is initialized with an IL
    Box box{ {}, { 1, 1 } };

    // it is still better to provide a ctor for clarity!!
}
