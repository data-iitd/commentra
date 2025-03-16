#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Helper function to print output.
void out(vector<int> x) {
    for (int i : x) {
        cout << i << " ";
    }
    cout << endl;
}

// Fenwick Tree implementation

class BIT {
public:
    int n;
    vector<int> data;

    BIT(int n) : n(n), data(n, 0) {}

    void add(int p, int x) {
        p++; // Convert to 1-based index
        while (p <= n) {
            data[p-1] += x;
            p += p & -p; // Move to the next node
        }
    }

    int sum(int l, int r) {
        return sum_upto(r) - sum_upto(l);
    }

private:
    int sum_upto(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r-1];
            r -= r & -r; // Move to the parent node
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    BIT fw(n);

    // Read n elements and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            // Update the value at position p by adding x to it.
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            // Query the sum of elements between indices l and r.
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << "\n";
        }
    }

    return 0;
}
