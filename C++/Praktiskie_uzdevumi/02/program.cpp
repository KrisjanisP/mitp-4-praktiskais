#include "header.hpp"
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define F first
#define S second

using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::greater;
using std::map;
using std::max;
using std::multiset;
using std::numeric_limits;
using std::queue;
using std::set;
using std::stack;
using std::streamsize;
using std::string;
using std::vector;

namespace MI_Utils
{
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

    void first(vector<double> &vector)
    {
        int n = get_number("Enter vector size: ");
        vector.resize(n);
        cout << "Enter " << n << " numbers: ";
        for (auto &i : vector)
        {
            i = get_number();
        }

        return;
    }

    void second(const vector<double> &vector)
    {
        queue<double> queue;
        for (const auto &i : vector)
        {
            queue.push(i);
        }
        cout << "Elements after being added and removed from queue: ";
        while (!queue.empty())
        {
            cout << queue.front() << " ";
            queue.pop();
        }
        cout << endl;

        return;
    }

    void third(const vector<double> &vector)
    {
        stack<double> stack;
        for (const auto &i : vector)
        {
            stack.push(i);
        }
        cout << "Elements after being added and removed from stack: ";
        while (!stack.empty())
        {
            cout << stack.top() << " ";
            stack.pop();
        }
        cout << endl;

        return;
    }

    void fourth(const vector<double> &vector)
    {
        stack<double> stack, stack_2;
        for (const auto &i : vector)
        {
            stack.push(i);
        }
        while (!stack.empty())
        {
            stack_2.push(stack.top());
            stack.pop();
        }
        cout << "Elements after being added and removed from two stacks: ";
        while (!stack_2.empty())
        {
            cout << stack_2.top() << " ";
            stack_2.pop();
        }
        cout << endl;

        return;
    }

    void fifth(const vector<double> &vector)
    {
        set<double> set;
        for (const auto &i : vector)
        {
            set.insert(i);
        }
        cout << "Elements after being added to set and iterated through: ";
        for (const auto &i : set)
        {
            cout << i << " ";
        }
        cout << endl;

        return;
    }

    void sixth(const vector<double> &vector)
    {
        cout << "Numbers in vector: ";
        for (const auto &i : vector)
        {
            cout << i << " ";
        }
        cout << endl;

        return;
    }

    void eighth(const vector<double> &vector)
    {
        static map<double, string> map;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (const auto &i : vector)
        {
            if (map.find(i) == map.end())
            {
                cout << "Enter alias to use for vector value " << i << ": " << flush;
                string temp;
                getline(cin, temp);
                map[i] = temp;
            }
        }

        set<double> temp(vector.begin(), vector.end());
        for (const auto &i : map)
        {
            if (temp.find(i.F) == temp.end())
            {
                map.erase(i.F);
            }
        }

        int value = get_number("Enter value which alias to lookup: ");
        if (map.find(value) != map.end())
        {
            cout << "Alias of value: " << map[value] << endl;
        }
        else
        {
            cout << "Alias of value not found!" << endl;
        }

        return;
    }

    void ninth()
    {
        cout << "------------------------------------------------------------------------------------" << endl
             << "This problem was taken from task fare_gatis (https://clevercode.lv/task/show/fare_gatis)." << endl
             << "It allows getting overlapping area of rectangles after adding or removing them!" << endl
             << "------------------------------------------------------------------------------------" << endl;

        multiset<double, greater<double>> left_multiset, bottom_multiset;
        multiset<double> right_multiset, top_multiset;
        int operation_count = (int)get_number("Enter operation count: ");
        cout << "Operations have to given in format [+-] [bottom left x y] [top right x y]!" << endl
             << "Example: + 1 5 8 10" << endl;
        for (int i = 1; i <= operation_count; ++i)
        {
            cout << "Operation " << i << ": ";
            char operation;
            cin >> operation;
            double bottom = get_number(), left = get_number(), top = get_number(), right = get_number();
            if (operation == '+')
            {
                left_multiset.insert(left);
                bottom_multiset.insert(bottom);
                right_multiset.insert(right);
                top_multiset.insert(top);
            }
            else if (operation == '-')
            {
                if (left_multiset.find(left) == left_multiset.end() ||
                    bottom_multiset.find(bottom) == bottom_multiset.end() ||
                    right_multiset.find(right) == right_multiset.end() ||
                    top_multiset.find(top) == top_multiset.end())
                {
                    cout << "Rectangle doesn't exist!" << endl;
                    --i;
                    continue;
                }
                else
                {
                    left_multiset.erase(left_multiset.find(left));
                    bottom_multiset.erase(bottom_multiset.find(bottom));
                    right_multiset.erase(right_multiset.find(right));
                    top_multiset.erase(top_multiset.find(top));
                }
            }
            else
            {
                cout << "Invalid operation!" << endl;
                --i;
                continue;
            }

            double l = *left_multiset.begin();
            double b = *bottom_multiset.begin();
            double r = *right_multiset.begin();
            double t = *top_multiset.begin();
            cout << "Overlapping size: " << (b >= t || l >= r ? 0 : (t - b) * (r - l)) << endl;
        }
    }
}
