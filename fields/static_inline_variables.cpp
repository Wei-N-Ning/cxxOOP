//
// Created by weining on 22/12/20.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"

namespace library
{
enum class ItemColor
{
    Red,
    Blue,
};

struct Item
{
    static inline ItemColor color = ItemColor::Red;
    // c++ 17 complete guide P/26
    // constexpr implies inline
    // ^^^^^^^^^^^^^^^^^^^^^^^^
    // the above definition can be rewritten as:
    // static constexpr ItemColor color = ItemColor::Red;
    //        ^^^^^^^^^
    // the "declaration" is the definition by itself, so the code is valid
    // without the former definition
};

struct BlueItem : Item
{
    static inline ItemColor color = ItemColor::Blue;
};

inline Item nullItem;

}  // namespace library

TEST_CASE( "static inline variables for header only library" )
{
    // c++ 17 the complete guide P/23
    // if this Item type (or type family) is used by multiple translation units
    // they all refer to the same unique "color".
    // same applies to the nullItem instance: there can only be one copy of it.

    // P/25
    // the initializations are performed when the first translation unit that
    // includes the header or contains these definitions gets entered;
    // formally the `inline` used here has the same semantics as a function
    // declared inline:
    // - it can be defined in multiple translation units, provided all defs are
    //   identical
    // - it must be defined in every translation unit in which it is used
    library::Item i1{};
    library::BlueItem i2{};

    CHECK_EQ( i1.color, library::ItemColor::Red );
    CHECK_EQ( library::nullItem.color, library::ItemColor::Red );
    CHECK_EQ( i2.color, library::ItemColor::Blue );
}