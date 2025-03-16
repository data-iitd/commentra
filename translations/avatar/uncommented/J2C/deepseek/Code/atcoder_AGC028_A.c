#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int gcd_val = gcd(n, m);
    char s[1000], t[1000];
    scanf("%s %s", s, t);
    for (int k = 0; k < gcd_val; k++) {
        if (s[k * n / gcd_val] != t[k * m / gcd_val]) {
            printf("-1\n");
            return 0;
        }
    }
    long long result = (long long)n * m / gcd_val;
    printf("%lld\n", result);
    return 0;
}
