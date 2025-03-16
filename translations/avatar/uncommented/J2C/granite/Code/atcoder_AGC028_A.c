
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n, m, gcd;
    char s[100001], t[100001];
    scanf("%d%d%s%s", &n, &m, s, t);
    gcd = __gcd(n, m);
    for (int i = 0; i < gcd; i++) {
        if (s[i * n / gcd]!= t[i * m / gcd]) {
            printf("%lld\n", (long long)n * m / gcd);
            return 0;
        }
    }
    printf("%lld\n", (long long)n * m / gcd);
    return 0;
}
//END-OF-CODE