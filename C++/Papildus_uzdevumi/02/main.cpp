// 1. Ir dots skaitļu masīvs ar 10 elementiem. Aprēķināt skaitļu grupas vidējo vērtību
// 2. Ir dots skaitļu masīvs ar 10 elementiem (float tipa). Atrast lielāko skaitli, attēlot to uz ekrāna
// 3. Aizpildīt divdimensiju masīvu a[5][5] ar datiem. Attēlot to uz ekrāna
// 4. Lietotājs ievada simbola virkni. Saskaitīt cik simbolu ‘a’ ir ievadītajā virknē, izdrukāt to uz ekrāna
// 5. Lietotājs ievada simbola virkni. Programma izņem no ievadītās virknes visus simbolus, kuri nav burti un izdrukā to uz ekrāna

// 1.1. Ņem vērā tikai pāra skaitļus vidējo vērtību aprēķināšanai
// 1.2. Atrast 3 lielākos skaitļus masīvā
// 1.3. Atrast 3 mazākos skaitļus masīvā
// 2.1. Atrast mazāko skaitli
// 2.2. Atrast vidējo skaitli
// 2.3. Atrast otru mazāko skaitli
// 3.1. Atrast un izdrukāt uz ekrāna tos masīva skaitļus, kuri ir veseli (aiz komata nav ciparu)
// 3.2. Atrast 5 mazākos skaitļus masīvā
// 3.3. Atrast 5 lielākos skaitļus masīvā
// 4.1. Saskaiti cik virknē ir 'aa' burtu virknējumu. Piemēram, aab - 1, aaab - 2, utt
// 4.2. Izdrukāt burta ‘a’ indeksus masīvā. Piemēram, virkne: ‘ababaab’. Rezultāts: 1 3 5 6
// 4.3. Izdzēst visus burtus, kuriem ASCII kods ir nepāra skaitlis
// 5.1. Mazos burtus pārvērst par lielajiem un pretēji
// 5.2. Katra vārda pirmo burtu aizstāj ar lielo burtu, ja tas ir sācies ar mazo burtu, ja jau ir lielais burts, tad nevajag neko darīt.
// 5.3. Atrod otru garāko vārdu simbola virknē

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::max;
using std::setw;
using std::sort;
using std::string;
using std::vector;

void firstTask()
{
    cout << "Enter ten integers:";
    int n = 10;
    int arr[n];
    for (auto &i : arr)
    {
        cin >> i;
    }

    int sum = 0;
    for (const auto &i : arr)
    {
        sum += i;
    }
    cout << "Average value is " << (double)sum / n << endl;

    sum = 0;
    int even_count = 0;
    for (const auto &i : arr)
    {
        if ((i & 1) == 0)
        {
            ++even_count;
            sum += i;
        }
    }
    cout << "Average value of even numbers is " << (double)sum / even_count << endl;

    sort(arr, arr + 10);
    cout << "Three biggest elements are "
         << arr[9] << " " << arr[8] << " " << arr[7] << endl;

    cout << "Three smallest elements are "
         << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    return;
}

void secondTask()
{
    cout << "Enter ten floating point numbers: ";
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
    cout << "Biggest value is " << biggest << endl;

    sort(arr, arr + 10);
    cout << "Smallest value is " << arr[0] << endl;

    cout << "Middle value is " << arr[4] << endl;

    cout << "Second smallest value is " << arr[1] << endl;

    return;
}

void thirdTask()
{
    int n = 5;
    double matrix[n][n];
    for (auto &i : matrix)
    {
        cout << "Enter 5 numbers: ";
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

    cout << "Round numbers: ";
    for (auto &i : matrix)
    {
        for (auto &j : i)
        {
            if ((int)j == j)
            {
                cout << j << " ";
            }
        }
    }
    cout << endl;

    vector<int> arr;
    for (auto &i : matrix)
    {
        for (const auto &j : i)
        {
            arr.push_back(j);
        }
    }
    sort(arr.begin(), arr.end());
    cout << "5 Smallest elements in matrix: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "5 Smallest elements in matrix: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[arr.size() - i - 1] << " ";
    }
    cout << endl;

    return;
}

void fourthTask()
{
    cout << "Enter a string: ";
    string str;
    cin.ignore();
    getline(cin, str);
    int res = 0;
    for (auto &i : str)
    {
        if (i == 'a')
        {
            ++res;
        }
    }
    cout << "There are " << res << " occurences of 'a' in string" << endl;

    int ans = 0;
    for (int i = 0, a_count = 0; i < str.length(); ++i)
    {
        if (str[i] == 'a')
        {
            ++a_count;
            if (a_count > 1)
            {
                ++ans;
            }
        }
        else
        {
            a_count = 0;
        }
    }
    cout << "There are " << ans << " occurences of 'aa' in string." << endl;

    string temp = "";
    for (const auto &i : str)
    {
        if (i % 2 == 0)
        {
            temp.push_back(i);
        }
    }
    str = temp;
    cout << "String with removed elements that have odd ascii code: " << endl
         << str << endl;
    return;
}

void fifthTask()
{
    cout << "Enter a string: " << endl;
    string str;
    cin.ignore();
    getline(cin, str);
    string res = "";
    for (const auto &i : str)
    {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
        {
            res.push_back(i);
        }
    }
    cout << "String with only letters: " << res << endl;

    string ans = str;
    for (auto &i : ans)
    {
        if (i >= 'A' && i <= 'Z')
        {
            i += 32;
        }
        else
        {
            i -= 32;
        }
    }
    cout << "String with big and small letters swaped: " << ans << endl;

    istringstream ss(str);
    string temp;
    cout << "String with capitalized words: ";
    while (ss >> temp)
    {
        if (temp[0] >= 'a' && temp[0] <= 'z')
        {
            temp[0] -= 32;
        }
        cout << temp << " ";
    }
    cout << endl;

    ss.clear();
    ss.str(str);
    vector<string> arr;
    while (ss >> temp)
    {
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), [](const string &lhs, const string &rhs)
         { return lhs.length() > rhs.length(); });
    if ((int)arr.size() > 1)
    {
        cout << "Second longest word in string: " << arr[1] << endl;
    }

    return;
}

int main()
{
    int ok = 1;
    do
    {
        int program_id;
        cout << "Choose program (1 - 5): ";
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