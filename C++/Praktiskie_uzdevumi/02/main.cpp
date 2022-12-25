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

// 1. Papildināt ar izvēlni - “map”, kura veic sekojošas darbības:
// Ņem pa vienam skaitlim no vektora un lietotājam prasa ievadīt tā skaitļa tekstuālo vērtību, piemēram, 4 - cetri (bez mīkstinājuma burtiem) un pievieno to map sarakstā (skaitli kā atslēgu, tekstuālo kā vērtību). Tā tiek izdarīts visiem unikāliem skaitļiem vektorā
// Pēc ievades, lietotājam prasa atrast kādu skaitli map sarakstā, ja ievadīto atrod, tad izdrukā uz ekrāna tā tekstuālo atspoguļojumu, ja nē - tad to paziņo lietotājam
// Ja vienu reizi lietotājs ir aizpildījis jau kādam skaitlim tekstuālo vērtību, tad atkārtoti to neprasa. Pat tajā gadījumā, ja vektorā tiek ievadīti jauni skaitļi, kur kāds jau atrodas iekš map. Pēc jaunu skaitļu ievades vektorā, visi neaktuālie skaitļi (tādi, kuri ir map, bet vairs nav skaitļu vektorā) no map ir jāizdzēš laukā.
// 2. Izveidot header failu, kurā ievietot visas funkcijas, kuras ir saistītas ar konteineriem. Funkcijām header failā ir jāatrodas namespace apgabalā MI_Utils. Pievienot header failu programmai un izmantot apgabala MI_Utils funkcijas galvenajā programmā.
// 3. Izdomāt, kādu algoritmu - uzdevumu (kaut cik jēdzīgu), kurā tiktu izmantots “multiset”. Papildināt ar izvēlni

#include <windows.h>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define F first
#define S second

using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::greater;
using std::map;
using std::max;
using std::multiset;
using std::numeric_limits;
using std::queue;
using std::set;
using std::stack;
using std::streamsize;
using std::string;
using std::vector;

enum Digit
{
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine
};

double get_number(const string msg);
void first(vector<double> &vector);
void second(const vector<double> &vector);
void third(const vector<double> &vector);
void fourth(const vector<double> &vector);
void fifth(const vector<double> &vector);
void sixth(const vector<double> &vector);
void eighth(const vector<double> &vector);
void ninth();

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
         << "7. End program" << endl
         << "8. Map" << endl
         << "9. Multiset" << endl;

    bool ok = true;
    do
    {
        const Digit choice = static_cast<Digit>((int)get_number("Choice: "));
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
        case eight:
            eighth(vector);
            break;
        case nine:
            ninth();
            break;
        default:
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
    int n = get_number("Enter vector size: ");
    vector.resize(n);
    cout << "Enter " << n << " numbers: ";
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

void eighth(const vector<double> &vector)
{
    static map<double, string> map;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (const auto &i : vector)
    {
        if (map.find(i) == map.end())
        {
            cout << "Enter alias to use for vector value " << i << ": " << flush;
            string temp;
            getline(cin, temp);
            map[i] = temp;
        }
    }

    set<double> temp(vector.begin(), vector.end());
    for (const auto &i : map)
    {
        if (temp.find(i.F) == temp.end())
        {
            map.erase(i.F);
        }
    }

    int value = get_number("Enter value which alias to lookup: ");
    if (map.find(value) != map.end())
    {
        cout << "Alias of value: " << map[value] << endl;
    }
    else
    {
        cout << "Alias of value not found!" << endl;
    }

    return;
}

void ninth()
{
    cout << "------------------------------------------------------------------------------------" << endl
         << "This problem was taken from task fare_gatis (https://clevercode.lv/task/show/fare_gatis)." << endl
         << "It allows getting overlapping area of rectangles after adding or removing them!" << endl
         << "------------------------------------------------------------------------------------" << endl;

    multiset<double, greater<double>> left_multiset, bottom_multiset;
    multiset<double> right_multiset, top_multiset;
    int operation_count = (int)get_number("Enter operation count: ");
    cout << "Operations have to given in format [+-] [bottom left x y] [top right x y]!" << endl
         << "Example: + 1 5 8 10" << endl;
    for (int i = 1; i <= operation_count; ++i)
    {
        cout << "Operation " << i << ": ";
        char operation;
        cin >> operation;
        double bottom = get_number(), left = get_number(), top = get_number(), right = get_number();
        if (operation == '+')
        {
            left_multiset.insert(left);
            bottom_multiset.insert(bottom);
            right_multiset.insert(right);
            top_multiset.insert(top);
        }
        else if (operation == '-')
        {
            if (left_multiset.find(left) == left_multiset.end() ||
                bottom_multiset.find(bottom) == bottom_multiset.end() ||
                right_multiset.find(right) == right_multiset.end() ||
                top_multiset.find(top) == top_multiset.end())
            {
                cout << "Rectangle doesn't exist!" << endl;
                --i;
                continue;
            }
            else
            {
                left_multiset.erase(left_multiset.find(left));
                bottom_multiset.erase(bottom_multiset.find(bottom));
                right_multiset.erase(right_multiset.find(right));
                top_multiset.erase(top_multiset.find(top));
            }
        }
        else
        {
            cout << "Invalid operator!" << endl;
            --i;
            continue;
        }

        double l = *left_multiset.begin();
        double b = *bottom_multiset.begin();
        double r = *right_multiset.begin();
        double t = *top_multiset.begin();
        cout << "Overlapping size: " << (b >= t || l >= r ? 0 : (t - b) * (r - l)) << endl;
    }
}