#include <iostream>
#include <io.h>
#include <fcntl.h>

using std::wcin;
using std::wcout;
using std::endl;
using std::wstring;

int main()
{
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stdin), _O_WTEXT);

    wstring str = L"Programmas ir jaraksta cilvekiem, kas tas lasis!";

    int ok = 1;
    do
    {
        wcout << L"1: Ievadīt jaunu tekstu (parastie burti)" << endl
             << L"2: Pasaka vai ievadītā teksta garums ir pāra vai nepāra skaitlis" << endl
             << L"3. Izvada summu no 1..n (kur n = teksta garums)" << endl
             << L"4. Atrod faktoriāli n (kur n = teksta garums)" << endl
             << L"5. Izvada virkni no otrā gala (reversā)" << endl
             << L"6. Beigt darbību" << endl;

        int choice;
        wcin >> choice;

        switch (choice)
        {
        case 1:
            wcout << L"Ievadīt virkni: ";
            wcin.ignore();
            fflush(stdin);
            getline(wcin, str);
            break;
        case 2:
            wcout << L"Teksta garums ir " << (str.length() & 1 ? L"nepāra" : L"pāra")
                 << L" skaitlis!" << endl;
            break;
        case 3:
            wcout << L"Summa no 1 līdz " << str.length() << " ir "
                 << (str.length() * (str.length() + 1)) / 2 << "!" << endl;
            break;
        case 4:
            wcout << L"Coming soon" << endl;
            break;
        case 5:
            for (int i = str.length() - 1; i >= 0; --i)
            {
                wcout << str[i];
            }
            wcout << endl;
            break;
        case 6:
            wcout << L"Programmas darbība pabeigta!" << endl;
            ok = 0;
            break;
        default:
            wcout << L"Ievadīt korektu vērtību!" << endl;
            break;
        }

    } while (ok);

    return 0;
}