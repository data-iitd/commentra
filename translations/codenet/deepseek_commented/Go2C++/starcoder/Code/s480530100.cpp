#include <bits/stdc++.h>

using namespace std;

// out is a helper function to print output.
void out(const vector<int> &v) {
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}

// getInt reads a single word from the input and converts it to an integer.
int getInt() {
	int x;
	cin >> x;
	return x;
}

// getString reads a single word from the input and returns it as a string.
string getString() {
	string s;
	cin >> s;
	return s;
}

// main function is the entry point of the program.
int main() {
	// Set the buffer size for the cin stream to a large value.
	cin.tie(0)->sync_with_stdio(false);
	ios_base::sync_with_stdio(false);

	// Read the number of elements (n) and the number of queries (q).
	int n, q;
	cin >> n >> q;

	// Initialize a Fenwick Tree with n elements.
	BIT fw(n);

	// Read n elements and add them to the Fenwick Tree.
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		fw.Add(i, a);
	}

	// Process q queries.
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			// Update the value at position p by adding x to it.
			int p, x;
			cin >> p >> x;
			fw.Add(p, x);
		} else {
			// Query the sum of elements between indices l and r.
			int l, r;
			cin >> l >> r;
			out(fw.Sum(l, r));
		}
	}
}

// BIT implementation

// BIT represents the Fenwick Tree data structure.
class BIT {
public:
	int n;
	vector<int> data;

	// BIT initializes and returns a new BIT with a given size.
	BIT(int n) {
		this->n = n;
		data.resize(n);
	}

	// Add updates the value at position p by adding x to it.
	void Add(int p, int x) {
		p++; // Convert to 1-based index
		for (int i = p; i <= n; i += i & -i) {
			data[i-1] += x;
		}
	}

	// Sum calculates the sum of elements between indices l and r.
	int Sum(int l, int r) {
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

