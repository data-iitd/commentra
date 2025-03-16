#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int main()
{
    int a, b;
    int ans;

    scanf("%d %d", &a, &b);

    ans = 0;
    if (a >= 13) {
        ans = b;
    } else if (a >= 6) {
        ans = b/2;
    }

    printf("%d\n", ans);

    return 0;
}

