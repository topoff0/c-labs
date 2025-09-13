#include "Rect.h"

Rect::Rect() : ptLT(0, 0), ptRB(0, 0) {}

Rect::Rect(const Vector &LT, const Vector &RB) : ptLT(LT), ptRB(RB) {}

Rect::Rect(double left, double top, double right, double bottom) : ptLT(left, top), ptRB(right, bottom) {}

Rect::Rect(const Rect &other) : ptLT(other.ptLT), ptRB(other.ptRB) {}

void Rect::Inflate(double d)
{
    double left = min(ptLT.GetX(), ptRB.GetX()) - d;
    double top = max(ptLT.GetY(), ptRB.GetY()) + d;
    double right = max(ptLT.GetX(), ptRB.GetX()) + d;
    double bottom = min(ptLT.GetY(), ptRB.GetY()) - d;

    ptLT = Vector(left, top);
    ptRB = Vector(right, bottom);
}

void Rect::Inflate(double dx, double dy)
{
    double left = min(ptLT.GetX(), ptRB.GetX()) - dx;
    double top = max(ptLT.GetY(), ptRB.GetY()) + dy;
    double right = max(ptLT.GetX(), ptRB.GetX()) + dx;
    double bottom = min(ptLT.GetY(), ptRB.GetY()) - dy;

    ptLT = Vector(left, top);
    ptRB = Vector(right, bottom);
}

void Rect::Inflate(double dl, double dt, double dr, double db)
{
    double left = min(ptLT.GetX(), ptRB.GetX()) - dl;
    double top = max(ptLT.GetY(), ptRB.GetY()) + dt;
    double right = max(ptLT.GetX(), ptRB.GetX()) + dr;
    double bottom = min(ptLT.GetY(), ptRB.GetY()) - db;

    ptLT = Vector(left, top);
    ptRB = Vector(right, bottom);
}

void Rect::Move(Vector &v)
{
    ptLT = Vector(ptLT.GetX() + v.GetX(), ptLT.GetY() + v.GetY());
    ptRB = Vector(ptRB.GetX() + v.GetX(), ptRB.GetY() + v.GetY());
}

void Rect::Out()
{
    cout << "\nRect ("
         << ptLT.GetX() << ", " << ptLT.GetY() << ", "
         << ptRB.GetX() << ", " << ptRB.GetY() << ')';
}

double Rect::Area()
{
    double left = min(ptLT.GetX(), ptRB.GetX());
    double top = max(ptLT.GetY(), ptRB.GetY());
    double right = max(ptLT.GetX(), ptRB.GetX());
    double bottom = min(ptLT.GetY(), ptRB.GetY());

    return ((right - left) * (top - bottom));
}

Rect &Rect::operator=(const Rect &other)
{
    if (this == &other)
        return *this;

    ptLT = other.ptLT;
    ptRB = other.ptRB;
    return *this;
}
