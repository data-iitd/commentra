
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, l, r, o, e;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string res;
    for (int i = 0; i < k; i++)
    {
        cin >> l >> r;
        o = 0;
        e = 0;
        for (int j = l - 1; j < r; j++)
        {
            if (arr[j] == 1)
                o++;
            else
                e++;
        }
        if ((r - l + 1) % 2 == 1)
            res += "0\n";
        else
        {
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e)
                res += "1\n";
            else
                res += "0\n";
        }
    }
    cout << res;
    return 0;
}

