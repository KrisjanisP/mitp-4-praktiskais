// PS > g++ main.cpp; ./a.exe

// Izveidot C++ programmā funkcijas:
// Lietotājs ievada simbola virkni. Izveidot funkciju, kas apgriež simbola virkni pretējā secībā
// Lietotājs ievada skaitli n. Izveidot funkciju, kas rekursīvi aprēķina summu no 1..n
// Izveidot 4 funkcijas ar vienādu nosaukumu Print, kuras uz ekrāna izdrukā padoto vērtību sekojošiem datu tipiem: int, string, double, char.
// Izveidot funkciju Min, kura atgriež minimālo elementu no 2 padotajiem. Datu tips var būt dažāds funkciju izmantojot.
// Izveidot kalkulatoru. Programma lietotājam prasa ievadīt 2 skaitļus un operāciju. Atkarībā no perācijas (+, -, *,  /) izsauc atbilstošo funkciju un attēlo rezultātu.

// 1.1. Lietotājs ievada vēl vienu virkni, kuru saglabā char masīvā. Izveidot jaunu funkciju, kas apgriež simbola virkni pretējā secībā (kā parametrs funkcijai tiek padots char masīvs).
// 1.2-3. Izveidot izvēlni:
//     1: Ievada string virkni
//     2: Ievada char masīvu
//     3: Reverse funkcija
//     4: Izvadīt uz ekrānas virkni
//     5: Beigt programmu
// Piezīme: 3, 4 operācija tiek izpildīta ar to simbola virknes veidu, kura ir bijusi ievadīta pēdējā
// 2.1. Izveidot rekursīvu funkciju, kura saskaita ievadītā skaitļa ciparu summu. Piemēram, ievadīt 35; rezultāts - 8 (3+5)
// 2.2. Izveidot rekursīvu funkciju, kura pasaka cik ciparu ir ievadītajā skaitlī, Piemēram, 35; rezultārs - 2
// 2.3. Izveidot izvēlni:
//     1: Skaitļa ievade
//     2: Summa
//     3: Ciparu summa
//     4: Cik cipari skaitlī
//     5: Beigt darbu
// 3.1. Sataisīt korektu izvēlni pēc līdzības iepriekšējiem uzdevumiem - lai lietotājs saprot, kas viņam ir jāievada un kas tiek izdrukāts
// 3.2-3.3. Izveidot papildus Print funkcijas vektora (vector), saraksta (list), steka (stack) un rindas (queue) objektiem
// 4.1. Izveidot tādu pašu realizāciju funkcijai Max
// 4.2. Izveidot tādu pašu realizāciju funkcijai Avg (average - vidējā vērtība)
// 4.3. Pielikt papildus objektu Vector, kurā lietotājs var ievadīt nenosakāmi daudz elementus. Arī uz šo Vector objektu var izsaukt Min, Max un Avg funkcijas
// 5.1-3. Ir dota simbolu virne: “2+5*3-4”. Programmai jāaprēķina rezultāts. Lietotājam ir iespēja ievadīt simbola virkni arī programmas darbības laikā.

#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

double get_number(const string msg);

void first();
void second();
void third();
void fourth();
void fifth();

int main()
{
    SetConsoleOutputCP(65001);

    cout << "1: Reverse string" << endl
         << "2: Recursive sum" << endl
         << "3. Overloading" << endl
         << "4. Template " << endl
         << "5. Calculator" << endl
         << "6. End program" << endl;

    bool ok = true;
    do
    {
        const int choice = (int)get_number("Choice: ");
        switch (choice)
        {
        case 1:
            first();
            break;
        case 2:
            second();
            break;
        case 3:
            third();
            break;
        case 4:
            fourth();
            break;
        case 5:
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

string reverseString(const string &str)
{
    string ans = "";
    for (auto i = str.rbegin(); i != str.rend(); ++i)
    {
        ans += *i;
    }
    return ans;
}

char *reverseString(const char *str)
{
    const int LEN = strlen(str);
    char *ans = new char[LEN + 1];
    ans[LEN] = '\0';
    for (int i = 0; str[i]; ++i)
    {
        ans[LEN - i - 1] = str[i];
    }
    return ans;
}

void first()
{
    cout << " Enter a high level string: ";
    string str;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);
    cout << " Reversed string: " << reverseString(str) << endl;

    const int LEN = 10000;
    cout << " Enter a low level string: ";
    char *low_str = new char[LEN];
    cin.getline(low_str, LEN);
    cout << " Reversed string: " << (low_str = reverseString(low_str)) << endl;

    cout << endl
         << " 1: Enter string" << endl
         << "2: Enter char array" << endl
         << " 3. Reverse" << endl
         << " 4. Print" << endl
         << " 5. End" << endl
         << endl;
    bool ok = true, last_input = false;
    do
    {
        const int choice = (int)get_number(" Choice: ");
        switch (choice)
        {
        case 1:
            cout << " Enter: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, str);
            last_input = true;
            break;
        case 2:
            cout << " Enter: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(low_str, LEN);
            last_input = false;
            break;
        case 3:
            if (last_input)
            {
                str = reverseString(str);
            }
            else
            {
                low_str = reverseString(low_str);
            }
            break;
        case 4:
            if (last_input)
            {
                cout << " String: " << str << endl;
            }
            else
            {
                cout << " Char array: " << low_str << endl;
            }
            break;
        case 5:
            ok = false;
            break;
        default:
            break;
        }
    } while (ok);

    delete[] low_str;

    return;
}

int sum(int x)
{
    if (x)
    {
        return x + sum(x - 1);
    }

    return 0;
}

int digit_sum(int x)
{
    return x % 10 + (x ? digit_sum(x / 10) : 0);
}

int digit_count(int x)
{
    return (x ? digit_count(x / 10) + 1 : 0);
}

void second()
{
    int n = (int)get_number(" Enter an integer: ");
    cout << " Sum of numbers from 1 to " << n << ": " << sum(n) << endl;

    cout << endl
         << " 1: Enter an integer" << endl
         << " 2: Sum of numbers from 1 to integer" << endl
         << " 3. Digit sum" << endl
         << " 4. Digit count" << endl
         << " 5. End" << endl
         << endl;
    bool ok = true;
    do
    {
        const int choice = (int)get_number(" Choice: ");
        switch (choice)
        {
        case 1:
            n = (int)get_number(" Enter an integer: ");
            break;
        case 2:
            cout << " Sum of numbers from 1 to " << n << ": " << sum(n) << endl;
            break;
        case 3:
            cout << " Digit sum of n is " << digit_sum(n) << endl;
            break;
        case 4:
            cout << " Digit count of n is " << digit_count(n) << endl;
            break;
        case 5:
            ok = false;
            break;
        default:
            break;
        }
    } while (ok);

    return;
}

void print(const int &x)
{
    cout << " Integer: " << x << endl;
    return;
}

void print(const double &x)
{
    cout << " Double: " << x << endl;
    return;
}

void print(const string &x)
{
    cout << " String: " << x << endl;
    return;
}

void print(const char &x)
{
    cout << " Char: " << x << endl;
    return;
}

void print(const vector<int> &vector)
{
    cout << " Vector elements: ";
    for (const auto &i : vector)
    {
        cout << i << " ";
    }
    cout << endl;
    return;
}

void print(const list<int> &list)
{
    cout << " Linked list elements: ";
    for (const auto &i : list)
    {
        cout << i << " ";
    }
    cout << endl;
    return;
}

void print(stack<int> stack)
{
    cout << " Stack elements: ";
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    return;
}

void print(queue<int> queue)
{
    cout << " Queue elements: ";
    while (!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
    return;
}

void third()
{
    int i = (int)get_number(" Enter an integer: ");

    double d = get_number(" Enter a floating point number: ");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << " Enter a string: ";
    string s;
    getline(cin, s);

    cout << " Enter a char: ";
    char c;
    cin >> c;

    print(i);
    print(d);
    print(s);
    print(c);

    cout << endl
         << " 1: Vector" << endl
         << " 2: Linked list" << endl
         << " 3. Stack" << endl
         << " 4. Queue" << endl
         << " 5. End" << endl
         << endl;
    bool ok = true;
    do
    {
        const int choice = (int)get_number(" Choice: ");
        switch (choice)
        {
        case 1:
        {
            int len = (int)get_number(" Vector size: ");
            vector<int> vector(len);
            cout << " Enter " << len << " integers: ";
            for (auto &i : vector)
            {
                i = (int)get_number();
            }
            print(vector);
            break;
        }
        case 2:
        {
            int len = (int)get_number(" Linked list size: ");
            list<int> list(len);
            cout << " Enter " << len << " integers: ";
            for (auto &i : list)
            {
                i = (int)get_number();
            }
            print(list);
            break;
        }
        case 3:
        {
            int len = (int)get_number(" Stack size: ");
            stack<int> stack;
            cout << " Enter " << len << " integers: ";
            while (len--)
            {
                stack.push((int)get_number());
            }
            print(stack);
            break;
        }
        case 4:
        {
            int len = (int)get_number(" Queue size: ");
            queue<int> queue;
            cout << " Enter " << len << " integers: ";
            while (len--)
            {
                queue.push((int)get_number());
            }
            print(queue);
            break;
        }
        case 5:
            ok = false;
            break;
        default:
            break;
        }
    } while (ok);

    return;
}

template <typename T>
T Min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

template <typename T>
T Max(const T &a, const T &b)
{
    return (a > b ? a : b);
}

template <typename T>
double Avg(const T &a, const T &b)
{
    return (double)(a + b) / 2;
}

template <typename T>
T Min(vector<T> &vector)
{
    if (vector.empty())
    {
        return MAXINT;
    }
    T lst = vector.back();
    vector.pop_back();
    T ans = Min(lst, Min(vector));
    vector.push_back(lst);
    return ans;
}

template <typename T>
T Max(vector<T> &vector)
{
    if (vector.empty())
    {
        return MININT;
    }
    T lst = vector.back();
    vector.pop_back();
    T ans = Max(lst, Max(vector));
    vector.push_back(lst);
    return ans;
}

template <typename T>
double Avg(vector<T> &vector)
{
    if (vector.empty())
    {
        return 0;
    }
    T lst = vector.back();
    vector.pop_back();
    double ans = (lst + Avg(vector) * vector.size()) / (vector.size() + 1);
    vector.push_back(lst);
    return ans;
}

void fourth()
{
    int i = (int)get_number(" Enter an integer: ");
    int ii = (int)get_number(" Enter an integer: ");

    double d = get_number(" Enter a floating point number: ");
    double dd = get_number(" Enter a floating point number: ");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << " Enter a string: ";
    string s;
    getline(cin, s);
    cout << " Enter a string: ";
    string ss;
    getline(cin, ss);

    cout << " Enter a char: ";
    char c;
    cin >> c;
    cout << " Enter a char: ";
    char cc;
    cin >> cc;

    cout << " Smallest integer: " << Min(i, ii) << endl
         << " Smallest floating point number: " << Min(d, dd) << endl
         << " Smallest string: " << Min(s, ss) << endl
         << " Smallest char: " << Min(c, cc) << endl;

    const int len = (int)get_number(" Enter vector size: ");
    vector<int> vector_d(len);
    cout << " Enter " << len << " integers: ";
    for (auto &i : vector_d)
    {
        i = get_number();
    }
    cout << " Smallest value: " << Min(vector_d) << endl
         << " Biggest value: " << Max(vector_d) << endl
         << " Average value: " << Avg(vector_d) << endl;
    cout << " Enter " << len << " numbers: ";
    for (auto &i : vector_d)
    {
        i = (int)get_number();
    }
    cout << " Smallest value: " << Min(vector_d) << endl
         << " Biggest value: " << Max(vector_d) << endl
         << " Average value: " << Avg(vector_d) << endl;

    return;
}

string shuntingYardAlgorithm(const string &equation)
{
    string ans = "";
    map<char, int> op_precedence({{'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}, {'^', 4}});
    map<char, bool> op_associativity({{'+', 1}, {'-', 1}, {'*', 1}, {'/', 1}, {'^', 0}});
    stack<char> op_stack;

    for (auto i = equation.begin(); i != equation.end(); ++i)
    {
        if ((*i >= '0' && *i <= '9') || *i == '.')
        {
            while ((*i >= '0' && *i <= '9') || *i == '.')
            {
                ans.push_back(*i);
                ++i;
            }
            ans.push_back(' ');

            if (i == equation.end())
            {
                break;
            }
        }

        if (*i == '(')
        {
            op_stack.push(*i);
        }
        else if (*i == ')')
        {
            while (op_stack.top() != '(')
            {
                ans = ans + op_stack.top() + ' ';
                op_stack.pop();

                //! Invalid expresion
                if (op_stack.empty())
                {
                    return "0";
                }
            }
            op_stack.pop();
        }
        else if (op_precedence.count(*i))
        {
            while (!op_stack.empty() && (op_precedence[*i] < op_precedence[op_stack.top()] ||
                                         (op_precedence[*i] == op_precedence[op_stack.top()] &&
                                          op_associativity[*i])))
            {
                ans = ans + op_stack.top() + ' ';
                op_stack.pop();
            }
            op_stack.push(*i);
        }
    }

    while (!op_stack.empty())
    {
        ans = ans + op_stack.top() + ' ';
        op_stack.pop();
    }
    ans.pop_back();

    return ans;
}

double evaluateReversePolishNotation(const string &equation)
{
    stack<double> operand_stack;

    for (int i = 0; i < equation.length(); i += 2)
    {
        if ((equation[i] >= '0' && equation[i] <= '9') || equation[i] == '.')
        {
            int j = 1;
            while ((equation[i + j] >= '0' && equation[i + j] <= '9') || equation[i + j] == '.')
            {
                ++j;
            }

            //! Invalid expression
            try
            {
                operand_stack.push(stod(equation.substr(i, j)));
            }
            catch (invalid_argument)
            {
                return 1;
            }

            i += j - 1;
        }
        else
        {
            //! Invalid expression
            if (operand_stack.size() < 2)
            {
                return 2;
            }
            double a, b, ab;
            b = operand_stack.top();
            operand_stack.pop();
            a = operand_stack.top();
            operand_stack.pop();
            switch ((int)equation[i])
            {
            case '+':
            {
                ab = a + b;
                break;
            }
            case '-':
            {
                ab = a - b;
                break;
            }
            case '*':
            {
                ab = a * b;
                break;
            }
            case '/':
            {
                //! Invalid expression
                if (b == 0)
                {
                    return 3;
                }
                ab = a / b;
                break;
            }
            case '^':
            {
                ab = pow(a, b);
                break;
            }
            }
            operand_stack.push(ab);
        }
    }

    return operand_stack.top();
}

void fifth()
{
    cout << " Equation in format ([number] [+-*/] [number]): ";

    double a, b;
    a = get_number();
    char op;
    cin >> op;
    b = get_number();

    cout << " Result: ";
    switch ((int)op)
    {
    case '+':
        cout << a + b;
        break;
    case '-':
        cout << a - b;
        break;
    case '*':
        cout << a * b;
        break;
    case '/':
        if (b)
        {
            cout << a / b;
        }
        else
        {
            cout << " Can't divide by 0!";
        }
        break;
    default:
        cout << " Unsupported operator!";
        break;
    }
    cout << endl;

    cout << " ---------------------------------------------------------------------------------" << endl;
    cout << " Program will evaluate simple equation by converting it to Reverse" << endl
         << " Polish notation using Shunting yard algorithm and then parsing it." << endl
         << endl
         << " It won't be able to determine if expression is invalid!" << endl
         << " It won't work with negative numbers, but will work with floating points values!" << endl
         << endl
         << " Enter an equation (Example: '3.5 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3'): ";
    string equation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, equation);
    cout << " Equation in Reverse Polish notation: " << shuntingYardAlgorithm(equation) << "|" << endl;
    cout << " Evaluation: " << evaluateReversePolishNotation(shuntingYardAlgorithm(equation)) << endl;

    cout << " ---------------------------------------------------------------------------------" << endl;

    return;
}
