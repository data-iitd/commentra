#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int m[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n - i - 1; k++) {
                if (m[k][0] < m[k + 1][0]) {
                    int temp = m[k][0];
                    m[k][0] = m[k + 1][0];
                    m[k + 1][0] = temp;
                    temp = m[k][1];
                    m[k][1] = m[k + 1][1];
                    m[k + 1][1] = temp;
                }
            }
        }
    }
    int a = m[0][0];
    int b = m[0][1];
    for (int i = 1; i < n; i++) {
        if (m[i][1] > b) {
            printf("Happy Alex\n");
            return 0;
        }
        a = m[i][0];
        b = m[i][1];
    }
    printf("Poor Alex\n");
    return 0;
}

