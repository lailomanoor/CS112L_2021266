#include <iostream>
#include <string>
using namespace std;

class stringType
{
    string s1;
    string s2;

public:
    stringType()
    {
        s1 = "";
        s2 = "";
    }

    void setValue(string x, string y)
    {
        s1 = x;
        s2 = y;
    }

    void cpystr(string source, string &destination)
    {
        /* int i = 0;
          int len1 = lenstr(source);

          while (i < len1)
          {
              destination[i] = source[i];
              i++;
          }

          destination[i] = '\0'; */

        destination = source;

        // cout << "dest: " << destination << endl;
    }

    void print()
    {
        cout << "\nthe first string is " << s1 << " and the second string is " << s2 << endl;
    }

    int lenstr(string s)
    {
        int i = 0;
        while (s[i] != '\0')
        {
            i++;
        }

        return i;
    }

    int maxLength()
    {
        int len1 = 0, len2 = 0;
        len1 = lenstr(s1);
        len2 = lenstr(s2);

        if (len1 > len2)
            return len1;

        else
            return len2;
    }

    string concatstr(string str1, string str2)
    {
        string str3;
        /*int len1 = lenstr(str1);
        int len2 = lenstr(str2);

        for (int i = 0; i < len1; i++)
        {
            str3[i] = str1[i];
        }


        for (int i = len1, j = 0; j < len2; i++, j++)
        {
            str3[i] = str2[j];
        }

        str3[len1 + len2] = '\0';*/

        str3 = str1 + str2;

        return str3;
    }

    int strcomp(string str1, string str2)
    {
        int len1 = lenstr(str1);
        int len2 = lenstr(str2);

        for (size_t i = 0; i < len1 && i < len2; i++)
            if (str1[i] != str2[i])
                return (str1[i] - str2[i]);

        return (len1 - len2);
    }

    int searchword(string word)
    {
        int len1 = lenstr(s1);
        int len2 = lenstr(s2);
        int lenW = lenstr(word);

        int check = 0;

        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < lenW; j++)
            {
                if (s1[i] == word[j])
                {
                    for (int a = 0, b = i, c = j; a < lenW; a++, b++, c++)
                    {
                        if (s1[b] == word[c])
                            check++;
                        else
                            break;
                    }

                    if (check == lenW)
                        return 1;
                    else
                        check = 0;
                }
            }
        }

        check = 0;
        for (int i = 0; i < len2; i++)
        {
            for (int j = 0; j < lenW; j++)
            {
                if (s2[i] == word[j])
                {
                    for (int a = 0, b = i, c = j; a < lenW; a++, b++, c++)
                    {
                        if (s2[b] == word[c])
                            check++;
                        else
                            break;
                    }

                    if (check == lenW)
                        return 1;
                    else
                        check = 0;
                }
            }
        }

        return 0;
    }

    int searchChar(char ch)
    {
        int len1 = lenstr(s1);
        int len2 = lenstr(s2);

        for (int i = 0; i < len1; i++)
        {
            if (s1[i] == ch)
                return 1;
        }

        for (int i = 0; i < len2; i++)
        {
            if (s2[i] == ch)
                return 1;
        }

        return 0;
    }
};

int main()
{
    stringType s;
    string s1, s2;

    cout << "enter two strings to set value\n";
    
    getline(cin, s1);
    getline(cin, s2);
    s.setValue(s1, s2);
    s.print();
    cout << "max length is " << s.maxLength() << endl;

    char c;
    cout << "enter character to search in s1 and s2\n";
    cin >> c;
    cout << "\nresult of search character is " << s.searchChar(c) << endl;

    cout << "enter word to search in s1 and s2\n";
    
    cin >> s1;
    cout << "\nresult of searching word is " << s.searchword(s1) << endl;

    cout << "enter string to copy\n";
    cin.ignore();
    getline(cin, s1);
    s2 = "";
    s.cpystr(s1, s2);
    cout << "s2 is now " << s2 << endl;

    cout << "enter two strings to concatinate and compare\n";
    getline(cin, s1);
    getline(cin, s2);
    cout << "concatinated string is : " << s.concatstr(s1, s2) << endl;
    cout << "result of the comparison is " << s.strcomp(s1, s2) << endl;

    return 0;
}
