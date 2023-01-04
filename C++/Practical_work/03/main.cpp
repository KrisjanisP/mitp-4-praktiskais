// PS > g++ main.cpp program.cpp; ./a.exe

// Izveidot C++ programmu, kura attaino noliktavas programmatūras funkcijas:
// Datu ievade (tiek papildināts produkts ar skaitu; ja nav tāda produkta, tad ievietots): X1
// Visu datu izvade (izvada visus produktus uz ekrāna): X1
// Produktu pārdošana (samazina attiecīgo skaitu; ja nav tāda vai nav ko pārdot - paziņo lietotājam): X2
// Izvada konkrēti datus par vienu produktu uz ekrāna (atrod pēc vārda): X2
// Izdrukāt uz ekrāna Top3 visvairāk iztirgotos produktus: X1
// Izdrukāt uz ekrāna Top3 vismazāk iztirgotos produktus: X2
// Izdrukāt uz ekrāna Top3 tos produktus par kuriem ir visvairāk nopelnīts: X2
// Izdrukāt uz ekrāna Top3 tos produktus par kuriem ir vismazāk nopelnīts: X1
// Izdrukāt uz ekrāna Top3 visdārgākos produktus: X1
// Izdrukāt uz ekrāna Top3 vislētākos produktus: X2

// Produkti satur sekojošu informāciju: (X1)
// Nosaukums
// Cena
// Pieejamais produktu skaits
// Pārdotais produktu skaits

// Jānorealizē arī atbilstošas izvēlnes, lai lietotājam ir ērti darboties ar programmu. X2

// Piezīme. Visas darbības tiek veiktas ar binārā failā ierakstītiem datiem (produkti).

#include <bits/stdc++.h>

using namespace std;

enum eOptions
{
    Input,
    Output,
    Sell,
    Search,
    MostSold,
    LeastSold,
    MostEarned,
    LeastEarned,
    MostExpensive,
    MostCheap,
    End
};

struct item
{
    string name;
    double price;
    int available;
    int sold;
};

class Storage
{
private:
    vector<item> data;
    fstream file;

public:
    Storage() {}
    virtual ~Storage() {}

    void add() {}
    void print() {}
    void sell() {}
    void search() {}
    void mostSold() {}
    void leastSold() {}
    void mostEarned() {}
    void leastEarned() {}
    void mostExpensive() {}
    void mostCheap() {}

    int menu()
    {
        cout << "------------------------------------------" << endl;
        cout << "Choose option:" << endl;
        cout << "1 - Add product" << endl;
        cout << "2 - Output all products" << endl;
        cout << "3 - Sell products" << endl;
        cout << "4 - Search product" << endl;
        cout << "5 - Most sold product Top 3" << endl;
        cout << "6 - Least sold product Top 3" << endl;
        cout << "7 - Most profitable product Top 3" << endl;
        cout << "8 - Least profitable product Top 3" << endl;
        cout << "9 - Most expensive product Top 3" << endl;
        cout << "10 - Least expensive product Top 3" << endl;
        cout << "11 - Stop execution" << endl;
        cout << "------------------------------------------" << endl;
        int op;
        cout << "Choice: ";
        cin >> op;
        return op;
    }
};

int main()
{
    Storage storage;
    int op = 0;
    while (op != 11)
    {
        op = storage.menu();
        switch (op - 1)
        {
        case (Input):
            break;
        case (Output):
            break;
        case (Sell):
            break;
        case (Search):
            break;
        case (MostSold):
            break;
        case (LeastEarned):
            break;
        case (MostExpensive):
            break;
        case (MostCheap):
            break;
        case (End):
            return 0;
        default:
            cout << "Invalid option!" << endl;
        }
    }
}