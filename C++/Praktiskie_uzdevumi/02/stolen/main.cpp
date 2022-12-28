#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

enum menu {insertMenu = 1, queueMenu, stackMenu, twoStacksMenu, dequeMenu, vectorMenu, endMenu};

void Sakums() {
    cout << endl << endl
        << "Ievadīt ciparu no 1 līdz 7" << endl
        << "1: Ievadīt skaitļus" << endl
        << "2: Rinda" << endl
        << "3. Steks" << endl
        << "4. Divi steki (Rinda)" << endl
        << "5. Indeksētas divvirzienu rindas" << endl
        << "6. Izvada skaitļu virkni" << endl
        << "7. Beigt darbību" << endl << endl;
}

void Case1(vector<int>& vecNum) {
    int vecInput;
    vecNum.clear();
    
    cout << "Ievadiet skaitļus (0, lai beigtu ievadi): " << endl;
                        
    while ((cin >> vecInput) && vecInput != 0) {
        vecNum.push_back(vecInput);
    }
                        
    cout << endl << "Ievadītie skaitļi: ";
    for (int i = 0; i < vecNum.size(); i++) {
        cout << vecNum[i] << " ";
    }

    Sakums();
}

void Case2(vector<int> vecNum) {
    queue<int> vecToQueue;
    for (int i = 0; i < (int)vecNum.size(); i++) {
        vecToQueue.push(vecNum[i]);
    }

    cout << endl << "Rindas skaitļi: ";
    while (!vecToQueue.empty()) {
        cout << vecToQueue.front() << " ";
        vecToQueue.pop();
    }

    Sakums();
}

void Case3(vector<int> vecNum) {
    stack<int> vecToStack;
    for (int i = 0; i < (int)vecNum.size(); i++) {
        vecToStack.push(vecNum[i]);
    }

    cout << endl << "Steka skaitļi: ";
    while (!vecToStack.empty()) {
        cout << vecToStack.top() << " ";
        vecToStack.pop();
    }

    Sakums();
}

void Case4(vector<int> vecNum) {
    stack<int> vecFirstStack;
    stack<int> vecSecondStack;
    
    for (int i = 0; i < (int)vecNum.size(); i++) {
        vecFirstStack.push(vecNum[i]);
    }

    while (!vecFirstStack.empty()) {
        vecSecondStack.push(vecFirstStack.top());
        vecFirstStack.pop();
    }

    cout << endl << "Skaitļi otrajā stekā: " ;

    while (!vecSecondStack.empty()) {
        cout << vecSecondStack.top() << " ";
        vecSecondStack.pop();
    }

    Sakums();
}

void Case5(vector<int> vecNum) {
    deque<int> constumSTL;
    int insertFront, insertBack;

    for (int i = 0; i < (int)vecNum.size(); i++) {
        constumSTL.push_back(vecNum[i]);
    }

    cout << "Ievadiet skaitli, ko pievienot rindas sākumā: ";
    cin >> insertFront;
    constumSTL.push_front(insertFront);

    cout << "Ievadiet skaitli, ko pievienot rindas beigās: ";
    cin >> insertBack;
    constumSTL.push_back(insertBack);

    cout << endl << "Indeksētas divvirzienu rinda: ";
                        
    while (!constumSTL.empty()) {
        cout << constumSTL.front() << " ";
        constumSTL.pop_front();
    }

    Sakums();
}

void Case6(vector<int> vecNum) {
    cout << endl << "Vektora skaitļi: ";
    for (int i = 0; i < vecNum.size(); i++) {
        cout << vecNum[i] << " ";
    }

    Sakums();
}

int main() {
    vector<int> vecNum = {4, 5, 6, 7, 8};

    Sakums();

    int input;

    while (input != 7) {
        cin >> input;
        switch (input) {
            case insertMenu: 
                Case1(vecNum);
                continue;

            case queueMenu: 
                Case2(vecNum);
                continue;

            case stackMenu: 
                Case3(vecNum);
                continue;

            case twoStacksMenu: 
                Case4(vecNum);
                continue;
                    
            case dequeMenu:
                Case5(vecNum);
                continue;

            case vectorMenu:
                Case6(vecNum);
                continue;
                    
            case endMenu:
                cout<<"Exiting";
                break;
                    
            default:{
                if (input > 7 || input < 1) {
                    cout << "Error! Ievadīt skaitli no 1 līdz 7" << endl;
                    continue;
                }
            }
        }           
    }

    return 0;
}