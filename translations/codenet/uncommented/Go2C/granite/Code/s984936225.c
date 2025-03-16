
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    const int Inf = 1 << 62;
    int *dist = (int *)malloc(sizeof(int) * N);
    int *a = (int *)malloc(sizeof(int) * M);
    int *b = (int *)malloc(sizeof(int) * M);
    int *c = (int *)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        c[i] = -c[i];
    }
    for (int i = 0; i < N; i++) {
        dist[i] = Inf;
    }
    dist[0] = 0;
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == Inf) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }
    int ans = dist[N - 1];
    int *navigate = (int *)malloc(sizeof(int) * N);
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == Inf) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                navigate[b[i] - 1] = 1;
            }
            if (navigate[a[i] - 1] == 1) {
                navigate[b[i] - 1] = 1;
            }
        }
    }

    if (navigate[N - 1] == 1) {
        printf("inf\n");
    } else {
        printf("%d\n", -ans);
    }

    free(dist);
    free(a);
    free(b);
    free(c);
    free(navigate);

    return 0;
}
