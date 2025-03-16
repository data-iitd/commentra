#include <stdio.h>
#include <stdlib.h>

int N, M, Q;
int *a, *b, *c, *d;
int res = 0;

void rec(int *A, int len) {
    if (len == N) {
        int ans = 0;
        for (int i = 0; i < Q; i++) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                ans += d[i];
            }
        }
        if (ans > res) {
            res = ans;
        }
        return;
    }
    int last_max = (len == 0) ? 1 : A[len - 1];
    for (int i = last_max; i <= M; i++) {
        A[len] = i;
        rec(A, len + 1);
    }
}

void solve(int N, int M, int Q, int *a, int *b, int *c, int *d) {
    int *A = (int *)malloc(N * sizeof(int));
    rec(A, 0);
    printf("%d\n", res);
    free(A);
}

int main() {
    scanf("%d %d %d", &N, &M, &Q);
    a = (int *)malloc(Q * sizeof(int));
    b = (int *)malloc(Q * sizeof(int));
    c = (int *)malloc(Q * sizeof(int));
    d = (int *)malloc(Q * sizeof(int));
    
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

// <END-OF-CODE>
