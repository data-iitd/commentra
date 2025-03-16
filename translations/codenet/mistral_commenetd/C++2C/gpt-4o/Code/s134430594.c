#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define int long long

// Define a struct to store information about intervals
struct Ban {
    int l; // left endpoint of the interval
    int r; // right endpoint of the interval
    int val; // value of the interval
};

// Define a namespace-like structure for segment tree operations
struct Sp {
    const int LIM; // Maximum depth of the segment tree
    const int N; // Maximum number of elements in the array
    int mn[20][200007]; // An array to store the minimum value in each segment of the segment tree
    int pw[200007]; // Array to store powers of 2

    Sp() : LIM(20), N(200007) {
        memset(mn, 0, sizeof(mn));
        memset(pw, 0, sizeof(pw));
    }

    // A function to initialize the segment tree
    void init(int* a, int n) {
        // Initialize the first level of the segment tree
        for (int i = 0; i < n; i++) {
            mn[0][i] = a[i]; // Store the value of the element at index i in the first level of the segment tree
        }
        // Build the segment tree recursively
        for (int i = 0; i + 1 < LIM; i++) {
            for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                mn[i + 1][j] = (mn[i][j] > mn[i][j + (1 << i)]) ? mn[i][j] : mn[i][j + (1 << i)]; // Find the minimum value in the current segment
            }
        }
        // Calculate the power of 2 up to the maximum depth of the segment tree
        pw[1] = 0;
        for (int i = 2; i < N; i++) {
            pw[i] = pw[i / 2] + 1; // Calculate the power of 2 for each index
        }
    }

    // A function to get the minimum value in a segment of the segment tree
    int get(int l, int r) {
        r++; // Adjust the index of the right endpoint of the segment to be one more than the actual index
        int p = pw[r - l]; // Calculate the depth of the segment tree for the given segment
        return (mn[p][l] < mn[p][r - (1 << p)]) ? mn[p][l] : mn[p][r - (1 << p)]; // Return the minimum value in the given segment
    }
};

int main() {
    // Fast input-output
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Read the number of elements in the array
    int n;
    scanf("%lld", &n);

    // Read the elements of the array
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // Initialize some variables
    int* dl = (int*)malloc(n * sizeof(int)); // An array to store the difference between the index and the index of the element in the array
    int ans = 0; // The answer
    struct Ban* bans = (struct Ban*)malloc(n * sizeof(struct Ban)); // A vector to store some information about the intervals
    int ban_count = 0; // Count of bans

    // Calculate the differences between the indices and the elements in the array
    for (int i = 0; i < n; i++) {
        if (a[i] > i) { // Check if the element is out of its position
            printf("-1\n"); // Output -1 if the element is out of its position
            free(a);
            free(dl);
            free(bans);
            return 0;
        }
        dl[i] = i - a[i]; // Calculate the difference between the index and the element
    }

    // Calculate the answer and store some information about the intervals in a vector
    for (int i = 0; i < n; i++) {
        int r = i; // Initialize a variable to store the right endpoint of the current interval
        while (r + 1 < n && a[r] + 1 == a[r + 1]) { // Check if there is a longer interval with the same value
            r++; // Move to the next index if there is
        }
        ans += a[r]; // Add the value of the right endpoint of the current interval to the answer
        i = r; // Update the index to be the right endpoint of the current interval
        bans[ban_count++] = (struct Ban){r - a[r], r, r - a[r]}; // Store some information about the current interval in the vector
    }

    // Initialize the segment tree using the differences between the indices and the elements in the array
    struct Sp sp;
    sp.init(dl, n);

    // Check some conditions and calculate the answer if possible
    for (int i = 0; i < ban_count; i++) {
        if (sp.get(bans[i].l, bans[i].r) > bans[i].val) { // Check if the minimum value in the segment of the segment tree is greater than the value of the interval
            printf("-1\n"); // Output -1 if the condition is not satisfied
            free(a);
            free(dl);
            free(bans);
            return 0;
        }
    }

    // Output the answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(a);
    free(dl);
    free(bans);
    return 0;
}

// <END-OF-CODE>
