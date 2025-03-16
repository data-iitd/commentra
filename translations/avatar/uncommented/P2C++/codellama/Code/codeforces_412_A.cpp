
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    string v;
    cin >> n >> k >> v;
    string d[2] = {"LEFT", "RIGHT"};
    bool f = k - 1 < n - k;
    int m = min(k - 1, n - k);
    string a[m + 2 * f];
    for (int i = 0; i < m; i++)
    {
        a[i] = d[not f];
    }
    for (int i = 0; i < v.length(); i++)
    {
        a[i + m] = "PRINT " + v[i];
        a[i + m + f] = d[f];
    }
    for (int i = 0; i < m + 2 * f; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

