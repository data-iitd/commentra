#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

// Define 'long long' as 'long long' for larger integer support
#define long long long

// Structure to represent a range with a value
typedef struct {
    int l; // Left index of the range
    int r; // Right index of the range
    int val; // Value associated with the range
} Ban;

// Constants for limits and size
const int LIM = 20; 
const int N = 2e5 + 7;

// Sparse table for range minimum queries
int mn[LIM][N];
// Precomputed powers of 2
int pw[N];

// Function to initialize the sparse table
void init(int* a, int n) {
    // Fill the first row of the sparse table
    for (int i = 0; i < n; i++) {
        mn[0][i] = a[i]; 
    }
    // Build the sparse table for range maximum queries
    for (int i = 0; i + 1 < LIM; i++) {
        for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
            mn[i + 1][j] = fmax(mn[i][j], mn[i][j + (1 << i)]);
        }
    }
    // Precompute powers of 2 for later use
    pw[1] = 0;
    for (int i = 2; i < N; i++) {
        pw[i] = pw[i / 2] + 1;
    }
} 

// Function to get the minimum value in the range [l, r]
int get(int l, int r) {
    r++;
    int p = pw[r - l];
    return fmin(mn[p][l], mn[p][r - (1 << p)]);
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);
    int a[n];
    // Read the elements into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Array to store the difference between index and value
    int dl[n];
    for (int i = 0; i < n; i++) {
        // Check if the value exceeds its index
        if (a[i] > i) {
            printf("-1\n"); // Output -1 if the condition fails
            return 0;
        }
        // Calculate the difference and store it
        dl[i] = i - a[i];
    }

    // Initialize answer and array to store ranges
    long ans = 0;
    Ban bans[n];
    int ban_count = 0;
    for (int i = 0; i < n; i++) {
        int r = i;
        // Extend the range while the next value is consecutive
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        // Update the answer with the maximum value in the range
        ans += a[r];
        i = r; // Move to the end of the current range
        // Store the range in the bans array
        bans[ban_count++] = (Ban){r - a[r], r, r - a[r]};
    }

    // Initialize the sparse table with the difference array
    init(dl, n);
    // Check each range for validity
    for (int i = 0; i < ban_count; i++) {
        Ban t = bans[i];
        // If the minimum value in the range exceeds the stored value, output -1
        if (get(t.l, t.r) > t.val) {
            printf("-1\n");
            return 0;
        }
    }
    // Output the final answer
    printf("%lld\n", ans);
}
