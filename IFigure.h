#ifndef IFIGURE_H
#define IFIGURE_H

#include <iostream>

namespace TypeID {
    enum TypeID {
        Line,
        Rectangle,
        Triangle,
        Circle
    };
}

struct Point {
    float x;
    float y;
};

class IFigure {
public:
    explicit IFigure() = default;
    virtual ~IFigure() = default;

    virtual void draw() const = 0;
    virtual void save(std::ostream& out) const = 0;
    TypeID::TypeID get_type();
protected:
    TypeID::TypeID _type_id;
};

class Line : public IFigure {
public:
    Line(Point a, Point b);
    explicit Line(std::istream& in);

    void draw() const override;
    void save(std::ostream& out) const override;
private:
    Point _a;
    Point _b;
};

class Rectangle : public IFigure {
public:
    Rectangle(Point a, Point b);
    explicit Rectangle(std::istream& in);

    void draw() const override;
    void save(std::ostream& out) const override;
private:
    Point _a;
    Point _b;
};

class Triangle : public IFigure {
public:
    Triangle(Point a, Point b, Point c);
    explicit Triangle(std::istream& in);

    void draw() const override;
    void save(std::ostream& out) const override;
private:
    Point _a;
    Point _b;
    Point _c;
};

class Circle : public IFigure {
public:
    Circle(Point a, float r);
    explicit Circle(std::istream& in);

    void draw() const override;
    void save(std::ostream& out) const override;
private:
    Point _a;
    float _r;
};

#endif //IFIGURE_H
