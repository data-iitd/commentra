#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    int L[100000];
    int l;
    for (int i = 0; i < N; i++) {
        scanf("%d", &l);
        L[i] = l;
    }

    qsort(L, N, sizeof(int), cmpfunc);

    for (int i = 0; i < M; i++) {
        int max_L = L[N-1];
        if (max_L == 0) {
            break;
        }

        max_L /= 2;
        int *itr = (int *)bsearch(&max_L, L, N, sizeof(int), cmpfunc);
        memmove(itr+1, itr, (N-1-itr)*sizeof(int));
        L[itr] = max_L;
        N--;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    printf("%lld\n", ans);

}

