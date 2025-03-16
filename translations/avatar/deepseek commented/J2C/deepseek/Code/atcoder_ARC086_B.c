#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int m = 0;
    for (int i = 1; i < n; ++i) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }

    int max_abs = abs(a[m]);
    int max_index = m;

    int r[2 * n][2]; // Array to store the operations
    int r_size = 0; // Size of the operations array

    for (int i = 0; i < n; ++i) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            r[r_size][0] = m + 1;
            r[r_size][1] = i + 1;
            r_size++;
        }
    }

    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r[r_size][0] = i;
            r[r_size][1] = i + 1;
            r_size++;
        }
    } else {
        for (int i = n; i > 1; --i) {
            r[r_size][0] = i;
            r[r_size][1] = i - 1;
            r_size++;
        }
    }

    printf("%d\n", r_size);
    for (int i = 0; i < r_size; ++i) {
        printf("%d %d\n", r[i][0], r[i][1]);
    }

    return 0;
}
