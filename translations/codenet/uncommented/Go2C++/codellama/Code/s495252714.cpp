
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iomanip>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <functional>
#include <iterator>
using namespace std;

#define SIZE 100010

const int mod = 1000000007;

int n;
int c[SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int ans = 0;
    sort(c, c + n);
    for (int i = 0; i < n; i++)
    {
        ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
    }

    cout << ans * modpow(4, n - 1) % mod << endl;
    return 0;
}

int modpow(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1 == 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

