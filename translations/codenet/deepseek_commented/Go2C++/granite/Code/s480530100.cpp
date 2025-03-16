
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// out is a helper function to print output.
void out(int x) {
    cout << x << endl;
}

// main function is the entry point of the program.
int main() {
    // Read the number of elements (n) and the number of queries (q).
    int n, q;
    cin >> n >> q;

    // Initialize a Fenwick Tree with n elements.
    vector<int> fw(n);

    // Read n elements and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw[i] += a;
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            // Update the value at position p by adding x to it.
            int p, x;
            cin >> p >> x;
            fw[p] += x;
        } else {
            // Query the sum of elements between indices l and r.
            int l, r;
            cin >> l >> r;
            int sum = 0;
            for (int j = l; j < r; j++) {
                sum += fw[j];
            }
            out(sum);
        }
    }

    return 0;
}

// Fenwick Tree implementation

// BIT represents the Fenwick Tree data structure.
class BIT {
public:
    vector<int> data;
    int n;

    // FenwickTree initializes and returns a new Fenwick Tree with a given size.
    BIT(int n) : n(n), data(n) {}

    // Add updates the value at position p by adding x to it.
    void add(int p, int x) {
        p++; // Convert to 1-based index
        for (int i = p; i <= n; i += i & -i) {
            data[i-1] += x;
        }
    }

    // Sum calculates the sum of elements between indices l and r.
    int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    // sum calculates the prefix sum up to index r.
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }
};

// Translate the above C++ code to Java and end with comment "