
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// Define 'int' as 'long long' for larger integer support
#define int long long

// Structure to represent a range with a value
typedef struct {
    int l; // Left index of the range
    int r; // Right index of the range
    int val; // Value associated with the range
} Ban;

namespace Sp {
    // Constants for limits and size
    const int LIM = 20; 
    const int N = 2e5 + 7;

    // Sparse table for range minimum queries
    int mn[LIM][N];
    // Precomputed powers of 2
    int pw[N];

    // Function to initialize the sparse table
    void init(vector<int> a) {
        int n = (int)a.size();
        // Fill the first row of the sparse table
        for (int i = 0; i < n; i++) {
            mn[0][i] = a[i]; 
        }
        // Build the sparse table for range maximum queries
        for (int i = 0; i + 1 < LIM; i++) {
            for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                mn[i + 1][j] = max(mn[i][j], mn[i][j + (1 << i)]);
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
        return min(mn[p][l], mn[p][r - (1 << p)]);
    }
}

int main() {
    // Optimize input/output
    setbuf(stdout, NULL);
    setvbuf(stdin, NULL, _IONBF, 0);

    // Read the number of elements
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    // Read the elements into the vector
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // Vector to store the difference between index and value
    vector<int> dl(n);
    for (int i = 0; i < n; i++) {
        // Check if the value exceeds its index
        if (a[i] > i) {
            printf("-1\n"); // Output -1 if the condition fails
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
        bans.push_back({r - a[r], r, r - a[r]});
    }

    // Initialize the sparse table with the difference vector
    Sp::init(dl);
    // Check each range for validity
    for (auto t : bans) {
        // If the minimum value in the range exceeds the stored value, output -1
        if (Sp::get(t.l, t.r) > t.val) {
            printf("-1\n");
            return 0;
        }
    }
    // Output the final answer
    printf("%lld\n", ans);
}

