#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Define 'int' as 'long long' for larger integer support
#define int long long

// Structure to represent a range with a value
struct Ban {
    int l; // Left index of the range
    int r; // Right index of the range
    int val; // Value associated with the range

    // Default constructor
    Ban() {}

    // Parameterized constructor
    Ban(int l_, int r_, int val_) {
        l = l_;
        r = r_;
        val = val_;
    }
};

// Structure to represent a sparse table for range minimum queries
struct Sp {
    int mn[20][100007]; // Sparse table for range minimum queries
    int pw[100007]; // Precomputed powers of 2
};

// Function to initialize the sparse table
void init(struct Sp *sp, vector<int> a) {
    int n = (int)a.size();
    // Fill the first row of the sparse table
    for (int i = 0; i < n; i++) {
        sp->mn[0][i] = a[i]; 
    }
    // Build the sparse table for range maximum queries
    for (int i = 0; i + 1 < 20; i++) {
        for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
            sp->mn[i + 1][j] = max(sp->mn[i][j], sp->mn[i][j + (1 << i)]);
        }
    }
    // Precompute powers of 2 for later use
    sp->pw[1] = 0;
    for (int i = 2; i < 100007; i++) {
        sp->pw[i] = sp->pw[i / 2] + 1;
    }
} 

// Function to get the minimum value in the range [l, r]
int get(struct Sp *sp, int l, int r) {
    r++;
    int p = sp->pw[r - l];
    return min(sp->mn[p][l], sp->mn[p][r - (1 << p)]);
}

int main() {
    // Optimize input/output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Read the number of elements
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    // Read the elements into the vector
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Vector to store the difference between index and value
    vector<int> dl(n);
    for (int i = 0; i < n; i++) {
        // Check if the value exceeds its index
        if (a[i] > i) {
            printf("%d\n", -1); // Output -1 if the condition fails
            return 0;
        }
        // Calculate the difference and store it
        dl[i] = i - a[i];
    }

    // Initialize answer and vector to store ranges
    int ans = 0;
    vector<Ban> bans;
    for (int i = 0; i < n; i++) {
        int r = i;
        // Extend the range while the next value is consecutive
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        // Update the answer with the maximum value in the range
        ans += a[r];
        i = r; // Move to the end of the current range
        // Store the range in the bans vector
        bans.push_back(Ban(r - a[r], r, r - a[r]));
    }

    // Initialize the sparse table with the difference vector
    struct Sp sp;
    init(&sp, dl);
    // Check each range for validity
    for (int i = 0; i < (int)bans.size(); i++) {
        // If the minimum value in the range exceeds the stored value, output -1
        if (get(&sp, bans[i].l, bans[i].r) > bans[i].val) {
            printf("%d\n", -1);
            return 0;
        }
    }
    // Output the final answer
    printf("%d\n", ans);

    // End of code
    return 0;
}



