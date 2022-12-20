#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::setw;
using std::vector;

bool isPrime(int &x)
{
    if (x <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= x; ++i)
    {
        if (!(x % i))
        {
            return false;
        }
    }
    return true;
}

vector<bool> SieveOfEratosthenes(const int &len)
{
    vector<bool> isPrime(len, 1);
    isPrime[0] = isPrime[1] = true;

    for (int i = 2; i * i <= len; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= len; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

void firstTask()
{
    cout << "Enter a number: ";
    int x;
    cin >> x;

    cout << "Number is" << (isPrime(x) ? " " : " not ") << "prime!" << endl;

    for (int i = 1, j = 1;; ++i)
    {
        if (isPrime(i))
        {
            ++j;
        }
        if (j == x)
        {
            cout << x << "'th prime number is " << i << endl;
            break;
        }
    }

    cout << "All pairs whose sum is " << x << ":" << endl;
    vector<bool> isPrime = SieveOfEratosthenes(x);
    bool found = false;
    for (int i = 2; i * 2 <= x; ++i)
    {
        if (isPrime[i] && isPrime[x - i])
        {
            found = true;
            cout << i << " " << x - i << endl;
        }
    }
    if (!found)
    {
        cout << 0 << endl;
    }

    cout << "All pairs whose product is " << x << ":" << endl;
    vector<int> primes;
    for (int i = 0; i < x; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
    found = false;
    for (int i = 0, j = primes.size() - 1; i <= j;)
    {
        if (primes[i] * primes[j] == x)
        {
            found = true;
            cout << primes[i] << " " << primes[j] << endl;
            --j;
        }
        else if (primes[i] * primes[j] > x)
        {
            --j;
        }
        else
        {
            ++i;
        }
    }
    if (!found)
    {
        cout << 0 << endl;
    }

    return;
}

void secondTask()
{
    cout << "Enter x, y length: ";
    double x, y;
    cin >> x >> y;

    cout << "Perimeter - " << x * 2 + y * 2 << endl
         << "Area - " << x * y << endl;

    for (int i = 0; i < (int)x; ++i)
    {
        for (int j = 0; j < (int)y; ++j)
        {
            if (!i || !j || i == (int)x - 1 || j == (int)y - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << "Rectangle center position (x, y): ";
    int pos_x, pos_y;
    cin >> pos_x >> pos_y;
    cout << "Rectangle edge positions:" << endl
         << "(" << pos_x - (x / 2) << "," << pos_y + (y / 2) << ")(" << pos_x + (x / 2) << "," << pos_y + (y / 2) << ")" << endl
         << "(" << pos_x - (x / 2) << "," << pos_y - (y / 2) << ")(" << pos_x + (x / 2) << "," << pos_y - (y / 2) << ")" << endl;

    cout << "Enter point a position (x, y): ";
    int a_x, a_y;
    cin >> a_x >> a_y;
    if (a_x >= pos_x - (x / 2) && a_x <= pos_x + (x / 2) && a_y >= pos_y - (y / 2) && a_y <= pos_y + (y / 2))
    {
        cout << "Point is in rectangle!" << endl;
    }
    else
    {
        cout << "Point is not in rectanle!" << endl;
    }

    return;
}

void thirdTask()
{
    cout << "Enter an integer: ";
    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!(i % 3) || !(i % 5))
        {
            res += i;
        }
    }
    cout << "Sum of numbers that divide by 3 or 5 is " << res << endl;

    cout << "Sum of number from 1 to n is " << (n * (n + 1)) / 2 << endl;

    res = 1;
    for (int i = 1; i < n; ++i)
    {
        res *= i;
    }
    cout << "Factorial n is " << res << endl;

    cout << "Enter integer: ";
    cin >> n;
    res = 0;
    while (n > 0)
    {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    cout << "Integer digit square sum is " << res << endl;

    return;
}

void fourthTask()
{
    cout << "Enter an integer: ";
    int x;
    cin >> x;

    int res = 0, temp = x;
    while (temp)
    {
        res *= 10;
        res += temp % 10;
        temp /= 10;
    }
    cout << "Reversed number is " << res << endl;

    int biggest_digit = 0;
    temp = x;
    while (temp)
    {
        biggest_digit = max(biggest_digit, temp % 10);
        temp /= 10;
    }
    cout << "Biggest digit in number is " << biggest_digit << endl;

    temp = x;
    res = 0;
    int power = 1;
    while (temp)
    {
        if ((temp % 10) & 1)
        {
            res += (temp % 10) * power;
            power *= 10;
        }
        temp /= 10;
    }
    cout << "Number with removed even digits is " << res << endl;

    return;
}

void fifthTask()
{
    cout << "Enter two integers: ";
    int number, range;
    cin >> number >> range;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i <= range; ++i)
    {
        if (i & 1)
        {
            SetConsoleTextAttribute(hConsole, 12);
        }
        cout << number;
        SetConsoleTextAttribute(hConsole, 15);
        cout << setw(3) << "*";
        if (!(i & 1))
        {
            SetConsoleTextAttribute(hConsole, 9);
        }
        cout << setw(4) << i;
        SetConsoleTextAttribute(hConsole, 15);
        cout << setw(4) << "=" ;
        SetConsoleTextAttribute(hConsole, 14);
        cout << setw(4) << number * i << endl;
        SetConsoleTextAttribute(hConsole, 15);
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