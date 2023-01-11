// PS > g++ main.cpp; ./a.exe

// Lietotājs ievada tekstu. Doto tekstu saglabā failā.
// Dots masīvs ar 10 skaitļiem. Nepāra skaitļus saglabā file1.txt, pāra skaitļus saglabā failā file2.txt un pirmskaitļus saglabā failā file3.txt
// Ir dots file4.txt ar saturu:
// The syntax highlighting engine has been significantly improved, with new features like handling non-deterministic grammars, multi-line constructs, lazy embeds and syntax inheritance.
// Memory usage has been reduced, and load times are faster than ever.
// Eat snack.
// Write code.
// Eat snack.
// Programma nolasa failu un uz ekrāna izdrukā:
// Burtu skaitu
// Programma nolasa faila saturu no pirmā uzdevuma. lietotājs ievada vienu burtu. Programma saglabā saturu bez šī burta file5.txt failā.
// Lietotājs programmā ievada datumu un laiku. Piemēram, 13.10.2021 16:49
// Programma ievadīto laiku saglabā binārajā failā un to aizver ciet. Pēc tam nolasa no binārā faila ievadīto datumu un attēlo uz ekrāna. Visas darbības norealizēt kā funkcijas. Lietotājam pieejama izvēlne:
// 	1) Ievadit datumu un laiku
// 	2) Saglabāt binārajā failā
// 	3) Nolasīt un izdrukāt uz ekrāna
// 	4) Beigt programmu
// Izvēlnes iespējamie gadījumi ir jādefinē kā enum tips

#include <iostream>
#include <fstream>
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

double get_number(const string msg);

void first();
void second();
void third();
void fourth();
void fifth();

int main()
{
    cout << "1: Save text to file" << endl
         << "2: Save numbers to files" << endl
         << "3. Read digit count from file" << endl
         << "4. Remove char " << endl
         << "5. Date" << endl
         << "6. End program" << endl;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)get_number("Choice: "));
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

void first()
{
    cout << "Enter text to save to a file: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string str;
    getline(cin, str);

    ofstream fileOut("first.txt", ios::out);
    fileOut << str;
    fileOut.close();

    cout << "Text saved to [first.txt]!" << endl;
}

bool isPrime(const int &x)
{
    if (x <= 1)
        return false;

    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;

    return true;
}

void second()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ofstream odd("file1.txt", ios::out), even("file2.txt", ios::out), prime("file3.txt", ios::out);

    for (const &i : arr)
    {
        if (i & 1)
            odd << i << ", ";
        else
            even << i << ", ";
        if (isPrime(i))
            prime << i << ", ";
    }

    odd.close();
    even.close();
    prime.close();
}

void third()
{
    ifstream fileIn("file4.txt", ios::in);

    int charCount = 0;
    while (true)
    {
        char temp;
        fileIn >> temp;

        if (fileIn.eof())
            break;

        if (temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')
            ++charCount;
    }

    fileIn.close();

    cout << "Character count: " << charCount << endl;
}

void fourth()
{
    ifstream fileIn("file4.txt", ios::in);
    ofstream fileOut("file5.txt", ios::out);

    cout << "Enter character to remove: ";
    char charToRemove;
    cin >> charToRemove;

    while (true)
    {
        char temp;
        fileIn.get(temp);

        if (fileIn.eof())
            break;

        if (temp != charToRemove)
            fileOut << temp;
    }

    fileIn.close();
    fileOut.close();
}

void fifth()
{
    cout << "1: Enter date" << endl
         << "2: Save date to file" << endl
         << "3. Read date from file" << endl
         << "4. End program" << endl;

    string date;
    date.resize(50);

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)get_number("Choice: "));
        switch (choice)
        {
        case one:
            cout << "Enter date: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, date);
            break;
        case two:
        {
            ofstream fileOut("fifth.bin", ios::out | ios::binary);
            fileOut.write(date.data(), date.size());
            fileOut.close();
            break;
        }
        case three:
            {
                ifstream fileIn("fifth.bin", ios::in | ios::binary);
                if(fileIn.is_open()){
                    fileIn.read(&date[0], date.size());
                }
                fileIn.close();
                cout << "Date: " << date << endl;
                break;
            }
        default:
            ok = false;
            break;
        }
    } while (ok);
}
