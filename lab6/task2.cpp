#include <iostream>
using namespace std;

class Officer
{
    
    static int count;

public:
    void check(int ID)
    {
        int tempID = ID, reverseID = 0;
        while (tempID)
        {
            reverseID = reverseID * 10 + tempID % 10;
            tempID /= 10;
        }

        if (reverseID == ID)
        {
            cout << "Entry allowed\n";
            count++;
        }

        else
            cout << "Entry not allowed\n";
    }

    static int getcount()
    {
        return count;
    }
};

int Officer::count = 0;

int main()
{
    Officer o1;
    int opt, id;
    while (1)
    {
        cout << "Enter:\n1-To check if entry is allowed\n2-To see how many officers have entered\n3-To exit\n";
        cin >> opt;

        if (opt == 1)
        {
            cout << "enter ID of officer\n";
            cin >> id;
            o1.check(id);
        }

        if (opt == 2)
            cout << "the number of officers who entered is: " << o1.getcount() << endl;

        if (opt == 3)
            break;
    }

    return 0;
}
