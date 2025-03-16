#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate C(n, m) using BigInteger logic
unsigned long long C(int n, int m) {
    unsigned long long res = 1;
    for (int i = m - n + 1; i <= m; i++) {
        res *= i;
    }
    for (int i = 1; i <= n; i++) {
        res /= i;
    }
    return res;
}

int main() {
    int n, p;
    int k0 = 0, k1 = 0;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 1) {
            k1++;
        } else {
            k0++;
        }
    }
    unsigned long long ans = 1;
    for (int i = 0; i < k0; i++) {
        ans *= 2;
    }
    if (p == 0) {
        unsigned long long add = 0;
        for (int i = 0; i <= k1; i += 2) {
            add += C(i, k1);
        }
        ans *= add;
        printf("%llu\n", ans);
    } else {
        unsigned long long add = 0;
        for (int i = 1; i <= k1; i += 2) {
            add += C(i, k1);
        }
        ans *= add;
        printf("%llu\n", ans);
    }
    return 0;
}
