#include <iostream>
using namespace std;

class parity
{
    int *arr;
    int size;

public:
    parity()
    {
        size = 0;
    }

    void put(int x)
    {
        size++;

        int *temp = new int[size];

        for (int j = 0; j < size - 1; j++)
        {
            temp[j] = arr[j];
        }

        delete[] arr;
        temp[size - 1] = x;
        arr = temp;
        delete[] temp;
    }

    void print()
    {

        for (int j = 0; j < size; j++)
        {
            cout << arr[j] << "  ";
        }

        cout << endl;
    }

    void del()
    {
        if (size > 0)
            size--;

        if (size == 0)
            delete [] arr;
            
        if (size > 0)
        {
            int *temp = new int[size];
            for (int j = 0; j < size; j++)
            {
                temp[j] = arr[j];
            }

            delete[] arr;
            arr = temp;
            delete[] temp;
        }
    }

    int test()
    {
        if (size % 2 == 0)
            return 1;
        else
            return 0;
    }

    ~parity()
    {
        delete[] arr;
    }
};

int main()
{
    int opt, num;
    parity p;
    do
    {
        cout << "enter 1-to add element,2-delete n elements,3-to print all elements,4-to test size,5-to exit\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "enter number\n";
            cin >> num;
            p.put(num);
            break;
        case 2:
            p.del();
            break;
        case 3:
            p.print();
            break;
        case 4:
            cout << p.test() << endl;
            break;
        case 5:
            break;
        default:
            cout << "wrong option\n";
        }
    } while (opt != 5);

    return 0;
}
