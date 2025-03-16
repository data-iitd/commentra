#include <iostream>
#include <cmath>

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

    int d[n];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += w[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (x - w[i] == (n - 1) * w[i])
        {
            d[count] = i + 1;
            count++;
        }
    }

    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << d[i] << " ";
    }

    return 0;
}

