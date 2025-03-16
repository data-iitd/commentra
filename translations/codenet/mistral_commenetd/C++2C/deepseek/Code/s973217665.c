#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORR(i, a, b) for (int i = a; i >= b; --i)
#define PI M_PI

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int p, q;
        scanf("%d %d", &p, &q);

        int l = (int)sqrt(p * p + q * q);

        bool isprime = true;

        REP(i, l) REP(j, l) {
            int x = i * i + j * j;

            if (x <= 1) continue;
            if (x > p * p + q * q) continue;

            if ((i * p + j * q) % x == 0 && (i * q - j * p) % x == 0) {
                isprime = false;
                break;
            }
        }

        printf("%s\n", isprime ? "P" : "C");
    }

    return 0;
}

