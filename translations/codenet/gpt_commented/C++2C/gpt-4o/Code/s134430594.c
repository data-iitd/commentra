#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
=======
#include <limits.h>
>>>>>>> 98c87cb78a (data updated)

#define LIM 20
#define N 200007

// Structure to represent a range with a value
<<<<<<< HEAD
struct Ban {
    long long l; // Left index of the range
    long long r; // Right index of the range
    long long val; // Value associated with the range
};

// Sparse table for range minimum queries
long long mn[LIM][N];
// Precomputed powers of 2
long long pw[N];

// Function to initialize the sparse table
void init(long long *a, long long n) {
    // Fill the first row of the sparse table
    for (long long i = 0; i < n; i++) {
        mn[0][i] = a[i];
    }
    // Build the sparse table for range maximum queries
    for (long long i = 0; i + 1 < LIM; i++) {
        for (long long j = 0; j + (1 << (i + 1)) <= n; j++) {
=======
typedef struct {
    long long l; // Left index of the range
    long long r; // Right index of the range
    long long val; // Value associated with the range
} Ban;

long long mn[LIM][N]; // Sparse table for range minimum queries
int pw[N]; // Precomputed powers of 2

// Function to initialize the sparse table
void init(long long *a, int n) {
    // Fill the first row of the sparse table
    for (int i = 0; i < n; i++) {
        mn[0][i] = a[i];
    }
    // Build the sparse table for range maximum queries
    for (int i = 0; i + 1 < LIM; i++) {
        for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
>>>>>>> 98c87cb78a (data updated)
            mn[i + 1][j] = (mn[i][j] > mn[i][j + (1 << i)]) ? mn[i][j] : mn[i][j + (1 << i)];
        }
    }
    // Precompute powers of 2 for later use
    pw[1] = 0;
<<<<<<< HEAD
    for (long long i = 2; i < N; i++) {
=======
    for (int i = 2; i < N; i++) {
>>>>>>> 98c87cb78a (data updated)
        pw[i] = pw[i / 2] + 1;
    }
}

// Function to get the minimum value in the range [l, r]
<<<<<<< HEAD
long long get(long long l, long long r) {
    r++;
    long long p = pw[r - l];
=======
long long get(int l, int r) {
    r++;
    int p = pw[r - l];
>>>>>>> 98c87cb78a (data updated)
    return (mn[p][l] < mn[p][r - (1 << p)]) ? mn[p][l] : mn[p][r - (1 << p)];
}

int main() {
<<<<<<< HEAD
=======
    // Optimize input/output
    ios_base::sync_with_stdio(0);
>>>>>>> 98c87cb78a (data updated)
    // Read the number of elements
    long long n;
    scanf("%lld", &n);
    long long *a = (long long *)malloc(n * sizeof(long long));
    // Read the elements into the array
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

<<<<<<< HEAD
    // Vector to store the difference between index and value
=======
    // Array to store the difference between index and value
>>>>>>> 98c87cb78a (data updated)
    long long *dl = (long long *)malloc(n * sizeof(long long));
    for (long long i = 0; i < n; i++) {
        // Check if the value exceeds its index
        if (a[i] > i) {
            printf("-1\n"); // Output -1 if the condition fails
            free(a);
            free(dl);
            return 0;
        }
        // Calculate the difference and store it
        dl[i] = i - a[i];
    }

    // Initialize answer and array to store ranges
    long long ans = 0;
<<<<<<< HEAD
    struct Ban *bans = (struct Ban *)malloc(n * sizeof(struct Ban));
=======
    Ban *bans = (Ban *)malloc(n * sizeof(Ban));
>>>>>>> 98c87cb78a (data updated)
    long long ban_count = 0;

    for (long long i = 0; i < n; i++) {
        long long r = i;
        // Extend the range while the next value is consecutive
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        // Update the answer with the maximum value in the range
        ans += a[r];
        i = r; // Move to the end of the current range
        // Store the range in the bans array
<<<<<<< HEAD
        bans[ban_count++] = (struct Ban){r - a[r], r, r - a[r]};
=======
        bans[ban_count++] = (Ban){r - a[r], r, r - a[r]};
>>>>>>> 98c87cb78a (data updated)
    }

    // Initialize the sparse table with the difference array
    init(dl, n);
    // Check each range for validity
    for (long long i = 0; i < ban_count; i++) {
<<<<<<< HEAD
        struct Ban t = bans[i];
=======
        Ban t = bans[i];
>>>>>>> 98c87cb78a (data updated)
        // If the minimum value in the range exceeds the stored value, output -1
        if (get(t.l, t.r) > t.val) {
            printf("-1\n");
            free(a);
            free(dl);
            free(bans);
            return 0;
        }
    }
    // Output the final answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(a);
    free(dl);
    free(bans);
    return 0;
}

// <END-OF-CODE>
