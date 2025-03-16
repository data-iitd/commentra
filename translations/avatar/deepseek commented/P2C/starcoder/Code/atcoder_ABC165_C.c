
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000
#define MAX_Q 100000

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    int res = 0;
    int A[MAX_N];
    int (*rec)(int[]) = NULL;
    rec = (int (*)(int[])) malloc(sizeof(int) * (N + 1));
    rec[0] = 1;
    for (int i = 1; i <= N; i++) {
        rec[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if (rec[i] == 0) {
                break;
            }
            if (rec[i] + 1 > rec[i + 1]) {
                rec[i + 1] = rec[i] + 1;
            }
            if (rec[i] + 1 == rec[i + 1]) {
                for (int k = 0; k < Q; k++) {
                    if (j >= a[k] && j <= b[k] && j - i == c[k]) {
                        res += d[k];
                    }
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}

