
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// A helper function to print output
void out(int x) {
    cout << x << endl;
}

// Function to read an integer from the standard input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a string from the standard input
string getString() {
    string x;
    cin >> x;
    return x;
}

// Fenwick Tree
class FenwickTree {
private:
    int n;
    vector<int> data;

public:
    FenwickTree(int n) {
        this->n = n;
        data.resize(n);
    }

    // Add x to the element at index p
    void add(int p, int x) {
        p++;
        for (int i = p; i <= n; i += i & -i) {
            data[i - 1] += x;
        }
    }

    // Return the sum of elements in the range [l, r]
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i - 1];
        }
        return s;
    }
};

int main() {
    // Read the number of elements 'n' and the number of queries 'q' from the standard input
    int n = getInt();
    int q = getInt();

    // Initialize a Fenwick Tree of size 'n'
    FenwickTree fw(n);

    // Iterate through each element and add it to the Fenwick Tree
    for (int i = 0; i < n; i++) {
        // Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
        int a = getInt();
        fw.add(i, a);
    }

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        // Read an integer 't' from the standard input to determine the type of query
        int t = getInt();

        // If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
        if (t == 0) {
            int p = getInt();
            int x = getInt();
            fw.add(p, x);
        } else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
            int l = getInt();
            int r = getInt();
            // Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
            out(fw.sum(l, r));
        }
    }

    return 0;
}

