#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <float.h>
#include <limits.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <fenv.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <assert.h>
#include <complex.h>
#include <tgmath.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <threads.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

#define N 100000

int main() {
    int N;
    scanf("%d", &N);
    int G[N][N];
    int E[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j] = 0;
            E[i][j] = 0;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        G[a][b] = 1;
        G[b][a] = 1;
        E[a][b] = 0;
        E[b][a] = 0;
    }
    int K = -1;
    int node2color[N];
    for (int i = 0; i < N; i++) {
        node2color[i] = -1;
    }
    int visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    int queue[N];
    int front = 0;
    int rear = 0;
    queue[rear] = 0;
    rear++;
    visited[0] = 1;
    while (front < rear) {
        int q = queue[front];
        int color = 0;
        for (int nex = 0; nex < N; nex++) {
            if (visited[nex]) {
                continue;
            }
            visited[nex] = 1;
            color++;
            if (color == node2color[q]) {
                color++;
            }
            node2color[nex] = color;
            E[min(q, nex)][max(q, nex)] = color;
            queue[rear] = nex;
            rear++;
        }
        K = max(K, color);
        front++;
    }
    printf("%d\n", K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", E[i][j]);
        }
        printf("\n");
    }
    return 0;
}

