#include "IFigure.h"

TypeID::TypeID IFigure::get_type() {
    return _type_id;
}

Line::Line(Point a, Point b) : _a(a), _b(b) {
    _type_id = TypeID::Line;
}

Line::Line(std::istream &in) {
    in.read((char*)&_a, sizeof(Point));
    in.read((char*)&_b, sizeof(Point));
    _type_id = TypeID::Line;
}

void Line::draw() const {
    //
    std::cout << "Line: point a(" << _a.x << ", " << _a.y <<
              "), point b(" << _b.x << ", " << _b.y << ")." << std::endl;
    //
}

void Line::save(std::ostream& out) const {
    out.write((char*)&_a, sizeof(_a));
    out.write((char*)&_b, sizeof(_b));
}

Rectangle::Rectangle(Point a, Point b)  : _a(a), _b(b) {
    _type_id = TypeID::Rectangle;
}

Rectangle::Rectangle(std::istream &in) {
    in.read((char*)&_a, sizeof(Point));
    in.read((char*)&_b, sizeof(Point));
    _type_id = TypeID::Rectangle;
}

void Rectangle::draw() const {
    //
    std::cout << "Rectangle: point a(" << _a.x << ", " << _a.y <<
              "), point b(" << _b.x << ", " << _b.y << ")." << std::endl;
    //
}

void Rectangle::save(std::ostream &out) const {
    out.write((char*)&_a, sizeof(_a));
    out.write((char*)&_b, sizeof(_b));
}

Triangle::Triangle(Point a, Point b, Point c)  : _a(a), _b(b), _c(c) {
    _type_id = TypeID::Triangle;
}

Triangle::Triangle(std::istream &in) {
    in.read((char*)&_a, sizeof(Point));
    in.read((char*)&_b, sizeof(Point));
    in.read((char*)&_c, sizeof(Point));
    _type_id = TypeID::Triangle;
}

void Triangle::draw() const {
    //
    std::cout << "Triangle: point a(" << _a.x << ", " << _a.y << "), point b(" << _b.x << ", " << _b.y <<
              "), point c(" << _c.x << ", " << _c.y << ")." << std::endl;
    //
}

void Triangle::save(std::ostream &out) const {
    out.write((char*)&_a, sizeof(_a));
    out.write((char*)&_b, sizeof(_b));
    out.write((char*)&_c, sizeof(_c));
}

Circle::Circle(Point a, float r)  : _a(a), _r(r) {
    _type_id = TypeID::Circle;
}

Circle::Circle(std::istream &in) {
    in.read((char*)&_a, sizeof(Point));
    in.read((char*)&_r, sizeof(float));
    _type_id = TypeID::Circle;
}

void Circle::draw() const {
    //
    std::cout << "Circle: center a(" << _a.x << ", " << _a.y << "), radius r = " << _r << "." << std::endl;
    //
}

void Circle::save(std::ostream &out) const {
    out.write((char*)&_a, sizeof(_a));
    out.write((char*)&_r, sizeof(_r));
}

