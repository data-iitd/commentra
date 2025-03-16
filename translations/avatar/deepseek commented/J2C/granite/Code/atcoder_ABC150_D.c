

#include <stdio.h>
#include <math.h>

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] /= 2;
    }
    long long lcm = 1;
    for (int i = 0; i < n; i++) {
        long long gcd_val = gcd(lcm, a[i]);
        lcm = (lcm * a[i]) / gcd_val;
        if (lcm > m) {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((lcm / a[i]) % 2 == 0) {
            printf("0\n");
            return 0;
        }
    }
    printf("%lld\n", (m / lcm + 1) / 2);
    return 0;
}
