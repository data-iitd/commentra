
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <limits>
#include <numeric>
#include <climits>
#include <random>
#include <cstdio>
#include <cstring>

using namespace std;

// Constants used throughout the program
const int MOD = 1000000007;
const int ALPHABET_NUM = 26;
const int INF_INT = 1e9;
const int INF_BIT = 1 << 30;
const int NIL = -1;

// Constants for graph algorithms
const int WHITE = 0; // Unvisited node
const int GRAY = 1; // Visited node
const int BLACK = 2; // Processed node

// Query struct to hold the details of each query
struct Query {
    int idx, l, r;
};

// Fenwick Tree structure for efficient range queries
struct FenwickTree {
    vector<int> dat; // Array to store the tree data
    int n; // Number of elements
    int minPow2; // Minimum power of 2 greater than or equal to n

    FenwickTree(int n) {
        this->n = n;
        minPow2 = 1;
        while (minPow2 << 1 <= n) {
            minPow2 <<= 1;
        }
        dat.assign(n + 1, 0);
    }

    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) {
            s += dat[i];
        }
        return s;
    }

    void add(int i, int x) {
        for (; i <= n; i += i & -i) {
            dat[i] += x;
        }
    }

    int lower_bound(int w) {
        if (w <= 0) {
            return 0;
        }
        int x = 0;
        for (int k = minPow2; k > 0; k /= 2) {
            if (x + k <= n && dat[x + k] < w) {
                w -= dat[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};

int main() {
    // Read the number of elements and queries
    int n, q;
    cin >> n >> q;

    vector<int> C(n); // Slice to hold the input values
    vector<Query> Q(q); // Slice to hold the queries

    vector<int> P(500000 + 50, -1); // Array to track the last position of each value
    vector<int> Answers(500000 + 50); // Array to hold the answers for each query

    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        Query query = {i, l, r};
        Q[i] = query;
    }

    sort(Q.begin(), Q.end(), [](Query a, Query b) {
        return a.r < b.r;
    });
    FenwickTree ft(500000 + 50); // Initialize a Fenwick Tree for range queries

    int k = 0; // Pointer to track the current position in the input array
    // Process each query
    for (Query query : Q) {
        // Update the Fenwick Tree for all elements up to the right bound of the current query
        for (; k < query.r; k++) {
            if (P[C[k]] != -1) { // If the current value has been seen before
                ft.add(P[C[k]] + 1, -1); // Remove its previous occurrence from the Fenwick Tree
            }
            P[C[k]] = k; // Update the last position of the current value
            ft.add(k + 1, 1); // Add the current value to the Fenwick Tree
        }
        // Calculate the answer for the current query using the Fenwick Tree
        Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
    }

    // Output the answers for all queries
    for (int i = 0; i < q; i++) {
        // cout << Answers[i] << endl; // Print each answer
        cout << Answers[i] << endl; // Output the answer to stdout
    }

    return 0;
}

