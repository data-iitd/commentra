
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> lista(n);
    vector<int> listb(n);
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
        if (k + 1 == a)
        {
            cout << 1 << " ";
        }
        else if (k + 1 == b)
        {
            cout << 2 << " ";
        }
        else if (k + 1 == lista[k])
        {
            cout << 1 << " ";
        }
        else if (k + 1 == listb[k])
        {
            cout << 2 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    return 0;
}
