
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// out is a helper function to print output.
void out(int x) {
    cout << x << endl;
}

// getInt reads a single word from the input and converts it to an integer.
int getInt() {
    int x;
    cin >> x;
    return x;
}

// getString reads a single word from the input and returns it as a string.
string getString() {
    string x;
    cin >> x;
    return x;
}

// Fenwick Tree implementation

// BIT represents the Fenwick Tree data structure.
class BIT {
public:
    int n;
    vector<int> data;

    // FenwickTree initializes and returns a new Fenwick Tree with a given size.
    BIT(int n) {
        this->n = n;
        data.resize(n);
    }

    // Add updates the value at position p by adding x to it.
    void Add(int p, int x) {
        p++; // Convert to 1-based index
        for (; p <= n; p += p & -p) {
            data[p - 1] += x;
        }
    }

    // Sum calculates the sum of elements between indices l and r.
    int Sum(int l, int r) {
        return sum(r) - sum(l);
    }

    // sum calculates the prefix sum up to index r.
    int sum(int r) {
        int s = 0;
        for (; r > 0; r -= r & -r) {
            s += data[r - 1];
        }
        return s;
    }
};

int main() {
    // Read the number of elements (n) and the number of queries (q).
    int n = getInt();
    int q = getInt();

    // Initialize a Fenwick Tree with n elements.
    BIT fw(n);

    // Read n elements and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a = getInt();
        fw.Add(i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t = getInt();
        if (t == 0) {
            // Update the value at position p by adding x to it.
            int p = getInt();
            int x = getInt();
            fw.Add(p, x);
        } else {
            // Query the sum of elements between indices l and r.
            int l = getInt();
            int r = getInt();
            out(fw.Sum(l, r));
        }
    }
}

