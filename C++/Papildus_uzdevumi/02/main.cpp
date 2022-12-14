// 1. Ir dots skaitļu masīvs ar 10 elementiem. Aprēķināt skaitļu grupas vidējo vērtību
// 2. Ir dots skaitļu masīvs ar 10 elementiem (float tipa). Atrast lielāko skaitli, attēlot to uz ekrāna
// 3. Aizpildīt divdimensiju masīvu a[5][5] ar datiem. Attēlot to uz ekrāna
// 4. Lietotājs ievada simbola virkni. Saskaitīt cik simbolu ‘a’ ir ievadītajā virknē, izdrukāt to uz ekrāna
// 5. Lietotājs ievada simbola virkni. Programma izņem no ievadītās virknes visus simbolus, kuri nav burti un izdrukā to uz ekrāna

#include <iostream>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::setw;
using std::string;

void firstTask()
{
    int n = 10;
    int arr[n];
    for (auto &i : arr)
    {
        cin >> i;
    }

    int sum = 0;
    for (auto &i : arr)
    {
        sum += i;
    }
    cout << (double)sum / n << endl;

    return;
}

void secondTask()
{
    int n = 10;
    double arr[n];
    for (auto &i : arr)
    {
        cin >> i;
    }

    double biggest = INT_MIN;
    for (auto &i : arr)
    {
        biggest = max(biggest, i);
    }
    cout << biggest << endl;
    return;
}

void thirdTask()
{
    int n = 5;
    int matrix[n][n];
    for (auto &i : matrix)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
    for (auto &i : matrix)
    {
        for (auto &j : i)
        {
            cout << setw(3) << j;
        }
        cout << endl;
    }

    return;
}

void fourthTask()
{
    string str;
    cin >> str;
    int res = 0;
    for (auto &i : str)
    {
        if (i == 'a')
        {
            ++res;
        }
    }
    cout << res << endl;

    return;
}

void fifthTask()
{
    string str;
    cin >> str;
    for (auto &i : str)
    {
        if (!(i >= 'a' && i <= 'z') && !(i >= 'A' && i <= 'Z'))
        {
            cout << i;
        }
    }
    cout << endl;

    return;
}

int main()
{
    int ok = 1;
    do
    {
        int program_id;
        cout << "Choose program: ";
        cin >> program_id;

        switch (program_id)
        {
        case 1:
            firstTask();
            break;
        case 2:
            secondTask();
            break;
        case 3:
            thirdTask();
            break;
        case 4:
            fourthTask();
            break;
        case 5:
            fifthTask();
            break;
        default:
            ok = 0;
            break;
        }
    } while (ok);

    return 0;
}