#include "Config.h"
#include "MyVector.h"

Vector::Vector(double c1, double c2)
{
    x = c1;
    y = c2;
}

Vector::Vector()
{
    x = y = 0.;
}

Vector::Vector(const Vector &v)
{
    *this = v;
}

bool Vector::Equals(const Vector &other)
{
    return fabs(!(*this) - !other) < __DBL_EPSILON__;
}

double Vector::operator*(Vector &other) const
{
    return x * other.x + y * other.y;
}

bool Vector::CoordGraterThan(const double value) const
{
    return x > value && y > value;
}

double Vector::GetX() const
{
    return x;
}

double Vector::GetY() const
{
    return y;
}

void Vector::Move(Vector &v)
{
    x += v.GetX();
    y += v.GetY();
}

void Vector::Out() const
{
    cout << "\nVector:  x = " << x << ",  y = " << y;
}

double Vector::Area() const
{
    return 0.0;
}

Vector::~Vector()
{
}

//====== Переопределение операций =====//
Vector &Vector::operator=(const Vector &v) // Присвоение
{
    if (this == &v)
        return *this;
    x = v.x;
    y = v.y;
    return *this;
}

Vector Vector::operator+(const Vector &other)
{
    return Vector(x + other.x, y + other.y);
}

double Vector::operator!() const
{
    return sqrt(x * x + y * y);
}

bool Vector::operator>(const Vector &other) const
{
    return !(*this) > !other;
}

bool Vector::operator==(const Vector &other) const
{
    return x == other.x && y == other.y;
}

bool Vector::operator<(const Vector &other) const
{
    return !(*this) < !other;
}

Vector Vector::operator*(double scalar) const
{
    return Vector(x * scalar, y * scalar);
}

Vector operator*(double scalar, const Vector &v)
{
    return Vector(scalar * v.x, scalar * v.y);
}
