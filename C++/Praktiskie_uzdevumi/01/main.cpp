// g++ main.cpp; ./a.exe

#include <iostream>
#include <cmath>
#include <set>
#include <io.h>
#include <fcntl.h>
#include <limits>

using std::endl;
using std::min;
using std::numeric_limits;
using std::set;
using std::streamsize;
using std::wcin;
using std::wcout;
using std::wstring;

int main()
{
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stdin), _O_WTEXT);

    wstring str = L"Programmas ir jaraksta cilvekiem, kas tas lasis!";

    wcout << L"Darbību saraksts :" << endl
          << L"1: Ievadīt jaunu tekstu" << endl
          << L"2: Pasaka vai ievadītā teksta garums ir pāra vai nepāra skaitlis" << endl
          << L"3. Izvada summu no 1..n (kur n = teksta garums)" << endl
          << L"4. Atrod faktoriāli n (kur n = teksta garums)" << endl
          << L"5. Izvada virkni no otrā gala (reversā)" << endl
          << L"6. Beigt darbību" << endl
          << L"7. Atrod īsāko vārdu virknē un izdrukā to uz ekrāna" << endl
          << L"8. Izdzēš no virknes visas pieturzīmes" << endl
          << L"9. Saskaita un attēlo uz ekrāna cik katrs cipars atkārtojas tekstā." << endl;

    int ok = 1;
    do
    {
        wcout << L"Darbība: ";
        wstring input;
        wcin >> input;

        int choice = -1;
        if (input.length() == 1)
        {
            choice = input[0] - L'0';
        }

        switch (choice)
        {
        case 1:
            wcout << L"Ievadīt virkni: ";
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            for (long long i = 1, factorial = 1, len = str.length();
                 i <= len;
                 ++i, factorial *= i)
            {
                if (len > 20)
                {
                    factorial %= ((long long)1E9 + 7);
                }
                if (i == len)
                {
                    wcout << L"Faktoriāls no " << len
                          << (len > 20 ? L" (pēc moduļa no 1E9 + 7)" : L"")
                          << " ir " << factorial << endl;
                }
            }
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
        case 7:
        {
            int shortest_length = INT_MAX;
            for (int i = 0, curr_length = 0;
                 i < str.length();
                 ++i, ++curr_length)
            {
                if (str[i] == L' ')
                {
                    shortest_length = min(shortest_length, curr_length);
                    curr_length = -1;
                }
                if (i == str.length() - 1 && ++curr_length != 0)
                {
                    shortest_length = min(shortest_length, curr_length);
                }
            }
            for (int i = 0, curr_length = 0;
                 i < str.length();
                 ++i, ++curr_length)
            {
                if (str[i] == L' ')
                {
                    if (curr_length == shortest_length)
                    {
                        for (int j = i - curr_length; j < i; ++j)
                        {
                            wcout << str[j];
                        }
                        wcout << L" ";
                    }
                    curr_length = -1;
                }
                if (i == str.length() - 1 && ++curr_length != 0)
                {
                    if (curr_length == shortest_length)
                    {
                        for (int j = i - curr_length + 1; j <= i; ++j)
                        {
                            wcout << str[j];
                        }
                        wcout << L" ";
                    }
                }
            }
            wcout << endl;
            break;
        }
        case 8:
        {
            set<wchar_t> punctuation({L'.', L',', L';', L'"', L'?', L'!', ':'});
            for (int i = 0, len = str.length(); i < len; ++i)
            {
                if (punctuation.find(str[i]) == punctuation.end())
                {
                    str.push_back(str[i]);
                }
                if (i + 1 == len)
                {
                    str.erase(0, len);
                }
            }
            wcout << str << endl;
            break;
        }
        case 9:
        {
            int arr[10]{};
            for (int i = 0; i < str.length(); ++i)
            {
                if (str[i] >= L'0' && str[i] <= L'9')
                {
                    ++arr[str[i] - L'0'];
                }
            }
            for (int i = 0; i < 10; ++i)
            {
                wcout << i << L" - " << arr[i] << endl;
            }
            break;
        }
        default:
            wcout << L"Ievadīt korektu vērtību!" << endl;
            break;
        }

    } while (ok);

    return 0;
}