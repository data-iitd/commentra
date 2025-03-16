#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    int min = INT_MAX;
    int a[n][m + 1];

    // Filling the array with nutrient amounts for each ingredient
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Generating all possible combinations of ingredients
    for (int i = 0; i < pow(2, n); i++) {
        int status[n];
        for (int j = 0; j < n; j++) {
            if ((1 & (i >> j)) == 1) {
                status[j] = 1;
            } else {
                status[j] = 0;
            }
        }
        int res[m + 1] = {0};
        for (int j = 0; j < n; j++) {
            if (status[j] == 1) {
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }
        int flag = 1;
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            if (min > res[0]) {
                min = res[0];
            }
        }
    }

    // Outputting the result
    if (min == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", min);
    }

    return 0;
}
