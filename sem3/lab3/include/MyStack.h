#pragma once

#include "Config.h"

class StackOverflow
{
};
class StackUnderflow
{
};
class StackOutOfRange
{
private:
    int index;

public:
    StackOutOfRange(int i) : index(i) {}
    void Out()
    {
        cout << RED << "\nStack index out of range: " << index << RESET << endl;
    }
};

template <typename T, int N>
class MyStack
{
private:
    T data[N];
    int top;

public:
    MyStack() : top(0) {}
    void Push(const T &value)
    {
        if (top >= N)
            throw StackOverflow();
        data[top++] = value;
    }
    T Pop()
    {
        if (top <= 0)
            throw StackUnderflow();
        return data[--top];
    }

    int GetSize()
    {
        return top;
    }
    int Capacity()
    {
        return N;
    }
    T &operator[](int index)
    {
        if (index < 0 || index >= top)
            throw StackOutOfRange(index);
        return data[index];
    }
};