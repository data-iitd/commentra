#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int a[5];
    int r[5];
    int map[10] = {0}; // To store the values for each remainder
    int b, ans = 0, last = 0, idx = -1;

    // Read input
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;
        if (r[i] != 0) {
            b = 10 - r[i];
            if (map[b] == 0 || map[b] < a[i]) {
                map[b] = a[i]; // Store the maximum value for each remainder
            }
        }
    }

    // Check if map is empty
    int hasNonZeroRemainder = 0;
    for (int i = 1; i < 10; i++) {
        if (map[i] != 0) {
            hasNonZeroRemainder = 1;
            break;
        }
    }

    if (!hasNonZeroRemainder) {
        for (int i = 0; i < 5; i++) {
            ans += a[i];
        }
        printf("%d\n", ans);
        return 0;
    }

    // Find the last value (maximum value with the highest key)
    for (int i = 1; i < 10; i++) {
        if (map[i] > last) {
            last = map[i];
        }
    }

    // Find the index of the last value
    for (int i = 0; i < 5; i++) {
        if (a[i] == last) {
            idx = i;
            break;
        }
    }

    // Calculate the answer
    for (int i = 0; i < 5; i++) {
        if (i != idx) {
            if (a[i] % 10 == 0) {
                ans += a[i];
            } else {
                ans += a[i] + (10 - r[i]);
            }
        }
    }
    ans += last;

    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
