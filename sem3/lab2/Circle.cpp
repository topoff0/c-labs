#include "Circle.h"

Circle::Circle()
{
    ptCntr = Vector();
    R = 0.0;
}

Circle::Circle(double x, double y, double r)
{
    ptCntr = Vector(x, y);
    R = r;
}

void Circle::Move(Vector &v)
{
    ptCntr = Vector(ptCntr.GetX() + v.GetX(), ptCntr.GetY() + v.GetY());
}

void Circle::Out()
{
    cout << "\nCircle (<" << ptCntr.GetX() << ", " << ptCntr.GetY() << "> rad = " << R << ")";
}

double Circle::Area()
{
    return M_PI * R * R;
}
