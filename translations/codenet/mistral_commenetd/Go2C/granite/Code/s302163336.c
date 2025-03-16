

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements n and m from the standard input
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize h array with n elements and good array with n boolean values
    int h[n];
    int good[n];
    for (int i = 0; i < n; i++) {
        // Read n integers from the standard input and initialize h and good arrays
        scanf("%d", &h[i]);
        good[i] = 1;
    }

    // Process m queries
    for (int i = 0; i < m; i++) {
        // Read two integers ai and bi from the standard input
        int ai, bi;
        scanf("%d %d", &ai, &bi);
        ai--;
        bi--;

        // Compare the heights of h[ai] and h[bi]
        if (h[ai] > h[bi]) {
            // If h[ai] is greater than h[bi], mark good[bi] as false
            good[bi] = 0;
        } else if (h[ai] < h[bi]) {
            // If h[ai] is less than h[bi], mark good[ai] as false
            good[ai] = 0;
        } else {
            // If heights are equal, mark both good[ai] and good[bi] as false
            good[ai] = 0;
            good[bi] = 0;
        }
    }

    // Initialize answer variable ans to 0
    int ans = 0;

    // Count the number of good elements in the h array
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            // Increment ans if good[i] is true
            ans++;
        }
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

