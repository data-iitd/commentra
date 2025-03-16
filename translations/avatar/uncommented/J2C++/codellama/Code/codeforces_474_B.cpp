
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, q[100000], arr[100000];
    cin >> n;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < m; i++)
    {
        int res = 0;
        int j = n;
        int k = 0;
        while (k <= j)
        {
            int md = k + (j - k) / 2;
            if (arr[md] == q[i])
            {
                cout << md << endl;
                break;
            }
            else if (arr[md] > q[i])
            {
                res = md;
                j = md - 1;
            }
            else
            {
                k = md + 1;
            }
        }
        if (res == 0)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}

