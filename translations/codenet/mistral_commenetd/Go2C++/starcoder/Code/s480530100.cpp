#include <bits/stdc++.h>

using namespace std;

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
	int n;
	vector<int> data;
	BIT(int n) {
		this->n = n;
		data.resize(n);
	}
	void Add(int p, int x) {
		p++;
		for ( ; p <= n; p += p & -p) {
			data[p-1] += x;
		}
	}
	int Sum(int l, int r) {
		return sum(r) - sum(l);
	}
	int sum(int r) {
		int s = 0;
		for ( ; r > 0; r -= r & -r) {
			s += data[r-1];
		}
		return s;
	}
};

// ** copy from here to your source code **

int main() {
	// Initialize the scanner for reading input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Read the number of elements 'n' and the number of queries 'q' from the standard input
	int n, q;
	cin >> n >> q;

	// Initialize a Fenwick Tree of size 'n'
	BIT fw(n);

	// Iterate through each element and add it to the Fenwick Tree
	for (int i = 0; i < n; i++) {
		// Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
		int a;
		cin >> a;
		fw.Add(i, a);
	}

	// Iterate through each query
	for (int i = 0; i < q; i++) {
		// Read an integer 't' from the standard input to determine the type of query
		int t;
		cin >> t;

		// If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			fw.Add(p, x);
		} else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
			int l, r;
			cin >> l >> r;
			// Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
			cout << fw.Sum(l, r) << endl;
		}
	}
	return 0;
}

// 