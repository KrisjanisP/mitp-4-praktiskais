// PS > g++ main.cpp; ./a.exe

// Izveidot C++ programmā funkcijas:
// Lietotājs ievada simbola virkni. Izveidot funkciju, kas apgriež simbola virkni pretējā secībā
// Lietotājs ievada skaitli n. Izveidot funkciju, kas rekursīvi aprēķina summu no 1..n
// Izveidot 4 funkcijas ar vienādu nosaukumu Print, kuras uz ekrāna izdrukā padoto vērtību sekojošiem datu tipiem: int, string, double, char.
// Izveidot funkciju Min, kura atgriež minimālo elementu no 2 padotajiem. Datu tips var būt dažāds funkciju izmantojot.
// Izveidot kalkulatoru. Programma lietotājam prasa ievadīt 2 skaitļus un operāciju. Atkarībā no perācijas (+, -, *,  /) izsauc atbilstošo funkciju un attēlo rezultātu.

#include <windows.h>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

double get_number(const string msg);

void first();
void second();
void third();
void fourth();
void fifth();

int main()
{
    SetConsoleOutputCP(65001);

    cout << "1: Reverse string" << endl
         << "2: Recursive sum" << endl
         << "3. Overloading" << endl
         << "4. Template " << endl
         << "5. Calculator" << endl
         << "6. End program" << endl;

    bool ok = true;
    do
    {
        const int choice = (int)get_number("Choice: ");
        switch (choice)
        {
        case 1:
            first();
            break;
        case 2:
            second();
            break;
        case 3:
            third();
            break;
        case 4:
            fourth();
            break;
        case 5:
            fifth();
            break;
        default:
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

string reverseString(const string &str)
{
    string ans = "";
    for (auto i = str.rbegin(); i != str.rend(); ++i)
    {
        ans += *i;
    }
    return ans;
}

void first()
{
    cout << "Enter a string: ";
    string str;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);
    cout << "Reversed string: " << reverseString(str) << endl;

    return;
}

int sum(int x)
{
    if (x)
    {
        return x + sum(x - 1);
    }

    return 0;
}

void second()
{
    int n = (int)get_number("Enter an integer: ");
    cout << "Sum of numbers from 1 to " << n << ": " << sum(n) << endl;

    return;
}

void print(const int &x)
{
    cout << "Integer: " << x << endl;
    return;
}

void print(const double &x)
{
    cout << "Double: " << x << endl;
    return;
}

void print(const string &x)
{
    cout << "String: " << x << endl;
    return;
}

void print(const char &x)
{
    cout << "Char: " << x << endl;
    return;
}

void third()
{
    int i = (int)get_number("Enter an integer: ");

    double d = get_number("Enter a floating point number: ");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter a string: ";
    string s;
    getline(cin, s);

    cout << "Enter a char: ";
    char c;
    cin >> c;

    print(i);
    print(d);
    print(s);
    print(c);

    return;
}

template <typename T>
T Min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

void fourth()
{
    int i = (int)get_number("Enter an integer: ");
    int ii = (int)get_number("Enter an integer: ");

    double d = get_number("Enter a floating point number: ");
    double dd = get_number("Enter a floating point number: ");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter a string: ";
    string s;
    getline(cin, s);
    cout << "Enter a string: ";
    string ss;
    getline(cin, ss);

    cout << "Enter a char: ";
    char c;
    cin >> c;
    cout << "Enter a char: ";
    char cc;
    cin >> cc;

    cout << "Smallest integer: " << Min(i, ii) << endl
         << "Smallest floating point number: " << Min(d, dd) << endl
         << "Smallest string: " << Min(s, ss) << endl
         << "Smallest char: " << Min(c, cc) << endl;

    return;
}

void fifth()
{
    cout << "Equation in format ([number] [+-*/] [number]): ";

    double a, b;
    a = get_number();
    char op;
    cin >> op;
    b = get_number();

    cout << "Result: ";
    switch ((int)op)
    {
    case '+':
        cout << a + b;
        break;
    case '-':
        cout << a - b;
        break;
    case '*':
        cout << a * b;
        break;
    case '/':
        cout << a / b;
        break;
    default:
        cout << "Unsupported operator";
        break;
    }
    cout << endl;

    return;
}
