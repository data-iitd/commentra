
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int count = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '1')
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << 0;
    }
    else
    {
        int result = 1;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == '0')
            {
                result *= (i + 1);
            }
        }
        cout << result;
    }
    return 0;
}

