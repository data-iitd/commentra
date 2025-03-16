#include <bits/stdc++.h>

using namespace std;

// out is a utility function to print output to the console.
void out(int x) {
	cout << x << endl;
}

// Initialize a new scanner to read input from standard input.
istream& operator>>(istream& is, BIT& bit) {
	int n, q;
	is >> n >> q;
	bit = BIT(n);
	for (int i = 0; i < n; i++) {
		int a;
		is >> a;
		bit.Add(i, a);
	}
	return is;
}

// getInt reads an integer from input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
	int x;
	cin >> x;
	return x;
}

// getString reads a string from input and returns it.
string getString() {
	string s;
	cin >> s;
	return s;
}

int main() {
	// Set the scanner to split input by whitespace and allocate a large buffer.
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin.rdbuf()->pubsetbuf(new char[1000000], 1000000);

	// Read the number of elements (n) and the number of queries (q).
	int n, q;
	cin >> n >> q;

	// Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
	BIT bit(n);

	// Read n integers and add them to the Fenwick Tree.
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		bit.Add(i, a);
	}

	// Process q queries.
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t; // Read the type of query.
		if (t == 0) {
			// For update queries, read position (p) and value (x) and update the Fenwick Tree.
			int p, x;
			cin >> p >> x;
			bit.Add(p, x);
		} else {
			// For sum queries, read the range (l, r) and output the sum from l to r.
			int l, r;
			cin >> l >> r;
			out(bit.Sum(l, r));
		}
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
struct BIT {
	int n; // Number of elements in the tree
	vector<int> data; // Array to store the tree data
};

// FenwickTree initializes a new Binary Indexed Tree with n elements.
BIT FenwickTree(int n) {
	BIT ret;
	ret.n = n;
	ret.data = vector<int>(n); // Create a slice to hold the tree data
	return ret;
}

// Add updates the Fenwick Tree by adding x to the element at position p.
void Add(BIT& bit, int p, int x) {
	p++; // Increment p to match the 1-based index used in Fenwick Tree
	for (int i = p; i <= bit.n; i += i & -i) {
		bit.data[i-1] += x; // Update the tree data
	}
}

// Sum calculates the sum of elements in the range [l, r).
int Sum(BIT& bit, int l, int r) {
	return Sum(bit, r) - Sum(bit, l); // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
int Sum(BIT& bit, int r) {
	int s = 0; // Initialize sum
	for (int i = r; i > 0; i -= i & -i) {
		s += bit.data[i-1]; // Add the value at index r-1
	}
	return s; // Return the calculated sum
}

