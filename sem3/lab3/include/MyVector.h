#pragma once
#include "Shape.h"

class Vector : public Shape
{
private:
    double x, y; // Координаты вектора на плоскости
public:
    //========== Три конструктора
    Vector(double c1, double c2);
    Vector(); // Default

    //========== Copy constructor
    Vector(const Vector &v);

    bool Equals(const Vector &other);

    double GetX() const;
    double GetY() const;

    void Move(Vector &v);
    void Out() const;
    double Area() const;

    ~Vector();

    //====== Переопределение операций =====//
    Vector &operator=(const Vector &v); // Присвоение

    Vector operator+(const Vector &other);

    double operator!() const;

    bool operator>(const Vector &other) const;
    bool operator==(const Vector &other) const;
    bool operator<(const Vector &other) const;

    Vector operator*(double scalar) const;
    double operator*(Vector &other) const;

    friend Vector operator*(double scalar, const Vector &v);

    bool CoordGraterThan(const double value) const;
};
