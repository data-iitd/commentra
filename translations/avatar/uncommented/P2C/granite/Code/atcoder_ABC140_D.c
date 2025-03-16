
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
    int n, k;
    scanf("%d%d", &n, &k);
    char s[100005];
    scanf("%s", s);
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i]!= s[i + 1])
            cnt++;
    }
    int ans = n - 1;
    if (cnt >= 2 * k)
        ans = n - 1;
    else
        ans = cnt + 2 * k;
    printf("%d\n", ans);
    return 0;
}

