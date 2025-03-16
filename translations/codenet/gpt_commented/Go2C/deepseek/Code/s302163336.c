#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from the input
int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int h[n];
    int good[n];
    for (int i = 0; i < n; i++) {
        h[i] = nextInt();
        good[i] = 1; // Initialize good array to 1 (true)
    }

    for (int i = 0; i < m; i++) {
        int ai = nextInt() - 1;
        int bi = nextInt() - 1;

        if (h[ai] > h[bi]) {
            good[bi] = 0; // If ai is taller, bi is not "good"
        } else if (h[ai] < h[bi]) {
            good[ai] = 0; // If bi is taller, ai is not "good"
        } else {
            // If heights are equal, mark both as not "good"
            good[ai] = 0;
            good[bi] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++; // Increment count for each "good" element
        }
    }

    printf("%d\n", ans);
    return 0;
}
