
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000000

int main() {
    int A, B, Q, x, b, d, res, S, T, d1, d2;
    scanf("%d %d %d", &A, &B, &Q);
    int s[A+2] = {-INF, INF};
    for (int i = 1; i <= A; i++) {
        scanf("%d", &s[i]);
    }
    int t[B+2] = {-INF, INF};
    for (int i = 1; i <= B; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &x);
        b = 0;
        d = 0;
        while (s[b+1] < x) {
            b++;
        }
        while (t[d+1] < x) {
            d++;
        }
        res = INF;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                S = s[b+j];
                T = t[d+k];
                d1 = abs(S-x) + abs(T-S);
                d2 = abs(T-x) + abs(S-T);
                res = fmin(res, fmin(d1, d2));
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
// END-OF-CODE