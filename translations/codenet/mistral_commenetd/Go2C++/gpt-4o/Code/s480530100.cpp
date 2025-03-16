#include <iostream>
#include <vector>

using namespace std;

// A helper function to print output
void out(int x) {
    cout << x << endl;
}

// Fenwick Tree (Binary Indexed Tree) class
class BIT {
public:
    BIT(int n) : n(n), data(n, 0) {}

    void Add(int p, int x) {
        p++;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    int Sum(int l, int r) {
        return sum(r) - sum(l);
    }

private:
    int n;
    vector<int> data;

    int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

// Function to read an integer from the standard input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Main function
int main() {
    // Read the number of elements 'n' and the number of queries 'q' from the standard input
    int n = getInt(), q = getInt();

    // Initialize a Fenwick Tree of size 'n'
    BIT fw(n);

    // Iterate through each element and add it to the Fenwick Tree
    for (int i = 0; i < n; i++) {
        // Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
        int a = getInt();
        fw.Add(i, a);
    }

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        // Read an integer 't' from the standard input to determine the type of query
        int t = getInt();

        // If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
        if (t == 0) {
            int p = getInt(), x = getInt();
            fw.Add(p, x);
        } else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
            int l = getInt(), r = getInt();
            out(fw.Sum(l, r));
        }
    }

    return 0;
}

// <END-OF-CODE>
