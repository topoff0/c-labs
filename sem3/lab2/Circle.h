#include "Shape.h"
#include "MyVector.h"

class Circle : public Shape
{
    Vector ptCntr;
    double R;

public:
    // === Constructors ===
    Circle();
    Circle(double x, double y, double r);

    // === Methods ===
    void Move(Vector &v);
    void Out();
    double Area();
};