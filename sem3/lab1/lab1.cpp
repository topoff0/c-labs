#include <cmath>    // математические функции
#include <locale.h> // функции, устанавливающие национальные кодировки символов
#include <iostream> // Эта - часть библиотеки STL (Standard Template Library)
#include <limits>   // Полезные константы
#include <float.h>

using namespace std; // Обеспечивает видимость имен STL
#define stop         // __asm nop// Эта макроподстановка упрощает установку точек останова

int n; // Глобальная переменная. По умолчанию она обнуляется.

namespace space // В пространстве имен - space
{
    int n = 1; // Объявлена переменная n
} // space определяет область видимости этой переменной

int main()
{
    // Выполняя программу по шагам, следите за значениями переменных  и интерпретируйте результат, объясняя себе
    // наблюдаемые значения. Обратите внимание на разную интерпретацию отладчиком  signed и unsigned типов данных.
    char c = 'A'; // 65 'A' 0x41
    // В комментарии справа полезно проставить десятичное символьное и шестнадцатеричное
    // значения переменной после выполнения указанной строки. Вы должны видеть их в окне Autos.
    c = 0x42;     // 66 'B' 0x42
    c = -1;       // -1 'я' 0xff
    c = CHAR_BIT; // Размер переменной типа char // * 1 байт
    stop;

    // В комментариях напишите результат, возвращаемый оператором sizeof для
    // переменной типа wchar_t (ее размер)
    wchar_t cw = L'Ф';      // * Хранение длинных символов
    size_t ns = sizeof(cw); // * 4 байта

    unsigned char uc = 0x41; // * 65 'A' 0x41
    uc = 'B';                // * 66 'B' 0x42
    uc = -1;                 // * 255 0xff
    stop;

    int i = 1; // * 1
    i = -1;    // * -1
    stop;

    unsigned int ui = 1; // * 1
    ui = -1;             // * 4294967295 0xffffffff

    // short s = 0xffff; // Здесь compiler генерирует warning. Измените код, чтобы убрать warning
    short s = static_cast<short>(0xffff);
    s = short(0xffff);
    s = 1;

    //==== Измените код, чтобы убрать warning
    unsigned short us = 0xffffu;
    us = 5;

    long l = 0xffffffffL;
    l = -128;

    // Все эти константы вы должны найти в файле limits (float.h) и объяснить их смысл по комментариям

    l = DBL_MAX_EXP; // * const = 1024, максимальная степень экспоненты в двоичной записи double
    l = FLT_MAX_EXP; // * const = 128, максимальная степень экспоненты в двоичной записи float

    l = FLT_MANT_DIG; // * const = 24, количество двоичных цифр в мантиссе float
    l = DBL_DIG;      // * const = 15, количество цифр после запятой, которое помещается в double

    l = DBL_MANT_DIG; // * const = 53, количество двоичных цифр в мантиссе double

    // float f = -12.56; // Здесь warning. Уберите его.
    // ! warning: implicit conversion loses floating-point precision: 'double' to 'float' [-Wimplicit-float-conversion]
    float f = -12.56f;
    f = -1.e-27f;

    f = FLT_MAX; // * Максимальное положительное число типа float
    f = FLT_MIN; // * Минимальное отрицательное число типа float

    double d = 0.1234567890123456789123456789; // * 0.12345678901234568
    d = -0.123456789012345e+306;               // * -1.2345678901234499E+305
    d = DBL_MAX;                               // * Максимальное положительное число типа double
    d = DBL_MIN;                               // * Минимальное положительное число типа double
    d = DBL_EPSILON;                           // Самая маленькая разность между двумя пер-ми типа double

    uc = ~0; // Побитовое отрицание // * 255 0xff
    i = ~0;  // * -1 0xffff
    stop;
    // Раннее (при компиляции) или неявное приведение типов данных
    // Объясните те значения, которые вы наблюдаете в окне Autos. Определите порядок выполнения присваиваний.
    d = f = i = s = c = 1 / 3;   // * d = 0, f = 0, i = 0, s = 0, c = 0, 1 / 3 = 0;
    c = s = i = f = d = 100 / 3; // * c = 33, s = 33, i = 33, f = 33, d = 33;
    c = s = i = f = d = 10 / 3;  // * c = 3, s = 3, i = 3, f = 3, d = 3;
    c = s = i = f = d = 1 / 3.;  // * c = 0, s = 0, i = 0, f = 0.333333343, d = 0.33333333333333331;
    // * Присваивание справа налево

    // Пример "небрежного" использования неявного приведения типов.	 Объясните результаты.
    i = 256; // * 0001_0000_0000 (9 бит)
    c = i;   // * char (8 бит) берутся только младшие 8 бит (нули) => c = 0

    uc = 255;
    unsigned char u = 2, sum = uc + u;
    // * <=> 255 + 2 = 257 (0001_0000_0001). Далее берутся младшие 8 бит (единица)
    stop;

    // Явное приведение типов	Объясните разницу результатов в строках (3) и (4)
    i = 100;
    f = d = i / 3;                      // (3) // * f = 33, d = 33;
    f = d = (double)i / 3;              // (4) // * f = 33.3333321, d = 33.333333333333336;
    f = d = double(i) / 3;              // (4) // * f = 33.3333321, d = 33.333333333333336;
    f = d = static_cast<double>(i) / 3; // (4) // * f = 33.3333321, d = 33.333333333333336;
    stop;

    // Область действия, область видимости и время существования. В этом фрагменте фигурируют четыре
    //  переменных с одним и тем же именем n.  Одна - глобальная, вторая определена в своем пространстве имен,
    // третья - локальная внутри функции main(), четвертая - локальная внутри блока.
    //  Обратите внимание, что глобальная переменная и та, что в пространстве имен space - объявлены вне функции main()
    // Определите, к какой из четырех переменных идет обращение, сформулируйте область действия и область видимости
    // каждой переменной. Для выполнения задания рекомендуется пользоваться  закладкой "Watches" или "Locals" окна
    // "Autos". Подсказка: В окно "Watches" можно поместить сразу все переменные (n, ::n, и space::n)
    n = 100;        // * Глобальная
    space::n = 200; // * Из пр-ва имен space
    n++;            // * Глобальная
    int n;          // Где живет эта переменная ? // * Внутри функции main()
    n = 10;         // * Внутри функции main()
    ::n++;          // * Глобальная

    {               //  Начало блока
        int n;      // Эта переменная живет внутри блока
        n = -1;     // * Внутри блока
        n++;        // * Внутри блока
        ::n++;      // * Глобальная
        space::n++; // * Из пр-ва имен space
    } // Конец блока
    n--;        // * Внутри ф-ии main
    ::n--;      // * Глобальная
    space::n--; // * Внутри пространства space

    // Спецификатор класса памяти - static Выполняя задание по шагам, обратите внимание на  разное поведение
    // переменных nLoc и nStat
    {
    Again:
        int outer;
        for (int i = 0; i < 5; i++)
        {
            static int nStat; // * i = 0: nStat = 0,
            {
                int nLoc = 0; // * i = 0: nLoc = 0, i = 1: nLoc = 0, i = 2: nLoc = 0, ...
                nLoc++;       // * i = 0: nLoc = 1, i = 1: nLoc = 1, i = 2: nLoc = 1, ...
                nStat++;      // * i = 0: nStat = 1, i = 1: nStat = 2, i = 2: nStat = 3, ...
            }
            outer = nStat; // * i = 0: outer = 1, i = 1: outer = 2, ...
        }
        if (outer < 10)
            goto Again;
    }
    // Перечисления - enum. Обратите внимание на явную и неявную инициализацию констант
    enum RANK
    {
        One,             // * 0
        Two,             // * 1
        Three,           // * 2
        Four,            // * 3
        Jack = 6,        // * 6
        Queen,           // * 7
        Ace = Queen + 3, // * 10
        Joker = 20       // * 20
    };
    typedef RANK RANG;

    RANG r = Jack;
    if (r == Jack)
        r = Queen;

    if (r == Queen)
    {
        // Любой целочисленной переменной можно присвоить enum-переменную
        int i = r;     // * i = 7
        r = RANK(i++); // Обратное преобразование надо указывать явно // * r = 7, i = 8
        i = r;         // * i = 7
        r = RANK(++i); // * r = 8
        i = r;         // * i = 8
    }
    RANK rr = Ace; // * rr = 10
    stop;
    //	Логический тип bool.	Выполняя задание по шагам, следите за значениями переменной b
    {
        int n = 127;
        bool b = n != 0; // * true
        b = n == 0;      // * false
        b = n > 0;       // * true
        b = n <= 0;      // * false
        b = n > 1;       // * true

        int num = static_cast<int>(b); // * num = 1
        if (b)
            cout << "\n\t My flag is: true" << "   or: " << b
                 << "\n\t Conversion to int: " << num << endl;
        b = n == num; // * b = false
        cout << "\n\t Now the flag is: false" << "   or: " << b;
    }

    //	Модификатор const
    const double pi = acos(-1.);
    double space_permiability = 4.e-7 * pi; //	Магнитная проницаемость пустоты
    const int dozen = 12;
    int var = dozen;

    //	Раскомментируйте следующую строчку и объясните ошибку компиляции (l-value означает left value)
    // dozen = 1;
    // * У нас у dozen модификатор const => dozen это r-value, а значение можно менять только у l-value переменных.
    //	Директивы условной трансляции. Объясните значение, которое принимает переменная version.
    //	Что нужно сделать для того, чтобы результат был другим?
    // * Чтобы значение 'version' было другое, нужно изменить название макроса.
#define _MSVER400
    const char *version;
#if defined _MSVER400
    version = "version 4.00"; // * это значение принимает 'version'.
#elif defined _MSVER311
    version = "version 3.11";
#else
    version = "version Unknown";
#endif

    cout << endl
         << version;
    cout << endl;
    stop;
    // TODO:
    //  В окне ClassView или Solution Explorer поставьте фокус на имя проекта дайте команду Project/Properties.
    //	В диалоге Property Pages щелкните на папке Configuration Properties, убедитесь, что в разделе Code Generation
    //	установлена константа компиляции _DEBUG. Создайте директивы препроцессора и код С++, которые
    //	в зависимости от действующей конфигурации проекта (_DEBUG или NDEBUG) выводят соответствующее
    //	сообщение. Измените конфигурацию проекта (в диалоге Property Pages) и проверьте ваш код.
    //	Чтобы изменить конфигурацию пользуйтесь кнопкой Configuration Manager

#ifdef _DEBUG
    cout << "Debug configuration\n";
#elif defined(NDEBUG)
    cout << "Release configuration\n";
#else
    cout << "No debug flags\n";
#endif

    //	Простейшие циклы. Объясните суть происходящего.
    {
        // Цикл while надо использовать, когда неизвестно количество итераций (повторений) цикла.
        cout << "\n\nGradually eat out all the units:\n\n";
        unsigned short us = 0xff;
        while (us)
        {
            cout << hex << us << endl;
            us &= us - 1;
        }
        cout << hex << us << "\nDone\n";
        // Цикл for надо использовать, когда известно количество итераций и/или есть код подготовки.
        // Подсказка: odd - нечетное, even - четное.
        cout << "\n\nShow even-odd:\n\n";
        for (int i = 0; i < 10; i++)
        {
            if (i & 1)
                cout << i << " - odd\n";
            else
                cout << i << " - even\n";
        }
        // Когда нужно использовать цикл do-while?
        // * Когда нам необходимо выполнить операцию хотя бы один раз
        char c = ' ';
        do
        {
            if (c == 'a')
                cout << "\nAction is a delegate type in C#";
            else if (c == 'b')
                cout << "\nbreak is one of the 'leave' statements in all C-like languages";
            else if (c == 'c')
                cout << "\ncontinue is a 'go on' statement in all C-like languages";
            else if (c == 'd')
                cout << "\ndo-while is a rarely used loop statement in all C-like languages";
            else
                cout << "\nPlease read the rules of this loop";
            cout << "\n\nEnter chars: a, b, c, d (q - to quit):\n\n";
            cin >> c;
            if (c == 'q')
                cout << "\nI am going to leave the loop\n";
        } while (c != 'q');
        stop;
    }
    //	Логические условные операторы и циклы. Функция y = f(x) задана графиком
    //	Напишите фрагмент кода, который с шагом 0.1 вычисляет y = f(x)  и выводит в консольное окно значения x и y.
    //	  y
    //	  |
    //	 2|__________
    //	  |         /\
	//	  |        /  \
	//	  |       /    \
	//	  |______/      \__________  x
    //	  0      1   2   3
    //	 Реализуйте 2 варианта этого алгоритма:   1. Используйте операторы if	 2. Используйте тернарные операции    ? :
    // * 1 Вариант
    {
        cout << "Variant 1: \n";

        double x = 0.0;
        double y;
        while (x < 4.0)
        {
            x += 0.1;

            if (x <= 1.0)
                y = 0;
            else if (x > 1.0 && x < 2.0)
                y = 2.0 * (x - 1.0);
            else if (x > 2.0 && x < 3.0)
                y = 2.0 * (3.0 - x);
            else
                y = 0;

            cout << "Coordinates: {X}: " << x << ", {Y}: " << y << '\n';
        }
    }

    cout << endl;

    // * Вариант 2
    {
        cout << "Variant 2: \n";

        double x = 0;
        double y;

        while (x < 4.0)
        {
            x += 0.1;

            y = x <= 1.0 || x >= 3.0
                    ? 0
                : x < 2.0
                    ? 2.0 * (x - 1.0)
                    : 2.0 * (3.0 - x);

            cout << "Coordinates: {X}: " << x << ", {Y}: " << y << '\n';
        }
    }

    //	Напишите фрагмент, который с помощью for и switch реализует следующую логику. Если пользователь ввел:
    //	символ 'a',   ваш алгоритм выводит  "Ok" (в кавычках)
    //	символ 'b',   ваш алгоритм выводит  Bell (alert - звуковой сигнал)
    //	символ 'с',   ваш алгоритм выводит  число, которое равно количеству введенных символов
    //	символ 'Esc', ваш алгоритм выводит  "to quit use 'q'"
    //	символ 'q',   ваш алгоритм выводит  "Bye" и выходит из цикла ввода
    {
        int count = 0;
        char ch;
        for (;;)
        {
            for (int c = getchar(); c != '\n' && c != EOF; c = getchar())
                ;

            cout << "Enter one of the symbol: 'a', 'b', 'c', 'Esc', 'q'\n";
            cin.get(ch);
            count++;

            switch (ch)
            {
            case 'a':
                cout << "\tOk\n";
                break;
            case 'b':
                cout << "\tBell\n";
                break;
            case 'c':
                cout << "\tCount: " << dec << count << '\n';
                break;
            case 27:
                cout << "\tto quit use 'q'\n";
                break;
            case 'q':
                cout << "Bye\n";
                break;

            default:
                cout
                    << "Unrecognizable symbol, please try again...\n";
                break;
            }

            cout << endl;

            if (ch == 'q')
                break;
        }
    }
    //	Побитовые операции:  |, &, ~, ^ и сдвиги >>, <<
    //	Поменяйте местами байты переменной flags и выведите результат в консольное окно unsigned short flags = 0xaabb;
    //	Ваш код
    //	Для вывода в шестнадцатеричном виде используйте  cout <<"\n bits = " << hex << flags;
    unsigned short flags = 0xaabb;
    cout << "\n bits before = " << hex << flags << endl;
    flags = (((flags & 0xff) << 8) |
             ((flags & 0xff00) >> 8));
    cout << "\n bits after = " << hex << flags << endl;
    cout << endl;

    //	В переменной unsigned char byte = 0x26;
    //      - установите в единицу 3-й бит (счет от нуля). Выведите результат.
    //	    - инвертируйте два младших бита. Выведите результат.
    //      - обнулите 4 младших бита. Выведите результат.
    char byte = 0x26;
    cout << "byte before = " << bitset<8>(byte) << '\n';

    byte |= 1 << 3;
    cout << "byte after 1 task = " << bitset<8>(byte) << '\n';

    byte ^= 3;
    cout << "byte after 2 task = " << bitset<8>(byte) << '\n';

    byte &= 0xf0;
    cout << "byte after 3 task = " << bitset<8>(byte) << '\n';

    cout << "\n\n";
} // Конец функции main()
