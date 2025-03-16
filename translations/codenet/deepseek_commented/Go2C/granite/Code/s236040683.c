

#include <stdio.h>
#include <stdlib.h>

void out(int n,...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int **adjacency_list = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        adjacency_list[i] = (int *)malloc(sizeof(int) * N);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        adjacency_list[from - 1][to - 1] = 1;
        adjacency_list[to - 1][from - 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (adjacency_list[i][j] == 1) {
                count++;
            }
        }
        out(1, count);
    }

    for (int i = 0; i < N; i++) {
        free(adjacency_list[i]);
    }
    free(adjacency_list);

    return 0;
}

