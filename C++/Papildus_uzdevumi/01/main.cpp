#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::setw;
using std::endl;

bool isPrime(int &x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (!(x % i))
        {
            return false;
        }
    }
    return true;
}

void firstTask()
{
    int x;
    cin >> x;
    cout << "Number is" << (isPrime(x) ? " " : " not ") << "prime!" << endl;

    return;
}

void secondTask()
{
    double x, y;
    cin >> x >> y;
    cout << "Perimeter - " << x * 2 + y * 2 << endl
         << "Area - " << x * y << endl;

    return;
}

void thirdTask()
{
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
    cout << "Sum of numbers - " << res << endl;

    return;
}

void fourthTask()
{
    int x;
    cin >> x;
    int res = 0;
    while (x)
    {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    cout << res << endl;

    return;
}

void fifthTask()
{
    int number, range;
    cin >> number >> range;
    for (int i = 0; i <= range; ++i)
    {
        cout << number << setw(3) << "*" << setw(4) << i << setw(4) << "=" << setw(4) << number * i << endl;
    }

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