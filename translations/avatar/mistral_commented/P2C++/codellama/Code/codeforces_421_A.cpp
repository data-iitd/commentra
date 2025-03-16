#include <iostream>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int lista[n], listb[n];
    for (int i = 0; i < n; i++)
    {
        cin >> lista[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> listb[i];
    }

    for (int k = 0; k < n; k++)
    {
        if (k + 1 == lista[k])
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 2 << " ";
        }
    }

    return 0;
}

