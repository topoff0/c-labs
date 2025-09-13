#pragma once

#include "stdafx.h"
#include "Shape.h"
#include "MyVector.h"

class Rect : public Shape
{
private:
    Vector ptLT;
    Vector ptRB;

public:
    // === Constructors ===
    Rect();
    Rect(const Vector &LT, const Vector &RB);
    Rect(double left, double top, double right, double bottom);
    // === Copy constructor ===
    Rect(const Rect &other);

    // === Methods ===
    void Inflate(double d = 1);
    void Inflate(double dx, double dy);
    void Inflate(double dl, double dt, double dr, double db);

    void Move(Vector &v) override;
    void Out() override;
    double Area() override;

    //=== Operators ===
    Rect &operator=(const Rect &other);
};
