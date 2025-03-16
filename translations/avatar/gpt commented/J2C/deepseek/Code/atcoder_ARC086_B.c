#include <stdio.h>
#include <stdlib.h>

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

    int pairs[n][2];
    int pair_count = 0;

    for (int i = 0; i < n; ++i) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            pairs[pair_count][0] = m + 1;
            pairs[pair_count][1] = i + 1;
            ++pair_count;
        }
    }

    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            pairs[pair_count][0] = i;
            pairs[pair_count][1] = i + 1;
            ++pair_count;
        }
    } else {
        for (int i = n; i > 1; --i) {
            pairs[pair_count][0] = i;
            pairs[pair_count][1] = i - 1;
            ++pair_count;
        }
    }

    printf("%d\n", pair_count);
    for (int i = 0; i < pair_count; ++i) {
        printf("%d %d\n", pairs[i][0], pairs[i][1]);
    }

    return 0;
}
