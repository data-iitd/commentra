#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF (int)(pow(10, 11))

int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int A = nextInt();
    int B = nextInt();
    int Q = nextInt();

    int *s = (int *)malloc((A + 2) * sizeof(int));
    s[0] = -INF;
    s[A + 1] = INF;
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt();
    }

    int *t = (int *)malloc((B + 2) * sizeof(int));
    t[0] = -INF;
    t[B + 1] = INF;
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt();
    }

    for (int i = 0; i < Q; i++) {
        int x = nextInt();
        int b = 0, d = 0;

        // Binary search for s
        for (int j = 1; j <= A + 1; j++) {
            if (s[j] >= x) {
                b = j;
                break;
            }
        }

        // Binary search for t
        for (int j = 1; j <= B + 1; j++) {
            if (t[j] >= x) {
                d = j;
                break;
            }
        }

        int res = INF;
        for (int j = b - 1; j <= b; j++) {
            for (int k = d - 1; k <= d; k++) {
                int S = s[j];
                int T = t[k];
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T);
                res = min(res, min(d1, d2));
            }
        }

        printf("%d\n", res);
    }

    free(s);
    free(t);
    return 0;
}

// <END-OF-CODE>
