

```cpp
#include <bits/stdc++.h>
using namespace std;

// Define the FenwickTree class for efficient range queries
class FenwickTree {
private:
    vector<int> dat; // Data array to store the tree
    int n; // Number of elements
    int minPow2; // Minimum power of 2 greater than or equal to n

public:
    FenwickTree(int n) : n(n) {
        dat.assign(n + 1, 0); // Initialize the data array
        minPow2 = 1;
        while (minPow2 <= n) {
            minPow2 *= 2;
        }
    }

    // Sum calculates the prefix sum from 1 to i (1-based)
    int Sum(int i) {
        int s = 0; // Variable to hold the sum
        while (i > 0) {
            s += dat[i]; // Add the current index value to the sum
            i -= i & (-i); // Move to the parent index
        }
        return s; // Return the calculated sum
    }

    // Add updates the Fenwick Tree by adding x to the index i (1-based)
    void Add(int i, int x) {
        while (i <= n) {
            dat[i] += x; // Add x to the current index
            i += i & (-i); // Move to the next index
        }
    }

    // LowerBound returns the minimum index such that the sum is greater than or equal to w
    int LowerBound(int w) {
        if (w <= 0) {
            return 0; // If w is non-positive, return 0
        }

        int x = 0; // Variable to hold the index
        while (minPow2 > 0) {
            if (x + minPow2 <= n && dat[x + minPow2] < w) {
                w -= dat[x + minPow2]; // Decrease w by the current index value
                x += minPow2; // Move to the next index
            }
            minPow2 /= 2; // Move to the parent index
        }
        return x + 1; // Return the found index (1-based)
    }
};

int main() {
    int n, q; // Number of elements and number of queries
    cin >> n >> q; // Read the number of elements and queries

    vector<int> C(n); // Input array of integers
    for (int i = 0; i < n; i++) {
        cin >> C[i]; // Read each integer into the array
    }

    vector<pair<int, pair<int, int>>> Q(q); // Slice to hold the queries
    for (int i = 0; i < q; i++) {
        int l, r; // Left and right bounds of the query
        cin >> l >> r; // Read the left and right bounds of the query
        Q[i] = make_pair(r, make_pair(l, i)); // Create a new query
    }

    sort(Q.begin(), Q.end()); // Sort the queries based on the right bound

    FenwickTree ft(500000 + 50); // Initialize a Fenwick Tree for range queries

    int k = 0; // Pointer to track the current position in the input array
    for (int i = 0; i < q; i++) {
        int l = Q[i].second.first; // Left bound of the current query
        int r = Q[i].first; // Right bound of the current query

        while (k < r) {
            if (k > 0) {
                ft.Add(k, -1); // Remove the previous occurrence of C[k - 1] from the Fenwick Tree
            }
            ft.Add(k + 1, 1); // Add C[k] to the Fenwick Tree
            k++; // Move to the next position
        }

        int ans = ft.Sum(r) - ft.Sum(l - 1); // Calculate the answer for the current query using the Fenwick Tree
        cout << ans << endl; // Output the answer to stdout
    }

    return 0; // Return 0 to indicate successful execution
}

