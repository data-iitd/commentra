
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define ll long long
#define mod 100000007
using namespace std;

int main() {
    ll startTime = clock();
    int n;
    scanf("%d", &n);
    ll div = pow(10, 9) + 7;
    ll A[n];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    for (int i = 0; i < 60; i++) {
        ll a = 0;
        ll count1 = 0;
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i & 1) == 1) count1++;
        }
        a = a + count1 * (n - count1);
        for (int j = 0; j < i; j++) {
            a = (a << 1) % div;
        }
        ans += a;
        ans %= div;
    }
    printf("%lld\n", ans);
    ll endTime = clock();
    return 0;
}
//END-OF-CODE