#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str = "Programmas ir jaraksta cilvekiem, kas tas lasis!";

    int ok = 1;
    do
    {
        cout << "1: Ievadīt jaunu tekstu (parastie burti)" << endl
             << "2: Pasaka vai ievadītā teksta garums ir pāra vai nepāra skaitlis" << endl
             << "3. Izvada summu no 1..n (kur n = teksta garums)" << endl
             << "4. Atrod faktoriāli n (kur n = teksta garums)" << endl
             << "5. Izvada virkni no otrā gala (reversā)" << endl
             << "6. Beigt darbību" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Ievadīt virkni: ";
            cin.ignore();
            getline(cin, str);
            break;
        case 2:
            cout << "Teksta garums ir " << (str.length() & 1 ? "nepāra" : "pāra")
                 << " skaitlis!" << endl;
            break;
        case 3:
            cout << "Summa no 1 līdz " << str.length() << " ir "
                 << (str.length() * (str.length() + 1)) / 2 << "!" << endl;
            break;
        case 4:
            cout << "Coming soon" << endl;
            break;
        case 5:
            for (int i = str.length() - 1; i >= 0; --i)
            {
                cout << str[i];
            }
            cout << endl;
            break;
        case 6:
            cout << "Programmas darbība pabeigta!" << endl;
            ok = 0;
            break;
        default:
            cout << "Ievadīt korektu vērtību!" << endl;
            break;
        }

    } while (ok);

    return 0;
}