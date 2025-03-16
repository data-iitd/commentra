#include <stdio.h>
#include <stdlib.h>

void editorial(int N, int* P) {
    if (N == 1) {
        printf("0\n");
        return;
    }
    int* a = (int*)calloc(N + 1, sizeof(int));
    for (int i = 0; i < N; i++) {
        a[P[i]] = i;
    }
    int tmp = 1;
    int max_len = 1;
    for (int i = 1; i < N; i++) {
        if (a[i] < a[i + 1]) {
            tmp++;
            max_len = tmp > max_len ? tmp : max_len;
        } else {
            tmp = 1;
        }
    }
    int ans = N - max_len;
    printf("%d\n", ans);
    free(a);
}

void WA(int N, int* P) {
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || P[i - 1] + 1 == P[i]) {
            tmp++;
        } else {
            ans = ans > tmp ? ans : tmp;
            tmp = 1;
        }
    }
    ans = ans > tmp ? ans : tmp;
    printf("%d\n", N - ans);
}

int main() {
    int N;
    scanf("%d", &N);
    int* P = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }
    editorial(N, P);
    free(P);
    return 0;
}

