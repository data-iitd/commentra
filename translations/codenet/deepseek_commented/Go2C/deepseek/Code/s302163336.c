#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int main() {
    int n, m;
    int h[MAX_N];
    int good[MAX_N];
    memset(good, 1, sizeof(good)); // Initialize all elements to true

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    for (int i = 0; i < m; i++) {
        int ai, bi;
        scanf("%d %d", &ai, &bi);
        ai--; // Adjust for 0-based index
        bi--; // Adjust for 0-based index
        if (h[ai] > h[bi]) {
            good[bi] = 0; // Mark the second element as not good if overshadowed
        } else if (h[ai] < h[bi]) {
            good[ai] = 0; // Mark the first element as not good if overshadowed
        } else {
            good[ai] = 0; // Mark both elements as not good if heights are equal
            good[bi] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++; // Count the elements that are still good
        }
    }

    printf("%d\n", ans); // Print the number of good elements
    return 0;
}
