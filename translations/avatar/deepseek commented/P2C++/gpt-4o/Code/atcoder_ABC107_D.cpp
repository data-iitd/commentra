#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class BIT {
public:
    BIT(int N) : size(N), tree(N + 1, 0) {}

    void bitadd(int i, int x) {
        i += 1; // Convert to 1-based index
        while (i <= size) {
            tree[i] += x; // Add x to the current index
            i += i & -i; // Move to the next index
        }
    }

    int bitsum(int l, int r = -1) {
        if (r == -1) {
            return _bitsum(l); // Calculate sum from 1 to l if r is not provided
        } else {
            return _bitsum(r) - _bitsum(l); // Calculate sum from l to r
        }
    }

private:
    int size;
    vector<int> tree;

    int _bitsum(int i) {
        int ret = 0; // Initialize the sum to 0
        while (i) {
            ret += tree[i]; // Add the value at the current index
            i ^= i & -i; // Move to the parent index using the binary representation
        }
        return ret; // Return the sum
    }
};

bool check(int X, const vector<int>& a, int n, int m) {
    vector<int> b(n + 1);
    b[0] = 0;
    for (int i = 0; i < n; ++i) {
        b[i + 1] = b[i] + ((a[i] >= X) ? 2 : 0) - 1; // Create a binary array
    }
    int c = *min_element(b.begin(), b.end()); // Normalize the array to be non-negative
    for (int i = 0; i <= n; ++i) {
        b[i] -= c;
    }
    BIT bit(*max_element(b.begin(), b.end()) + 2); // Initialize the BIT
    long long ans = 0;
    for (int x : b) {
        ans += bit.bitsum(x + 1); // Count inversions using the BIT
        bit.bitadd(x, 1); // Add 1 to the current index in the BIT
    }
    return ans >= m;
}

int main() {
    int n;
    cin >> n;
    int m = n * (n + 1) / 4; // Calculate the median position
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    unordered_map<int, int> d;
    vector<int> _a = a;
    _a.push_back(0);
    sort(_a.begin(), _a.end());
    _a.erase(unique(_a.begin(), _a.end()), _a.end());
    
    for (int i = 0; i < _a.size(); ++i) {
        d[_a[i]] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        a[i] = d[a[i]];
    }

    // Binary search to find the value of X
    pair<int, int> t = {static_cast<int>(_a.size()), 0};
    while (t.first - t.second > 1) {
        int mid = (t.first + t.second) / 2;
        if (check(mid, a, n, m)) {
            t.second = mid; // If check is true, move the lower bound up
        } else {
            t.first = mid; // Otherwise, move the upper bound down
        }
    }

    // Output the median value
    cout << _a[t.second] << endl;

    return 0;
}

// <END-OF-CODE>
