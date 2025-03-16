
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT {
public:
    vector<int> data; // Array to store the tree data
    int n; // Number of elements in the tree

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    BIT(int n) : n(n), data(n) {}

    // Add updates the Fenwick Tree by adding x to the element at position p.
    void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        for (int i = p; i <= n; i += i & -i) {
            data[i-1] += x; // Update the tree data
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    int sum(int r) {
        int s = 0; // Initialize sum
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1]; // Add the value at index i-1
        }
        return s; // Return the calculated sum
    }
};

int main() {
    // Set the scanner to split input by whitespace and allocate a large buffer.
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // Read the number of elements (n) and the number of queries (q).
    int n, q;
    cin >> n >> q;

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
    BIT fw(n);

    // Read n integers and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t; // Read the type of query.
        cin >> t;
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }

    return 0;
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT {
public:
    vector<int> data; // Array to store the tree data
    int n; // Number of elements in the tree

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    BIT(int n) : n(n), data(n) {}

    // Add updates the Fenwick Tree by adding x to the element at position p.
    void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        for (int i = p; i <= n; i += i & -i) {
            data[i-1] += x; // Update the tree data
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    int sum(int r) {
        int s = 0; // Initialize sum
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1]; // Add the value at index i-1
        }
        return s; // Return the calculated sum
    }
};

int main() {
    // Set the scanner to split input by whitespace and allocate a large buffer.
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // Read the number of elements (n) and the number of queries (q).
    int n, q;
    cin >> n >> q;

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
    BIT fw(n);

    // Read n integers and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t; // Read the type of query.
        cin >> t;
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }

    return 0;
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT {
public:
    vector<int> data; // Array to store the tree data
    int n; // Number of elements in the tree

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    BIT(int n) : n(n), data(n) {}

    // Add updates the Fenwick Tree by adding x to the element at position p.
    void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        for (int i = p; i <= n; i += i & -i) {
            data[i-1] += x; // Update the tree data
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    int sum(int r) {
        int s = 0; // Initialize sum
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1]; // Add the value at index i-1
        }
        return s; // Return the calculated sum
    }
};

int main() {
    // Set the scanner to split input by whitespace and allocate a large buffer.
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // Read the number of elements (n) and the number of queries (q).
    int n, q;
    cin >> n >> q;

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
    BIT fw(n);

    // Read n integers and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t; // Read the type of query.
        cin >> t;
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }

    return 0;
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT {
public:
    vector<int> data; // Array to store the tree data
    int n; // Number of elements in the tree

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    BIT(int n) : n(n), data(n) {}

    // Add updates the Fenwick Tree by adding x to the element at position p.
    void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        for (int i = p; i <= n; i += i & -i) {
            data[i-1] += x; // Update the tree data
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    int sum(int r) {
        int s = 0; // Initialize sum
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1]; // Add the value at index i-1
        }
        return s; // Return the calculated sum
    }
};

int main() {
    // Set the scanner to split input by whitespace and allocate a large buffer.
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // Read the number of elements (n) and the number of queries (q).
    int n, q;
    cin >> n >> q;

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
    BIT fw(n);

    // Read n integers and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t; // Read the type of query.
        cin >> t;
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }

    return 0;
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT {
public:
    vector<int> data; // Array to store the tree data
    int n; // Number of elements in the tree

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    BIT(int n) : n(n), data(n) {}

    // Add updates the Fenwick Tree by adding x to the element at position p.
    void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        for (int i = p; i <= n; i += i & -i) {
            data[i-1] += x; // Update the tree data
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    int sum(int r) {
        int s = 0; // Initialize sum
        for (int i = r; i > 0; i -= i & -