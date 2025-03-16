#include <stdio.h>
#include <math.h>

#define REP(i,n) for(int i=0; i<n; ++i)

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int p, q;
        scanf("%d %d", &p, &q);
        int l = (int)sqrt(p*p + q*q);
        int isprime = 1;
        REP(i, l) REP(j, l) {
            int x = i*i + j*j;
            if (x <= 1 || x >= p*p + q*q) continue;
            if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) isprime = 0;
        }
        printf("%s\n", isprime ? "P" : "C");
    }

    return 0;
}

// <END-OF-CODE>
