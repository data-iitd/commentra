

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int **m;

    scanf("%d", &n);
    m = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        m[i] = (int *)malloc(2 * sizeof(int));
        for (j = 0; j < 2; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (m[j][1] < m[j + 1][1]) {
                int temp = m[j][0];
                m[j][0] = m[j + 1][0];
                m[j + 1][0] = temp;
                temp = m[j][1];
                m[j][1] = m[j + 1][1];
                m[j + 1][1] = temp;
            }
        }
    }

    int a = m[0][0], b = m[0][1];
    for (i = 1; i < n; i++) {
        if (m[i][1] > b) {
            printf("Happy Alex");
            break;
        }
        a = m[i][0];
        b = m[i][1];
    }
    if (i == n) {
        printf("Poor Alex");
    }

    for (i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}

