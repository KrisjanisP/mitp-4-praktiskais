// PS > g++ main.cpp; ./a.exe

// Izveidot C++ programmu, kura veic sekojošas darbības:
// Attēlo lietotājam sekojošu izvēlni:
// 1: Ievadīt skaitļus
// 2: Rinda
// 3. Steks
// 4. Divi steki (Rinda)
// 5. Jebkuru no STL konteineriem, kas nav doti programmā
// 6. Izvada skaitļu virkni
// 7. Beigt darbību
// Lietotājs ievada vienu no izvēlnēm (1-7) un programma izpilda tās darbību.

// Programmas sākumā jau ir doti 5 skaitļi - tie ir uzglabāti vektorā: 4, 5, 6, 7, 8
// Programma beidz darbību tikai tad, kad ir ievadīta izvēlne 7
// Programma nedrīkst uzkārties. Jāparedz gadījumi, kad ievadīta ir nekorekta izvēlne
// (1) ievadītos skaitļus saglabā vektorā
// (2), (3), (4), (5), (6) - visus skaitļus iegūst no vektora
// (2) - No vektora iegūtos skaitļus pa vienam liek rindā. Kad visi skaitļi ir ievietoti, tad pa vienam ņem laukā un izņemto elementu izdrukā uz ekrāna
// (3) - No vektora iegūtos skaitļus pa vienam liek stekā. Kad visi skaitļi ir ievietoti, tad pa vienam ņem laukā un izņemto elementu izdrukā uz ekrāna
// (4) - No vektora iegūtos skaitļus pa vienam liek pirmajā stekā. Kad visi skaitļi ir ievietoti, tad pa vienam ņem laukā un liek otrajā stekā. Tad pa vienam ņem laukā no otrā steka un izņemto elementu izdrukā uz ekrāna
// (5) - izvēlaties kādu STL konteineri un realizējat viņa darbību ar skaitļiem, kas uzglabāti vektorā
// (6) - Izdrukā uz ekrāna vektorā uzglabātos skaitļus

// Visām darbībām ir jābūt norealizētām kā funkcijām
// Izvēlnes programmā ir norealizētas, izmantojot switch. Visi case gadījumi ir jāapraksta, izmantojot enum tipu.
// Programmas laikā nedrīkst izmantot globāli definētus mainīgos.

#include <windows.h>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <stack>
#include <set>

#define SIZE 5

using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::max;
using std::numeric_limits;
using std::queue;
using std::set;
using std::stack;
using std::streamsize;
using std::string;
using std::vector;

enum Number
{
    one = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7
};

double get_number(const string msg);
void first(vector<double> &vector);
void second(const vector<double> &vector);
void third(const vector<double> &vector);
void fourth(const vector<double> &vector);
void fifth(const vector<double> &vector);
void sixth(const vector<double> &vector);

int main()
{
    SetConsoleOutputCP(65001);

    vector<double> vector({4, 5, 6, 7, 8});

    cout << "1: Enter numbers" << endl
         << "2: Queue" << endl
         << "3. Stack" << endl
         << "4. Two stack (queue)" << endl
         << "5. Set" << endl
         << "6. Output numbers" << endl
         << "7. End program" << endl;

    bool ok = true;
    do
    {
        const Number choice = static_cast<Number>((int)get_number("Choice: "));
        switch (choice)
        {
        case one:
            first(vector);
            break;
        case two:
            second(vector);
            break;
        case three:
            third(vector);
            break;
        case four:
            fourth(vector);
            break;
        case five:
            fifth(vector);
            break;
        case six:
            sixth(vector);
            break;
        case seven:
            ok = false;
            break;
        }
    } while (ok);

    return 0;
}

double get_number(const string msg = "")
{
    double input = -1;
    bool valid = false;
    do
    {
        cout << msg << flush;
        cin >> input;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!valid);

    return (input);
}

void first(vector<double> &vector)
{
    cout << "Enter " << SIZE << " numbers: " << endl;
    for (auto &i : vector)
    {
        i = get_number();
    }

    return;
}

void second(const vector<double> &vector)
{
    queue<double> queue;
    for (const auto &i : vector)
    {
        queue.push(i);
    }
    cout << "Elements after being added and removed from queue: ";
    while (!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;

    return;
}

void third(const vector<double> &vector)
{
    stack<double> stack;
    for (const auto &i : vector)
    {
        stack.push(i);
    }
    cout << "Elements after being added and removed from stack: ";
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;

    return;
}

void fourth(const vector<double> &vector)
{
    stack<double> stack, stack_2;
    for (const auto &i : vector)
    {
        stack.push(i);
    }
    while (!stack.empty())
    {
        stack_2.push(stack.top());
        stack.pop();
    }
    cout << "Elements after being added and removed from two stacks: ";
    while (!stack_2.empty())
    {
        cout << stack_2.top() << " ";
        stack_2.pop();
    }
    cout << endl;

    return;
}

void fifth(const vector<double> &vector)
{
    set<double> set;
    for (const auto &i : vector)
    {
        set.insert(i);
    }
    cout << "Elements after being added to set and iterated through: ";
    for (const auto &i : set)
    {
        cout << i << " ";
    }
    cout << endl;

    return;
}

void sixth(const vector<double> &vector)
{
    cout << "Numbers in vector: ";
    for (const auto &i : vector)
    {
        cout << i << " ";
    }
    cout << endl;

    return;
}
