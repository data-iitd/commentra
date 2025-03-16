#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

int main() {
    int n;
    scanf("%d", &n);
    long long A[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    long long ans = 0;
    long long div = 1000000007;
    for(int i = 0; i < 60; i++) {
        long long a = 0;
        long long count1 = 0;
        for(int j = 0; j < n; j++) {
            if((A[j] >> i & 1) == 1) count1++;
        }
        a = a + count1 * (n - count1);
        for(int j = 0; j < i; j++) {
            a = (a << 1) % div;
        }
        ans += a;
        ans %= div;
    }
    printf("%lld\n", ans);
    return 0;
}
