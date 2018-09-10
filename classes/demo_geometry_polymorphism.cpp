
#include <string>
#include <cassert>

namespace geometry
{

class ShapeInterface
{
public:
    virtual const std::string name() const = 0;
    virtual unsigned short dimension() const = 0;
    virtual ~ShapeInterface() = default;
};

class Point : public ShapeInterface
{
public:
    const std::string name() const override
    {
        return std::string{"point"};
    }
    unsigned short dimension() const override
    {
        return 1;
    }
};

class Line : public ShapeInterface
{
public:
    const std::string name() const override
    {
        return std::string{"line"};
    }
    unsigned short dimension() const override
    {
        return 2;
    }
};

class Polygon : public ShapeInterface
{
public:
    const std::string name() const override
    {
        return std::string{"polygon"};
    }
    unsigned short dimension() const override
    {
        return 3;
    }
};

class Quad : public Polygon
{
public:
    const std::string name() const override
    {
        return std::string{"quad"};
    }
};

} // namespace geometry

using geometry::ShapeInterface;

void RunTinyTests();

void test_ExpectLineBehavior()
{
    ShapeInterface* pShape = new geometry::Line{};
    assert( pShape->name() == std::string( "line" ) );
    assert( pShape->dimension() == 2 );
    delete pShape;
}

void test_ExpectPolygonBehavior()
{
    ShapeInterface* pShape = new geometry::Polygon{};
    assert( pShape->name() == std::string( "polygon" ) );
    assert( pShape->dimension() == 3 );
    delete pShape;
}

void test_ExpectQuadBehaviorViaPointerToPolygon()
{
    geometry::Polygon* pPoly = new geometry::Quad{};
    assert( pPoly->name() == std::string( "quad" ) );
    assert( pPoly->dimension() == 3 );
    delete pPoly;
}

int main()
{
    RunTinyTests();
    return 0;
}
