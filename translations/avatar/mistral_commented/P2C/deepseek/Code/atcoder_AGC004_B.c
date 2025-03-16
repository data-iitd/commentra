#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = -1; // Initialize with -1 to indicate uninitialized
        }
    }

    for (int i = 0; i < n; i++) {
        int m = a[i];
        for (int j = 0; j < n; j++) {
            int k = i - j;
            if (k < 0) {
                k += n;
            }
            m = (m < a[k]) ? m : a[k];
            b[j][i] = m;
        }
    }

    int min_sum = 1000000000000000;
    for (int i = 0; i < n; i++) {
        int sum_row = 0;
        for (int j = 0; j < n; j++) {
            sum_row += b[i][j];
        }
        sum_row += x * i;
        min_sum = (min_sum < sum_row) ? min_sum : sum_row;
    }

    printf("%d\n", min_sum);

    return 0;
}
