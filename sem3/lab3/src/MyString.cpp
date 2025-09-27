#include "MyString.h"

void MyString::Copy(const char *s)
{
    delete[] m_pStr;
    // Динамически выделяем требуемое количество памяти.
    int len = strlen(s) + 1;
    m_pStr = new char[len];
    // + 1, так как нулевой байт тоже нужно скопировать
    // Если память выделена, копируем строку-аргумент в строку-член класса
    if (m_pStr)
    {
        strncpy(m_pStr, s, len);
        m_pStr[len - 1] = '\0';
    }
}

MyString::MyString()
{
    m_pStr = new char[1];
    m_pStr[0] = '\0';
}

// Определение конструктора.
MyString::MyString(const char *s)
{
    m_pStr = 0;
    Copy(s);
}

MyString::MyString(const MyString &other)
{
    m_pStr = nullptr;
    Copy(other.m_pStr);
}

// Определение деструктора.
MyString::~MyString()
{
    // Освобождение памяти, занятой в конструкторе для строки-члена класса
    delete[] m_pStr;
}

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        Copy(other.m_pStr);
    }
    return *this;
}

// Метод класса
char *MyString::GetString() const
{
    return m_pStr;
}

int MyString::GetLength()
{
    return strlen(m_pStr) + 1;
}

std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << BLUE << '"' << str.GetString() << '"' << RESET << endl;
    return os;
}
