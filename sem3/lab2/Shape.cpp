#include "Shape.h"

int Shape::Count = 0;
int Shape::Capacity = 0;

Shape **Shape::shapes = nullptr;

Shape::Shape()
{
    if (Count == Capacity)
    {
        int newCap = (Capacity == 0) ? 4 : Capacity * 2;
        Shape **newShapes = new Shape *[newCap];
        for (int i = 0; i < Count; i++)
        {
            newShapes[i] = shapes[i];
        }
        delete[] shapes;
        shapes = newShapes;
        Capacity = newCap;
    }
    shapes[Count++] = this;
}

Shape::~Shape()
{
    for (int i = 0; i < Count; i++)
    {
        if (shapes[i] == this)
        {
            for (int j = i; j < Count - 1; j++)
            {
                shapes[j] = shapes[j + 1];
            }
            break;
        }
    }
    Count--;
}

int Shape::GetCount()
{
    return Count;
}

void Shape::PrintCount()
{
    cout << "\nNow there are " << Count << " shapes\n";
}
