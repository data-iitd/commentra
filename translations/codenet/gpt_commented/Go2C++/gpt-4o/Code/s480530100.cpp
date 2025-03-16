#include <iostream>
#include <vector>

using namespace std;

// Utility function to print output to the console.
void out(int x) {
    cout << x << endl;
}

// Class representing a Binary Indexed Tree (Fenwick Tree).
class BIT {
public:
    BIT(int n) : n(n), data(n, 0) {} // Constructor to initialize the tree with n elements.

    // Update the Fenwick Tree by adding x to the element at position p.
    void Add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p;      // Move to the next index
        }
    }

    // Calculate the sum of elements in the range [l, r).
    int Sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

private:
    int n; // Number of elements in the tree
    vector<int> data; // Array to store the tree data

    // Calculate the prefix sum from the start to index r.
    int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r;      // Move to the parent index
        }
        return s; // Return the calculated sum
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q; // Read the number of elements (n) and the number of queries (q).

    BIT fw(n); // Initialize a Fenwick Tree with n elements.

    // Read n integers and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.Add(i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t; // Read the type of query.
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p, x;
            cin >> p >> x;
            fw.Add(p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
            int l, r;
            cin >> l >> r;
            out(fw.Sum(l, r));
        }
    }

    return 0;
}

// <END-OF-CODE>
