#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7; // Modulus value for calculations
const int MAXN = 500000 + 50;    // Maximum number of elements

struct Query {
    int idx, l, r; // Index, left, and right bounds of the query
};

class FenwickTree {
public:
    vector<int> dat;
    int n;

    FenwickTree(int size) : n(size) {
        dat.resize(n + 1, 0); // Initialize the Fenwick Tree
    }

    void Add(int i, int x) {
        while (i <= n) {
            dat[i] += x; // Add x to the current index
            i += i & (-i); // Move to the next index
        }
    }

    int Sum(int i) {
        int s = 0; // Variable to hold the sum
        while (i > 0) {
            s += dat[i]; // Add the current index value to the sum
            i -= i & (-i); // Move to the parent index
        }
        return s; // Return the calculated sum
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; // Number of elements and number of queries
    cin >> n >> q;

    vector<int> C(n); // Slice to hold the input values
    for (int i = 0; i < n; i++) {
        cin >> C[i]; // Read the slice of integers
    }

    vector<int> P(MAXN, -1); // Array to track the last position of each value
    vector<int> Answers(q); // Array to hold the answers for each query
    vector<Query> Q(q); // Slice to hold the queries

    // Read each query and store it in the Q vector
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r; // Read the left and right bounds of the query
        Q[i] = {i, l, r}; // Create a new query
    }

    // Sort the queries based on the right bound
    sort(Q.begin(), Q.end(), [](const Query &a, const Query &b) {
        return a.r < b.r;
    });

    FenwickTree ft(MAXN); // Initialize a Fenwick Tree for range queries
    int k = 0; // Pointer to track the current position in the input array

    // Process each query
    for (const auto &query : Q) {
        // Update the Fenwick Tree for all elements up to the right bound of the current query
        while (k < query.r) {
            if (P[C[k]] != -1) { // If the current value has been seen before
                ft.Add(P[C[k]] + 1, -1); // Remove its previous occurrence from the Fenwick Tree
            }
            P[C[k]] = k; // Update the last position of the current value
            ft.Add(k + 1, 1); // Add the current value to the Fenwick Tree
            k++; // Move to the next position
        }
        // Calculate the answer for the current query using the Fenwick Tree
        Answers[query.idx] = ft.Sum(query.r) - ft.Sum(query.l - 1);
    }

    // Output the answers for all queries
    for (int i = 0; i < q; i++) {
        cout << Answers[i] << "\n"; // Print each answer
    }

    return 0;
}

/<END-OF-CODE>
