#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cctype>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <bitset>
using namespace std;

int main()
{
    int n, k, l = 0, c = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == l)
            c += 1;
        else
            c = 1;
        l = a;
    }
    if (c + k > n)
        cout << n - c;
    else
        cout << -1;
    return 0;
}

