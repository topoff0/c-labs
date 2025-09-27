#pragma once

#include "Config.h"

class Vector;

class Shape
{
private:
    static int Count;
    static int Capacity;

public:
    static Shape **shapes;
    // === Constructors ===
    Shape();
    virtual ~Shape();

    // === Methods ===
    static int GetCount();
    static void PrintCount();

    virtual void Move(Vector &v) = 0;
    virtual void Out() = 0;
    virtual double Area() = 0;

    // === Operator overloading ===
};