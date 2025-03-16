#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define INF 1000000007

int min(int a, int b) {
    return a < b ? a : b;
}

int** createMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = INF;
        }
        matrix[i][i] = 0;
    }
    return matrix;
}

void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

    int rs[R];
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--;
    }

    int** costs = createMatrix(n);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    int perms[R][R];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            perms[i][j] = rs[i] == rs[j] ? 0 : INF;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < R; k++) {
                perms[i][j] = min(perms[i][j], perms[i][k] + costs[rs[k]][rs[j]]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < R; i++) {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            tmp += perms[i][j];
        }
        ans = min(ans, tmp);
    }

    printf("%d\n", ans);

    freeMatrix(costs, n);
    return 0;
}
