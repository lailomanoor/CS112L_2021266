#include <iostream>
using namespace std;

class temperature
{
    int t;

public:
    temperature()
    {
        t = 15;
    }

    ~temperature()
    {
        cout << "destructor called\n";
    }

    void warmer()
    {
        t += 5;
    }

    void cooler()
    {
        t -= 5;
    }

    void print()
    {
        cout << "temperature is: " << t << endl;
    }
};

int main()
{
    temperature t1;
    t1.print();
    int opt;

    do
    {
        cout << "enter 1-print the temperature,2-to call heater,3-to call cooler,4- to exit\n";
        cin >> opt;

        switch (opt)
        {
        case 1:
            t1.print();
            break;
        case 2:
            t1.warmer();
            t1.print();
            break;
        case 3:
            t1.cooler();
            t1.print();
            break;
        case 4:
            cout << "exiting...\n";
            break;
        default:
            cout << "wrong option\n";
        }
    } while (opt != 4);

    return 0;
}
