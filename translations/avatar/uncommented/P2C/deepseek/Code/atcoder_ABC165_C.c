#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void solve(int N, int M, int Q, int* a, int* b, int* c, int* d) {
    int res = 0;
    void rec(int* A, int index) {
        if (index == N) {
            int ans = 0;
            for (int i = 0; i < Q; i++) {
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];
                }
            }
            res = max(res, ans);
            return;
        }
        int last_max = (index == 0) ? 1 : A[index - 1];
        for (int i = last_max; i <= M; i++) {
            A[index] = i;
            rec(A, index + 1);
        }
    }
    int A[N];
    rec(A, 0);
    printf("%d\n", res);
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    int* a = (int*)malloc(Q * sizeof(int));
    int* b = (int*)malloc(Q * sizeof(int));
    int* c = (int*)malloc(Q * sizeof(int));
    int* d = (int*)malloc(Q * sizeof(int));
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    solve(N, M, Q, a, b, c, d);
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}
