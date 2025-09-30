//=======================================================================
//	Лабораторная №3. Шаблоны функций. Шаблоны классов. Стандартные шаблоны С++.
//				Обработка исключений.
//=======================================================================
// Используйте недостающие файлы из лабораторной 2
#include <algorithm>

#include <string>
#include <list>
#include <vector>
using std::list;
using std::string;
using std::vector;

#include "MyVector.h"
#include "MyString.h"
#include "Config.h"
#include "MyStack.h"
#include "StringEquals.h"

//============= Шаблон функции для вывода с помощью итератора
template <class T>
void pr(T &v, string s)
{
    cout << "\n\n\t" << s << "  # Sequence:\n";

    // Итератор любого контейнера
    typename T::iterator p;
    int i;

    for (p = v.begin(), i = 0; p != v.end(); p++, i++)
        cout << endl
             << i + 1 << ". " << *p;
    cout << '\n';
}

void printList(const list<Vector> &l, const string &s = "")
{
    if (!s.empty())
        cout << BLUE << s << ":"
             << RESET;
    for (list<Vector>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        it->Out();
    }
    cout << endl;
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void callOut(const Vector &vec)
{
    vec.Out();
}

bool HasLargeCoord(const Vector &vec)
{
    return vec.GetX() > 2 && vec.GetY() > 2;
}

int main()
{

    //===========================================================
    // Шаблоны функций
    //===========================================================
    // Создайте шаблон функции перестановки двух параметров - Swap().
    // Проверьте работоспособность созданного шаблона с помощью
    // приведенного ниже фрагмента.
    {
        int i = 1, j = -1;
        //		Swap (i, j);

        double a = 0.5, b = -5.5;
        //		Swap (a, b);

        Vector u(1, 2), w(-3, -4);
        //		Swap(u, w);

        // Если вы достаточно развили класс MyString в предыдущей работе,
        // то следующий фрагмент тоже должен работать корректно.

        MyString s1("Your fault"), s2("My forgiveness");
        cout << "s1 before: " << s1 << "s2 before: " << s2 << endl;
        Swap(s1, s2);
        cout << "s1 after: " << s1 << "s2 after: " << s2 << endl;
    }
    //===========================================================
    // Шаблоны классов
    //===========================================================
    // Создайте шаблон класса MyStack для хранения элементов любого типа T.
    // В качестве основы для стека может быть выбран массив.
    // Для задания максимального размера стека может быть использован
    // параметр-константа шаблона
    // Обязательными операциями со стеком являются "Push" и "Pop","GetSize" и "Capacity"
    // Необязательной - может быть выбор по индексу (operator[]).
    // Для того, чтобы гарантировать корректное выполнение этих операций
    // следует генерировать исключительные ситуации.

    // С помощью шаблона MyStack создайте стек переменных типа int, затем
    // стек переменных типа double и, наконец, стек из переменных типа Vector
    // Если вы подготовите три класса для обработки исключений,
    // то следующий фрагмент должен работать
    try
    {
        cout << "\tTest MyStack\n";
        MyStack<int, 3> stack;

        cout << "\nInteger Stack capacity: " << stack.Capacity();

        stack.Push(1);
        stack.Push(2);
        stack.Push(3);

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

        // stack.Push(4);       // Здесь должно быть "выброшено" исключение

        cout << "\nInteger Stack pops: " << stack.Pop();
        cout << "\nInteger Stack pops: " << stack.Pop();

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
        stack.Pop();
        // stack.Pop();         // Здесь должно быть "выброшено" исключение
        stack.Push(2);

        // int i = stack[3]; // Здесь должно быть "выброшено" исключение

        MyStack<Vector, 5> ptStack;

        cout << "\nVector Stack capacity: " << ptStack.Capacity();

        ptStack.Push(Vector(1, 1));
        ptStack.Push(Vector(2, 2));

        cout << "\nVector Stack pops: ";
        // Используйте метод класса Vector для вывода элемента
        ptStack.Pop().Out();

        cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
    }
    catch (StackOverflow)
    {
        cout << RED << "\nStack overflow" << RESET << endl;
    }
    catch (StackUnderflow)
    {
        cout << RED << "\nStack underflow" << RESET << endl;
    }
    catch (StackOutOfRange o)
    {
        o.Out();
    }
    cout << endl;

    //=======================================================================
    // Контейнеры стандартной библиотеки. Последовательности типа vector
    //=======================================================================

    // Создайте пустой вектор целых чисел. Узнайте его размер с помощью метода size(),
    // С помощью метода push_back() заполните вектор какими-либо значениями.
    // Получите новый размер вектора и выведите значения его элементов.
    // В процессе работы с вектором вы можете кроме количества реально заполненных
    // элементов (size()) узнать максимально возможное количество элементов (max_size()),
    // а также зарезервированную память (capacity()).

    cout << PURPLE << "\n======== Vector<int> ========\n"
         << RESET << endl;
    vector<int> v;
    int n = v.size();
    cout << BLUE << "Current size of v = " << n << RESET << endl;
    v.push_back(-1);
    v.push_back(-2);
    n = v.size();
    cout << BLUE << "Now there are 2 elements in v and size = " << n << RESET << endl;
    n = v.capacity();
    cout << BLUE << "Current capacity of v: " << n << RESET << endl;
    // n = v.max_size();
    cout << BLUE << "Current max_size of v: " << v.max_size() << RESET << endl;
    // Так как мы часто будем выводить последовательности, то целесообразно
    // создать шаблон функции для вывода любого контейнера.
    // Проанализируйте коды такого шаблона (pr), который приведен выше
    // Используйте его для вывода вашего вектора

    pr(v, "Vector of ints");

    // Используем другой конструктор для создания вектора вещественных
    // с начальным размером в 2 элемента и заполнением (222.).
    // Проверим параметры вектора. Затем изменим размер вектора и его заполнение
    // (метод - resize()) и вновь проверим параметры.

    cout << PURPLE << "\n======== Vector<double> ========\n"
         << RESET << endl;
    vector<double> vd(2, 222.);
    pr(vd, "Vector of doubles");
    cout << BLUE << "After creation with size 2 and value 222.0:" << RESET << endl;
    cout << "Size: " << vd.size() << endl;
    cout << "Capacity: " << vd.capacity() << endl;
    cout << "max_size: " << vd.max_size() << endl;

    vd.resize(5, 111.);
    pr(vd, "After resize");
    cout << BLUE << "After resize with size 5 and value 111.0:" << RESET << endl;
    cout << "Size: " << vd.size() << endl;
    cout << "Capacity: " << vd.capacity() << endl;
    cout << "max_size: " << vd.max_size() << endl;

    // Используя метод at(), а также операцию выбора [], измените значения
    // некоторых элементов вектора и проверьте результат.
    vd[1] = 888.0;
    vd.at(2) = 999.0;
    pr(vd, "After at");

    // Создайте вектор вещественных, который является копией существующего.
    vector<double> wd(vd);
    pr(wd, "Copy");

    // Создайте вектор, который копирует часть существующей последовательности
    // vector<double> ud
    vector<double> ud(vd.begin(), vd.begin() + 3);
    pr(ud, "Copy part");

    // Создайте вектор вещественных, который является копией части обычного массива.
    double ar[] = {0., 1., 2., 3., 4., 5.};
    vector<double> va(ar + 1, ar + 4);
    pr(va, "Copy part of array"); // * 1 2 3

    // Создайте вектор символов, который является копией части обычной строки
    char s[] = "Array is a succession of chars";

    vector<char> vc(s, s + 8); // * Array is
    pr(vc, "Copy part of c-style string");

    // Создайте вектор элементов типа Vector и инициализируйте
    // его вектором с координатами (1,1).
    vector<Vector> vv(1, Vector(1., 1.));

    cout
        << "\n\nvector of Vectors\n";
    for (int i = 0; i < vv.size(); i++)
        vv[i].Out();
    cout << endl;

    // Создайте вектор указателей на Vector и инициализируйте его адресами
    // объектов класса Vector
    Vector v1(1.1, 1.1);
    Vector v2(2.2, 2.2);
    Vector v3(3.3, 3.3);
    vector<Vector *> vp;
    vp.push_back(&v1);
    vp.push_back(&v2);
    vp.push_back(&v3);

    cout << "\n\nvector of pointers to Vector\n";

    for (int i = 0; i < vp.size(); i++)
        vp[i]->Out();
    cout << endl;

    // Научитесь пользоваться методом assign и операцией
    // присваивания = для контейнеров типа vector.
    vp.assign({&v1, &v3});

    cout << "\n\nAfter assign\n";
    for (int i = 0; i < vp.size(); i++)
        vp[i]->Out();
    cout << endl;

    vector<Vector *> vp2 = vp;

    cout << "\n\nAfter '='\n";
    for (int i = 0; i < vp2.size(); i++)
        vp2[i]->Out();
    cout << endl;

    // Декларируйте новый вектор указателей на Vector и инициализируйте его
    // с помощью второй версии assign

    vector<Vector *> vpNew;
    vpNew.assign(3, &v3);

    cout << "\n\nNew vector after assign\n";
    for (int i = 0; i < vpNew.size(); i++)
        vpNew[i]->Out();
    cout << endl;

    // На базе шаблона vector создание двухмерный массив и
    // заполните его значениями разными способами.
    // Первый вариант - прямоугольная матрица
    // Второй вариант - ступенчатая матрица

    cout << PURPLE << "\n======== Rectangular Matrix ========\n"
         << RESET << endl;

    vector<vector<double>> rMatrix(4, vector<double>(5));

    // Fill
    for (int i = 0; i < rMatrix.size(); i++)
    {
        for (int j = 0; j < rMatrix[i].size(); j++)
        {
            rMatrix[i][j] = i * 10 + j;
        }
    }
    // Print
    for (int i = 0; i < rMatrix.size(); i++)
    {
        for (int j = 0; j < rMatrix[i].size(); j++)
        {
            cout << setw(2) << rMatrix[i][j] << " ";
        }
        cout << endl;
    }

    //========= Ступенчатая матрица
    cout << PURPLE << "\n======== Jugged Matrix ========\n"
         << RESET << endl;

    vector<vector<double>> jMatrix(6, vector<double>(10));

    // Fill
    for (int i = 0; i < jMatrix.size(); i++)
    {
        for (int j = i * 2; j < jMatrix[i].size(); j++)
        {
            jMatrix[i][j] = i * 10 + j + 1;
        }
    }
    // Print
    for (int i = 0; i < jMatrix.size(); i++)
    {
        for (int j = 0; j < jMatrix[i].size(); j++)
        {
            cout << setw(2) << jMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //===================================
    // Простейшие действия с контейнерами
    //===================================
    // 3б. Получение значения первого и последнего элементов последовательности.
    // Получение размера последовательности. Присваивание значений
    // элементов одной последовательности элементам другой - assign().

    cout << PURPLE << "======== Char container operations ========"
         << RESET << endl;

    // Создайте и проинициализируйте вектор из элементов char. Размер -
    // по желанию.

    vector<char> vchar({'a', 'b', 'c', 'd'});
    pr(vchar, "Vector of chars:");

    // Создайте и проинициализируйте массив из элементов char. Размер -
    // по желанию.

    char cMas[] = {'A', 'B', 'C', 'D'};
    cout << BLUE << "Array of chars: " << RESET;
    for (int i = 0; i < sizeof(cMas) / sizeof(cMas[0]); i++)
    {
        cout << cMas[i] << " ";
    }
    cout << endl;

    // Получите значение первого элемента вектора ( front() )

    cout << BLUE << "First element of vchar: " << RESET << vchar.front() << endl;

    // Получите значение последнего элемента вектора ( back() )

    cout << BLUE << "Last element of vchar: " << RESET << vchar.back() << endl;

    // Получите размер вектора

    cout << BLUE << "Size of vchar: " << RESET << vchar.size() << endl;

    // Присвойте вектору любой диапазон из значений массива cMas.

    vchar.assign(cMas + 1, cMas + 3);
    pr(vchar, "Vector of chars after assign");

    // Проверьте размер вектора, первый и последний элементы.
    cout << BLUE << "First element of vchar: " << RESET << vchar.front() << endl;
    cout << BLUE << "Last element of vchar: " << RESET << vchar.back() << endl;
    cout << BLUE << "Size of vchar: " << RESET << vchar.size() << endl;

    // 3в. Доступ к произвольным элементам вектора с проверкой - at()
    // и без проверки - []
    // Создайте неинициализированный вектор из 8 элементов char - vChar2.
    // С помощью at() присвойте четным элементам вектора значения
    // элементов vChar1 из предыдущего задания,
    // а с помощью [] присвойте нечетным элементам вектора vChar2 значения
    // массива {'K','U','K','U'}.

    cout << PURPLE << "\n======== Vector at() vs [] ========\n"
         << RESET << endl;

    vector<char> vChar1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    char chars1[] = {'K', 'U', 'K', 'U'};

    vector<char> vChar2(8);

    for (int i = 0; i < vChar2.size(); i++)
    {
        if (i % 2 == 0)
            vChar2.at(i) = vChar1.at(i);
        else
            vChar2[i] = chars1[i / 2];
    }

    pr(vChar2, "vChar2 after manipulations");

    // Попробуйте "выйти" за границы вектора с помощью at() и
    // с помощью []. Обратите внимание: что происходит при
    // попытке обращения к несуществующему элементу в обоих случаях

    // cout << vChar2.at(100) << endl; //! libc++abi: terminating due to uncaught exception of type std::out_of_range: vector
    // * at() проверяет индекс на выход за границы и выбрасывает std::out_of_range | работает медленнее []

    // cout << vChar2[100] << endl; //! WRONG
    // * [] все работает без ошибок, НО НЕОПРЕДЕЛЕННОЕ ПОВЕДЕНИЕ | работает быстрее at()

    // 3г.Добавьте в конец вектора vChar2  - букву Z (push_back()). Для
    // расширения кругозора можете ее сразу же и выкинуть (pop_back())

    vChar2.push_back('Z');
    pr(vChar2, "bChar2 after push_back('Z')");
    vChar2.pop_back();
    pr(vChar2, "vChar2 after pop_back()");

    // 3д. Вставка-удаление элемента последовательности insert() - erase()
    // Очистка последовательности - clear()

    cout << PURPLE << "\n======== Insert, Erase and Clear Operations ========\n"
         << RESET << endl;

    // Вставьте перед каждым элементом вектора vChar2 букву 'W'

    for (int i = vChar2.size() - 1; i >= 0; i--)
    {
        vChar2.insert(vChar2.begin() + i, 'W');
    }

    pr(vChar2, "vChar2 after 'W' insert");

    // Вставьте перед 5-ым элементом вектора vChar2 3 буквы 'X'
    vChar2.insert(vChar2.begin() + 4, 3, 'X');

    pr(vChar2, "vChar2 after x3 'X' insert");

    // Вставьте перед 2-ым элементом вектора vChar2 с третьего по
    // шестой элементы массива "aaabbbccc"
    char arc[] = "aaabbbccc";

    vChar2.insert(vChar2.begin() + 1, arc + 2, arc + 6);

    pr(vChar2, "vChar2 array insert");

    // Сотрите c первого по десятый элементы vChar2
    vChar2.erase(vChar2.begin(), vChar2.begin() + 10);

    pr(vChar2, "vChar2 array after erase");
    // Уничтожьте все элементы последовательности - clear()

    vChar2.clear();
    pr(vChar2, "vChar2 array after clear");

    // Создание двухмерного массива

    /*
        Задание 4. Списки. Операции, характерные для списков.
        Создайте два пустых списка из элементов Vector - ptList1 и
        ptList2

        Наполните оба списка значениями с помощью методов push_back(),
        push_front, insert()

        Отсортируйте списки - sort().
        Подсказка: для того, чтобы работала сортировка, в классе Vector
        должен быть переопределен оператор "<"

        Объедините отсортированные списки - merge(). Посмотрите: что
        при этом происходит со вторым списком.
        * Второй список обнуляется

        Исключение элемента из списка - remove()
        Исключите из списка элемент с определенным значением.
        Подсказка: для этого необходимо также переопределить
        в классе Vector оператор "=="
    */

    cout << PURPLE << "\n======== Lists ========\n"
         << RESET << endl;

    list<Vector> ptList1;
    list<Vector> ptList2;

    ptList1.push_back(Vector(1.1, 1.11));
    ptList1.push_front(Vector(11.1, 11.11));
    ptList1.insert(++ptList1.begin(), Vector(111.1, 111.11));

    ptList2.push_back(Vector(2.2, 2.22));
    ptList2.push_front(Vector(22.2, 22.22));
    ptList2.insert(++ptList2.begin(), Vector(222.2, 222.22));

    printList(ptList1, "ptList1 after initializing:");
    printList(ptList2, "ptList2 after initializing:");

    // Sorting
    ptList1.sort();
    ptList2.sort();

    printList(ptList1, "ptList1 after sorting:");
    printList(ptList2, "ptList2 after sorting:");

    // Merging
    ptList1.merge(ptList2);
    printList(ptList1, "ptList1 after merging:");
    printList(ptList2, "ptList2 after merging:"); // * empty

    ptList1.push_back(Vector(1, 1));
    ptList1.push_back(Vector(1, 1));

    printList(ptList1, "ptList1 before removing Vector(1,1)");

    ptList1.remove(Vector(1, 1));
    printList(ptList1, "ptList1 after removing Vector(1,1)");

    // Задание 5. Стандартные алгоритмы.Подключите заголовочный файл
    //  <algorithm>
    // 5а. Выведите на экран элементы ptList1 из предыдущего
    // задания с помощью алгоритма for_each()
    cout << PURPLE << "\n======== Standard algorithms ========\n"
         << RESET << endl;
    std::for_each(ptList1.begin(), ptList1.end(), callOut);

    // 5б.С помощью алгоритма find() найдите итератор на элемент Vector с
    // определенным значением. С помощью алгоритма find_if() найдите
    // итератор на элемент, удовлетворяющий определенному условию,
    // например, обе координаты точки должны быть больше 2.
    // Подсказка: напишите функцию-предикат, которая проверяет условие
    // и возвращает boolean-значение (предикат может быть как глобальной
    // функцией, так и методом класса)

    list<Vector>::iterator it = std::find(ptList1.begin(), ptList1.end(), Vector(2.2, 2.22));
    cout << BLUE << "\nFound element by find(): " << RESET;
    it->Out();
    cout << endl;

    list<Vector>::iterator it_if = std::find_if(ptList1.begin(), ptList1.end(), HasLargeCoord);
    cout << BLUE << "\nFound element by find_if(): " << RESET;
    it->Out();
    cout << endl;
    cout << endl;

    // Создайте список из указателей на элементы Vector. С помощью
    // алгоритма find_if() и предиката (можно использовать предикат -
    // метод класса Vector, определенный в предыдущем задании) найдите в
    // последовательности элемент, удовлетворяющий условию
    Vector vv1(0.5, 0.5);
    Vector vv2(1., 1.);
    Vector vv3(1.5, 1.5);
    Vector vv4(2., 2.);
    Vector vv5(5.5, 5.5);

    std::list<Vector *> ptrList;
    ptrList.push_back(&vv1);
    ptrList.push_back(&vv2);
    ptrList.push_back(&vv3);
    ptrList.push_back(&vv4);
    ptrList.push_back(&vv5);

    auto itp = std::find_if(ptrList.begin(), ptrList.end(), [](const Vector *v)
                            { return v->CoordGraterThan(5); });

    if (itp != ptrList.end())
    {
        cout << BLUE << "Element found: " << RESET << endl;
        (*itp)->Out();
    }
    else
    {
        cout << RED << "Element not found" << RESET << endl;
    }

    // 5в. Создайте список элементов Vector. Наполните список
    // значениями. С помощью алгоритма replace() замените элемент
    // с определенным значением новым значением. С помощью алгоритма
    // replace_if() замените элемент, удовлетворяющий какому-либо
    // условию на определенное значение. Подсказка: условие
    // задается предикатом.

    cout << PURPLE << "\n======== Replace in list ========" << RESET << "\n\n";
    list<Vector> vList = {{1, 1}, {2, 2}, {3.3, 3.3}, {5.1, 5.6}, {21.4, 43.1}};

    printList(vList, "Current elements in list");

    cout << "\nReplace 2nd element with Vector(123, 123):" << endl;
    std::replace(vList.begin(), vList.end(), Vector(2, 2), Vector(123, 123));

    printList(vList, "Elements in list after replace()");

    std::replace_if(vList.begin(), vList.end(), [](const Vector &v)
                    { return v.CoordGraterThan(5); }, Vector(0, 0));
    printList(vList, "Elements in list after replace_if() elements grater than 5");

    // 5г. Создайте вектор строк (string). С помощью алгоритма count()
    // сосчитайте количество одинаковых строк. С помощью алгоритма
    // count_if() сосчитайте количество строк, начинающихся с заданной
    // буквы
    cout << PURPLE << "\n======== Count in strings ========" << RESET << "\n\n";

    vector<string> strings = {"first",
                              "first",
                              "first",
                              "second",
                              "second",
                              "thrid",
                              "fourth",
                              "fifth",
                              "sixth",
                              "seventh"};
    cout << BLUE << "Count of equals 'first' strings: " << RESET
         << std::count(strings.begin(), strings.end(), "first") << endl;

    char letter = 's';
    cout << BLUE << "Count of strings begins with " << letter << ": " << RESET
         << std::count_if(strings.begin(), strings.end(), [letter](const string &s)
                          { return !s.empty() && s[0] == letter; })
         << endl;

    // 5д. С помощью алгоритма count_if() сосчитайте количество строк,
    // которые совпадают с заданной строкой. Подсказка: смотри тему
    // объекты-функции

    cout << PURPLE << "\n======== Operator() in strings ========" << RESET << "\n\n";

    cout << BLUE << "Count of string with value 'first: " << RESET
         << std::count_if(strings.begin(), strings.end(), StringEquals("first")) << endl;

    cout << "\n\n";
}
