#include <iostream>
using namespace std;

int main()
{
    int a, c, k, b;
    while (cin >> a)
    {
        c = 0, k = 0;
        if (a < 3)
            cout << "0" << endl;
        else
        {
            b = a;
            while (a--)
            {
                b--;
                c++;
                if (c == 3)
                {
                    k++;
                    c = 0;
                }
            }
            cout << k << endl;
        }
    }
}
