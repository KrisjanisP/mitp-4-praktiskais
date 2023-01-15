// PS > g++ main.cpp; ./a.exe

// Izveidot C++ programmas:
// Lietotājs ievada divus skaitļus un uz ekrāna izvada summu. Programmā no datu tipiem var būt definēti tikai norādes (pointer’i)
// Programmā ir dots veselu skaitļu masīvs - 10 elementi. Izveidot funkciju, kurā, izmantojot norādes, lietotājam tiek  paziņots vai viņa ievadītais skaitlis atrodas masīvā vai nē
// Lietotājs ievada simbola virkni. Izveidot funkciju, kura izmantojot norādi nosaka simbola virknes garumu un izdrukā uz ekrāna
// Programmā ir dots veselu skaitļu masīvs - 10 elementi. Izveidot funkciju, kurā, izmantojot norādi tiek izdrukāti masīva elementi pretējā secībā
// Izveidot funkciju, kurai tiek padota norāde uz veselu skaitļu masīvu (10 elementi) un elementu skaits. Funkcijai ir jāatgriež norāde uz masīva mazāko elementu.
// Funkcijas definīcija: int* minElelement(int* arr, int arrSize);
// Visos uzdevumos for, while ciklos un if nosacījumos izmantot norādes.

#include <iostream>
#include <limits>

using namespace std;

enum eNumber
{
    zero,
    one,
    two,
    three,
    four,
    five
};

double getNumber(const string msg);

void first();
void second();
void third();
void fourth();
void fifth();

int main()
{
    cout << "1. Sum" << endl
         << "2. Find number in array" << endl
         << "3. Find string length" << endl
         << "4. Reverse array" << endl
         << "5. Get smallest element" << endl
         << "6. End program" << endl;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)getNumber("Choice: "));
        switch (choice)
        {
        case one:
            first();
            break;
        case two:
            second();
            break;
        case three:
            third();
            break;
        case four:
            fourth();
            break;
        case five:
            fifth();
            break;
        default:
            ok = false;
            break;
        }
    } while (ok);

    return 0;
}

double getNumber(const string msg = "")
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

void first()
{
    cout << "Enter two numbers: ";
    double *numA = new double, *numB = new double;
    cin >> *numA >> *numB;

    cout << "Sum: " << *numA + *numB << endl;

    delete numA, numB;
}

void second()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Enter number to find: ";
    int *find = new int;
    cin >> *find;

    bool *found = new bool(false);
    for (const int *i = arr; i != end(arr); ++i)
    {
        if (*i == *find)
        {
            cout << "Number is in array!" << endl;
            *found = true;
        }
    }

    if (!*found)
        cout << "Number not found in array!" << endl;

    delete find, found;
}

void third()
{
    string *str = new string;

    cout << "Enter string: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, *str);

    int *length = new int(0);
    for (const char *i = (*str).c_str(); *i; ++i)
    {
        ++(*length);
    }

    cout << "String length: " << *length << endl;

    delete str, length;
}

void fourth()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (const int *i = &arr[9];; --i)
    {
        cout << *i << " ";

        if (i == arr)
            break;
    }
    cout << endl;
}

int *minElelement(int *arr, int arrSize)
{
    int *ans = &arr[0];

    for (const int *i = arr; i != (arr + arrSize); ++i)
    {
        if (*i < *ans)
        {
            *ans = *i;
        }
    }

    return ans;
}

void fifth()
{
    int arr[10] = {6, 1, 2, 3, 4, -3, 6, 7, 8, 9};

    cout << *minElelement(arr, 10) << endl;
}
