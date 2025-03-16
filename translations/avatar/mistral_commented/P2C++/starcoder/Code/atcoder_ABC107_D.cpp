
#include <bits/stdc++.h>
using namespace std;

// Class definition for BIT (Binary Indexed Tree)
// Initialize an instance of BIT with a given size N
class BIT {
public:
    int size;
    vector<int> tree;
    int depth;
    BIT(int N) {
        // Initialize tree array with zeros
        size = N;
        tree = vector<int>(N + 1, 0);
        depth = N.bit_length();  // Calculate the depth of the tree
    }

    // Helper function to calculate the sum of bits from index i to 0
    int _bitsum(int i) {
        int ret = 0;
        while (i) {
            ret += tree[i];
            i &= i - 1;  // Bitwise AND with the rightmost set bit
        }
        return ret;
    }

    // Function to calculate the sum of bits from left index l to right index r
    int bitsum(int l, int r = -1) {
        if (r == -1) {
            return _bitsum(l);
        } else {
            return _bitsum(r) - _bitsum(l);
        }
    }

    // Function to add a value x to the index i in the tree
    void bitadd(int i, int x) {
        i += 1;  // Index i is 1-based in the tree
        while (i <= size) {
            tree[i] += x;
            i += i & -i;  // Bitwise right propagation
}
};

// Function to check if a given value X is a valid answer
bool check(int X) {
    vector<int> b(n + 1, 0);
    for (int i = 0; i < n; i++) {
        b[i + 1] = (a[i] >= X) * 2 - 1;
    }
    for (int i = 0; i < n; i++) {
        b[i + 1] += b[i];
    }
    int c = min(b);
    b = vector<int>(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        b[i] -= c;
    }
    BIT bit(max(b) + 2);  // Initialize BIT tree with the maximum value in b + 2
    int ans = 0;
    for (int x : b) {
        ans += bit.bitsum(x + 1);  // Calculate the sum of bits from index x+1 to the end
        bit.bitadd(x, 1);  // Add 1 to the index x in the tree
    }
    return ans >= m;
}

// Binary search to find the answer
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> d(a.size());
    for (int i = 0; i < a.size(); i++) {
        d[i] = i;
    }
    for (int i = 0; i < a.size(); i++) {
        a[i] = d[a[i]];
    }
    int t[2] = {a.size(), 0};
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        t[check(mid)] = mid;
    }
    cout << a[t[1]] << endl;
    return 0;
}

