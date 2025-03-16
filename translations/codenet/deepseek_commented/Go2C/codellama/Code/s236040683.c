
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int to[MAX_NODES];
} Node;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Node n[N];

    for (int i = 0; i < M; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        n[from].to[i] = to;
        n[to].to[i] = from;
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", sizeof(n[i].to) / sizeof(int));
    }

    return 0;
}

