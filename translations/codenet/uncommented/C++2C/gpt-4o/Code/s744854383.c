#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
#define INF (int)2e9
#define MOD (1000 * 1000 * 1000 + 7)
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
=======
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define INF (int)2e9
>>>>>>> 98c87cb78a (data updated)

int main() {
    int N;
    scanf("%d", &N);
    int *a = (int *)malloc(N * sizeof(int));
    REP(i, N) scanf("%d", &a[i]);

    int idx = 1;
    int ans = 0;
    REP(i, N) {
        if (a[i] == idx) {
            idx++;
        } else {
            ans++;
        }
    }

    if (idx == 1) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    free(a);
    return 0;
}

// <END-OF-CODE>
