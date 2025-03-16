#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct {
    int *to;
    int size;
} Node;

Node nodes[MAX_NODES];

void out(int x, ...) {
    va_list args;
    va_start(args, x);
    for (int i = 0; i < x; i++) {
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int main() {
    int N = getInt();
    int M = getInt();

    for (int i = 0; i < M; i++) {
        int from = getInt() - 1;
        int to = getInt() - 1;
        nodes[from].to = (int *)realloc(nodes[from].to, (nodes[from].size + 1) * sizeof(int));
        nodes[from].to[nodes[from].size] = to;
        nodes[from].size++;
        nodes[to].to = (int *)realloc(nodes[to].to, (nodes[to].size + 1) * sizeof(int));
        nodes[to].to[nodes[to].size] = from;
        nodes[to].size++;
    }

    for (int i = 0; i < N; i++) {
        out(1, nodes[i].size);
    }

    for (int i = 0; i < N; i++) {
        free(nodes[i].to);
    }

    return 0;
}

