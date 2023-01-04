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
#include <algorithm>

#define NAME_LENGTH 20

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

struct Product
{
    char name[NAME_LENGTH + 1];
    double price;
    int available;
    int sold;
};

class Storage
{
private:
    vector<Product> data;

public:
    Storage()
    {
        ifstream fileIn;
        fileIn.open("storage.bin", ios::in | ios::binary);

        if (fileIn.is_open())
        {
            size_t size;
            fileIn.read((char *)&size, sizeof(size));

            data.resize(size);
            fileIn.read((char *)&data[0], size * sizeof(Product));

            cout << "Opened " << size << " product(s) from file!" << endl;
        }

        fileIn.close();
    }

    ~Storage()
    {
        ofstream fileOut("storage.bin", ios::out | ios::binary);

        size_t size = data.size();
        fileOut.write((char *)&size, sizeof(size));

        fileOut.write((char *)&data[0], data.size() * sizeof(Product));

        fileOut.close();

        cout << "Saved " << size << " product(s) to file!" << endl;
    }

    void add()
    {
        Product product;

        cout << "Enter product details: " << endl
             << "Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(product.name, NAME_LENGTH);

        cout << "Price: ";
        cin >> product.price;

        cout << "Available quantity: ";
        cin >> product.available;

        cout << "Sold quantity: ";
        cin >> product.sold;

        data.push_back(product);

        return;
    }

    void print()
    {
        // for (const auto i : data)
        // {
        //     cout << i.name << endl
        //          << i.price << endl
        //          << i.available << endl
        //          << i.sold << endl
        //          << "-----------" << endl;
        // }
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        cout << "|\tName\t\t|\tPrice\t\t|\tAvailable\t|\tSold\t\t|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        for (const auto i : data)
        {
            cout << "|\t" << i.name << "\t\t|\t" << i.price << "\t\t|\t" << i.available << "\t\t|\t" << i.sold << "\t\t|" << endl;
        }
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        return;
    }

    void sell()
    {
        string name;
        cout << "Product name: ";
        cin >> name;
        int index = -1;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].name == name)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "There is not such product." << endl;
            return;
        }
        //
        int sell;
        cout << "Available quantity: " << data[index].available << endl;
        cout << "How many do you want to sell: " << endl;
        cin >> sell;
        if (sell > data[index].available)
        {
            cout << "There are not enough available " << data[index].name << " items." << endl;
            return;
        }
        data[index].available -= sell;
        data[index].sold += sell;
    }

    void search()
    {
        string name;
        cout << "Product name: ";
        cin >> name;
        int index = -1;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].name == name)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "There is not such product." << endl;
            return;
        }

        cout << "Price: " << data[index].price << endl;
        cout << "Available: " << data[index].available << endl;
        cout << "Sold: " << data[index].sold << endl;
    }

    void mostSold() {}

    void leastSold()
    {
        sort(data.begin(), data.end(), [](Product a, Product b)
             { return a.sold < b.sold; });
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        cout << "| # |\tName\t\t|\tPrice\t\t|\tAvailable\t|\tSold\t\t|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "| " << i + 1 << " |\t" << data[i].name << "\t\t|\t" << data[i].price << "\t\t|\t" << data[i].available << "\t\t|\t" << data[i].sold << "\t\t|" << endl;
        }
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
    }

    void mostEarned()
    {
        sort(data.begin(), data.end(), [](Product a, Product b)
             { return double(a.sold) * a.price > double(b.sold) * b.price; });
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        cout << "| # |\tName\t\t|\tPrice\t\t|\tAvailable\t|\tSold\t\t|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "| " << i + 1 << " |\t" << data[i].name << "\t\t|\t" << data[i].price << "\t\t|\t" << data[i].available << "\t\t|\t" << data[i].sold << "\t\t|" << endl;
        }
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
    }

    void leastEarned() {}

    void mostExpensive() {}

    void mostCheap()
    {
        sort(data.begin(), data.end(), [](Product a, Product b)
             { return a.price < b.price; });
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        cout << "| # |\tName\t\t|\tPrice\t\t|\tAvailable\t|\tSold\t\t|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "| " << i + 1 << " |\t" << data[i].name << "\t\t|\t" << data[i].price << "\t\t|\t" << data[i].available << "\t\t|\t" << data[i].sold << "\t\t|" << endl;
        }
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
    }

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
            storage.add();
            break;
        case (Output):
            storage.print();
            break;
        case (Sell):
            storage.sell();
            break;
        case (Search):
            storage.search();
            break;
        case (MostSold):
            storage.mostSold();
            break;
        case (LeastSold):
            storage.leastSold();
            break;
        case (MostEarned):
            storage.mostEarned();
            break;
        case (LeastEarned):
            storage.leastEarned();
            break;
        case (MostExpensive):
            storage.mostExpensive();
            break;
        case (MostCheap):
            storage.mostCheap();
            break;
        case (End):
            return 0;
        default:
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}