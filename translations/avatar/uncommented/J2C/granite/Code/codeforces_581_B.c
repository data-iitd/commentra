
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

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<ll> dp(n + 1, -1);
    dp[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i + 1], a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > dp[i + 1]) {
            printf("0 ");
        } else {
            printf("%lld ", dp[i + 1] - a[i] + 1);
        }
    }
    printf("\n");
    return 0;
}
