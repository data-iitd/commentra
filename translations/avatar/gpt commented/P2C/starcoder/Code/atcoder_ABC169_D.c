#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define N 1000000000
#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0");
        return 0;
    }
    int ans = 0;
    int fac[N];
    for (int i = 0; i < N; i++) {
        fac[i] = 0;
    }
    int fac_cnt = 0;
    int f = 2;
    while (f * f <= n) {
        if (n % f == 0) {
            fac[fac_cnt] = f;
            fac_cnt++;
            n /= f;
        } else {
            f++;
        }
    }
    if (n!= 1) {
        fac[fac_cnt] = n;
        fac_cnt++;
    }
    for (int i = 0; i < fac_cnt; i++) {
        int x = fac[i];
        for (int j = 1; j < 99999999; j++) {
            if (x >= j) {
                x -= j;
                ans += 1;
            } else {
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}

