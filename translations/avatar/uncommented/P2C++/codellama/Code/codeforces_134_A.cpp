#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += w[i];
    }
    int d[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if ((x - w[i]) / (n - 1) == w[i])
        {
            d[j] = i + 1;
            j++;
        }
    }
    cout << j << endl;
    for (int i = 0; i < j; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    return 0;
}



