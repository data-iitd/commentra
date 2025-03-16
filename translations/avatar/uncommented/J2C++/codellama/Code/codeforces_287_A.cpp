
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str[4];
    int i = -1;
    while (i != 3)
    {
        i++;
        cin >> str[i];
    }
    int u = -1;
    i = -1;
    int yes = 0;
    while (u != 2)
    {
        u++;
        i = -1;
        while (i != 2)
        {
            i++;
            if ((str[u].at(i) == str[u].at(i + 1) && (str[u + 1].at(i) == str[u].at(i) || str[u + 1].at(i + 1) == str[u].at(i))) || (str[u + 1].at(i) == str[u + 1].at(i + 1) && (str[u].at(i) == str[u + 1].at(i) || str[u].at(i + 1) == str[u + 1].at(i))))
            {
                yes = 1;
                cout << "YES" << endl;
                break;
            }
        }
        if (yes == 1)
        {
            break;
        }
    }
    if (yes == 0)
    {
        cout << "NO" << endl;
    }
    return 0;
}

