#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
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
#include <tgmath.h>
#include <threads.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

#define N 100000

typedef struct {
    int color;
    int parent;
} node;

typedef struct {
    int a, b;
} edge;

int bfs(int v, int N, node *G, edge *E) {
    int visited[N];
    int queue[N];
    int K = -1;
    int node2color[N];
    memset(visited, 0, sizeof(visited));
    memset(node2color, -1, sizeof(node2color));
    int front = 0, rear = 0;
    queue[rear++] = v;
    visited[v] = 1;
    while (front < rear) {
        int q = queue[front++];
        int color = 0;
        for (int nex = 0; nex < G[q].size; nex++) {
            int nex_id = G[q].data[nex];
            if (visited[nex_id]) {
                continue;
            }
            visited[nex_id] = 1;
            color += 1;
            if (color == node2color[q]) {
                color += 1;
            }
            node2color[nex_id] = color;
            E[min(q, nex_id)].color = color;
            E[min(q, nex_id)].parent = max(q, nex_id);
            queue[rear++] = nex_id;
        }
        K = max(K, color);
    }
    return K;
}

int main() {
    int N;
    scanf("%d", &N);
    node G[N];
    edge E[N];
    for (int i = 0; i < N; i++) {
        G[i].size = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].data[G[a].size++] = b;
        G[b].data[G[b].size++] = a;
        E[i].a = min(a, b);
        E[i].b = max(a, b);
    }
    int K = bfs(0, N, G, E);
    printf("%d\n", K);
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", E[i].color);
    }
    return 0;
}

