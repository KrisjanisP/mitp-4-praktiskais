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
         << "2: Queue" << endl
         << "3. Stack" << endl
         << "4. Two stack (queue)" << endl
         << "5. Set" << endl
         << "6. Output numbers" << endl
         << "7. End program" << endl;

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

