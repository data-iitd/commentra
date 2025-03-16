#include <stdio.h>
#include <stdlib.h>

int main() {
    int x[3];
    int max = 0;
    int k;
    int i, j, m;

    // Reading the size of the array x from the standard input stream
    for (i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        if (x[i] > max) {
            max = x[i];
        }
    }

    scanf("%d", &k);

    long long a[3][max];

    // Reading the elements of each sub-list a[i] of size x[i] from the standard input stream and sorting it in ascending order
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < x[i]; ++j) {
            scanf("%lld", &a[i][j]);
        }
        // Sorting the sub-list a[i]
        for (j = 0; j < x[i] - 1; ++j) {
            for (m = j + 1; m < x[i]; ++m) {
                if (a[i][j] > a[i][m]) {
                    long long temp = a[i][j];
                    a[i][j] = a[i][m];
                    a[i][m] = temp;
                }
            }
        }
    }

    long long ans[max * max * max];
    int ans_size = 0;

    // Finding all such sums and adding them to the list ans
    for (i = 0; i < x[0]; ++i) {
        for (j = 0; j < x[1]; ++j) {
            for (m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    long long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[ans_size++] = tmp;
                }
            }
        }
    }

    // Sorting the list ans in ascending order
    for (i = 0; i < ans_size - 1; ++i) {
        for (j = i + 1; j < ans_size; ++j) {
            if (ans[i] > ans[j]) {
                long long temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
        }
    }

    // Printing the i-th element of the list ans, where i is the index of the element to be printed, starting from the last one
    for (i = 0; i < k; ++i) {
        printf("%lld\n", ans[ans_size - i - 1]);
    }

    return 0;
}
