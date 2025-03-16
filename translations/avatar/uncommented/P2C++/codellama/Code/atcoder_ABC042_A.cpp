#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    istringstream iss(input);
    int ABC[3];
    for (int i = 0; i < 3; i++)
    {
        iss >> ABC[i];
    }
    if (count(ABC, ABC + 3, 5) == 2)
    {
        if (accumulate(ABC, ABC + 3, 0) == 17)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}

