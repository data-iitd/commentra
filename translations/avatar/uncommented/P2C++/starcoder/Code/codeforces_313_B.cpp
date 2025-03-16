#include <iostream>
#include <string>
using namespace std;
int main()
{
    string soz;
    cin >> soz;
    int a[soz.length() + 1];
    a[0] = 0;
    for (int i = 1; i < soz.length(); i++)
    {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i])
            a[i] += 1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, l;
        cin >> m >> l;
        cout << a[l - 1] - a[m - 1] << endl;
    }
    return 0;
}
