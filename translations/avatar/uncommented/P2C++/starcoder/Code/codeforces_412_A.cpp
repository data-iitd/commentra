#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string v;
    cin >> v;
    string d[] = {"LEFT", "RIGHT"};
    bool f = k - 1 < n - k;
    int m = min(k - 1, n - k);
    string a[m * 2 + 1];
    for (int i = 0; i < m; i++)
        a[i * 2] = d[not f];
    for (int i = 0; i < v.length(); i++)
    {
        a[i * 2 + 1] = "PRINT " + v[i];
        a[i * 2 + 2] = d[f];
    }
    for (int i = 0; i < m * 2 + 1; i++)
        cout << a[i] << endl;
    return 0;
}
