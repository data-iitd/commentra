#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> lista;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        lista.push_back(x);
    }

    vector<int> listb;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        listb.push_back(x);
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

