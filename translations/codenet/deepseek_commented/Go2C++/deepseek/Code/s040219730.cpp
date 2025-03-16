#include <bits/stdc++.h>
using namespace std;

// Constants and global variables
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = 1LL << 60;
const int INF_BIT60 = 1 << 60;
const int INF_INT32 = 1 << 30;
const int INF_BIT30 = 1 << 30;
const int NIL = -1;

// Initializes the input reader and output writer
void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Main function where the execution starts
int main() {
    init();
    // Reads the number of elements (n) and the number of queries (q)
    int n, q;
    cin >> n >> q;
    // Reads the array C
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    // Initializes the position array P with -1
    vector<int> P(500000 + 50, -1);
    // Reads the queries and stores them in Q
    vector<tuple<int, int, int>> Q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        Q.emplace_back(i, l, r);
    }

    // Sorts the queries based on the right index (r)
    sort(Q.begin(), Q.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) < get<2>(b);
    });

    // Initializes a Fenwick Tree with a size of 500050
    vector<int> fenwickTree(500050, 0);

    // Variable to keep track of the current position in the array C
    int k = 0;
    // Processes each query
    vector<int> Answers(q);
    for (const auto& query : Q) {
        int idx, l, r;
        tie(idx, l, r) = query;
        // Updates the Fenwick Tree and position array P until the current right index of the query
        while (k < r) {
            if (P[C[k]] != -1) {
                update(fenwickTree, P[C[k]] + 1, -1);
            }
            P[C[k]] = k;
            update(fenwickTree, k + 1, 1);
            k++;
        }
        // Calculates the answer for the current query using the Fenwick Tree
        Answers[idx] = sum(fenwickTree, r) - sum(fenwickTree, l - 1);
    }

    // Outputs the answers for each query
    for (int i = 0; i < q; i++) {
        cout << Answers[i] << '\n';
    }

    return 0;
}

// Fenwick Tree functions
void update(vector<int>& fenwickTree, int i, int x) {
    while (i < fenwickTree.size()) {
        fenwickTree[i] += x;
        i += i & (-i);
    }
}

int sum(const vector<int>& fenwickTree, int i) {
    int s = 0;
    while (i > 0) {
        s += fenwickTree[i];
        i -= i & (-i);
    }
    return s;
}
