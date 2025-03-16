#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 200000

typedef struct {
    int *to;
    int size;
} Node;

Node nodes[MAX_N];

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

void addEdge(int from, int to) {
    nodes[from].to[nodes[from].size++] = to;
    nodes[to].to[nodes[to].size++] = from;
}

int main() {
    int N = getInt();
    int M = getInt();

    for (int i = 0; i < N; i++) {
        nodes[i].to = (int *)malloc(MAX_M * sizeof(int));
        nodes[i].size = 0;
    }

    for (int i = 0; i < M; i++) {
        int from = getInt() - 1;
        int to = getInt() - 1;
        addEdge(from, to);
    }

    for (int i = 0; i < N; i++) {
        out(1, nodes[i].size);
    }

    for (int i = 0; i < N; i++) {
        free(nodes[i].to);
    }

    return 0;
}
