#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 1e18

typedef struct {
    int size;
    int *data;
} deque;

deque* create_deque(int size) {
    deque* d = (deque*)malloc(sizeof(deque));
    d->size = 0;
    d->data = (int*)malloc(size * sizeof(int));
    return d;
}

void push_back(deque* d, int value) {
    d->data[d->size++] = value;
}

int pop_front(deque* d) {
    int value = d->data[0];
    for (int i = 1; i < d->size; i++) {
        d->data[i - 1] = d->data[i];
    }
    d->size--;
    return value;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int edge[N][N];
    memset(edge, 0, sizeof(edge));
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        scanf("%d %d %d", &X, &Y, &Z);
        X--; Y--;
        edge[X][Y] = 1;
        edge[Y][X] = 1;
    }
    bool used[N];
    memset(used, false, sizeof(used));
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;
            deque* queue = create_deque(N);
            push_back(queue, i);
            while (queue->size > 0) {
                int node = pop_front(queue);
                used[node] = true;
                for (int nextnode = 0; nextnode < N; nextnode++) {
                    if (edge[node][nextnode] && !used[nextnode]) {
                        push_back(queue, nextnode);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
