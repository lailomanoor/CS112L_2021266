#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int myStrLen(string s1)
{
    int i = 0;
    while (s1[i] != '\0')
    {
        i++;
    }

    return i;
}

class Coordinator;

class Person
{
private:
    char competition[20];
    char university[20];

public:
    friend class Coordinator;
};

class Coordinator
{
private:
    Person p1, p2;

public:
    void check()
    {
        char p1_info[20], p2_info[20];
        cout << "enter competition name and university name of first person, seperated by space\n";
        cin.getline(p1_info, 20);

                cout << "enter competition name and university name of second person, seperated by space\n";
        cin.getline(p2_info, 20);

        int i = 0;
        for (; p1_info[i] != ' '; i++)
        {
            p1.competition[i] = p1_info[i];
        }
        p1.competition[i] = '\0';
        i++;

        for (int j = 0; p1_info[i] != '\0'; j++, i++)
        {
            p1.university[j] = p1_info[i];
        }

        i = 0;
        for (; p2_info[i] != ' '; i++)
        {
            p2.competition[i] = p2_info[i];
        }
        p2.competition[i] = '\0';
        i++;

        int j = 0;
        for (; p2_info[i] != '\0'; j++, i++)
        {
            p2.university[j] = p2_info[i];
        }
        p2.university[j] = '\0';

        cout << p2_info << endl;
        cout << p1.university << " " << p2.university << endl;

        if (!strcmp(p1.university, p2.university))
        {
            int roomno;
            if (myStrLen(p1.competition) > myStrLen(p2.competition)) // Roomno = maxlength(s1,s2)
                roomno = myStrLen(p1.competition);
            else
                roomno = myStrLen(p2.competition);

            cout << "person 1 and person 2 are roomates and their room number is: " << roomno << endl;
        }

        else
            cout << "person 1 and person 2 are not roommates\n";
    }
};

int main()
{

    Coordinator c1;
    c1.check();
    return 0;
}
