#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum eOptions{
    Input,
    Output,
    Sell,
    Search,
    MostSold,
    LeastSold,
    MostEarned,
    LeastEarned,
    MostExpensive,
    MostCheap,
    End
};

struct item{
    string name;
    double price;
    int available;
    int sold;
};

class Storage{
    private:
        vector<item> data;
        fstream file;

    public:
        Storage(){}
        virtual ~Storage(){}

        void add(){}
        void print(){}
        void sell(){}
        void search(){}
        void mostSold(){}
        void leastSold(){}
        void mostEarned(){}
        void leastEarned(){}
        void mostExpensive(){}
        void mostCheap(){}

        int menu(){
            cout << "/////" << endl;
            cout << "Izvelejaties opciju:" << endl;
            cout << "1 - Papildināt" << endl;
            cout << "2 - Izvadīt visas preces" << endl;
            cout << "3 - Pārdot preces" << endl;
            cout << "4 - Meklēt preci" << endl;
            cout << "5 - Top3 visvairāk iztirgotos produkti" << endl;
            cout << "6 - Top3 vismazāk iztirgotos produkti" << endl;
            cout << "7 - Top3 tie produkti, par kuriem ir visvairāk nopelnīts" << endl;
            cout << "8 - Top3 tie produkti, par kuriem ir vismazāk nopelnīts" << endl;
            cout << "9 - Top3 visdārgākie produkti" << endl;
            cout << "10 - Top3 vislētākie produkti" << endl;
            cout << "11 - Top3 beigt darbību" << endl;
            cout << "/////" << endl;
            int op;
            cout << "Jūsu opcija: ";
            cin >> op;
            return op;
        }
};

int main(){
    Storage storage;
    int op = 0;
    while(op!=11){
        op = storage.menu();
        switch(op-1){
            case(Input):
                break;
            case(Output):
                break;
            case(Sell):
                break;
            case(Search):
                break;
            case(MostSold):
                break;
            case(LeastEarned):
                break;
            case(MostExpensive):
                break;
            case(MostCheap):
                break;
            case(End):
                return 0;
            default:
                cout << "Nav tadas opcijas, lūdzu, izvelējaties citu." << endl;
        }
    }
}