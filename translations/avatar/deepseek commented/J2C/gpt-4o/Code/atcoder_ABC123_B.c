#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[5];
    int r[5];
    int map[11] = {0}; // To store the last value for each remainder
    int lastValue[11] = {0}; // To store the last value corresponding to each key
    int mapSize = 0;

    // Step 2: Reading input and storing remainders
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;
        int b = 10;
        if (r[i] != 0) {
            b = 10 - r[i];
            if (map[b] == 0) {
                map[b] = 1; // Mark this remainder as used
                lastValue[b] = a[i]; // Store the last value for this remainder
                mapSize++;
            } else {
                lastValue[b] = a[i]; // Update the last value for this remainder
            }
        }
    }

    // Step 3: Handling edge cases
    if (mapSize == 0) {
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += a[i];
        }
        printf("%d\n", ans);
        return 0;
    }

    // Step 4: Finding the maximum and adjusting values
    int last = 0;
    for (int i = 0; i < 11; i++) {
        if (map[i] == 1) {
            last = lastValue[i]; // Get the last value for the maximum key
        }
    }

    int idx = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] == last) {
            idx = i; // Find the index of the last value
        }
    }

    int ans = 0;
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
