
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main()
{
    int num = 998244353;
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 1)
    {
        printf("%d\n", b[n / 2] - a[n / 2] + 1);
    }
    else
    {
        double b1 = (a[n / 2] + a[n / 2 - 1]) / 2.0;
        double b2 = (b[n / 2] + b[n / 2 - 1]) / 2.0;
        printf("%d\n", (int)(2 * (b2 - b1) + 1));
    }
    return 0;
}
