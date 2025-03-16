#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define INF 1000000007

int min(int a, int b) {
    return a < b ? a : b;
}

int** createMatrix(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = INF;
        }
        matrix[i][i] = 0;
    }
    return matrix;
}

void freeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void floydWarshall(int** costs, int size) {
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }
}

int* readArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        arr[i]--;
    }
    return arr;
}

void generatePermutations(int* arr, int n, int** result, int* index) {
    if (n == 1) {
        for (int i = 0; i < n; i++) {
            result[*index][i] = arr[i];
        }
        (*index)++;
    } else {
        for (int i = 0; i < n; i++) {
            generatePermutations(arr, n - 1, result, index);
            if (n % 2 == 1) {
                int temp = arr[i];
                arr[i] = arr[n - 1];
                arr[n - 1] = temp;
            } else {
                int temp = arr[0];
                arr[0] = arr[n - 1];
                arr[n - 1] = temp;
            }
        }
    }
}

int main() {
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

    int* rs = readArray(R);

    int** costs = createMatrix(n);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    floydWarshall(costs, n);

    int** perms = (int**)malloc(R * sizeof(int*));
    for (int i = 0; i < R; i++) {
        perms[i] = (int*)malloc(R * sizeof(int));
    }
    int index = 0;
    generatePermutations(rs, R, perms, &index);

    int ans = INF;
    for (int i = 0; i < index; i++) {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            int from = perms[i][j - 1];
            int to = perms[i][j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
    }

    printf("%d\n", ans);

    for (int i = 0; i < R; i++) {
        free(perms[i]);
    }
    free(perms);
    free(rs);
    freeMatrix(costs, n);

    return 0;
}
