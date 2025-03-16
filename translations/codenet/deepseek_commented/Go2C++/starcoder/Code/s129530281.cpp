#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new scanner that reads from the given file pointer.
auto getScanner(FILE* fp) {
	return make_shared<stringstream>(ios_base::in | ios_base::out);
}

// getNextString reads the next word from the scanner.
string getNextString(shared_ptr<stringstream> scanner) {
	string s;
	*scanner >> s;
	return s;
}

// getNextInt converts the next word to an integer.
int getNextInt(shared_ptr<stringstream> scanner) {
	int i;
	*scanner >> i;
	return i;
}

// getNextInt64 converts the next word to a 64-bit integer.
int64_t getNextInt64(shared_ptr<stringstream> scanner) {
	int64_t i;
	*scanner >> i;
	return i;
}

// getNextUint64 converts the next word to an unsigned 64-bit integer.
uint64_t getNextUint64(shared_ptr<stringstream> scanner) {
	uint64_t i;
	*scanner >> i;
	return i;
}

// getNextFloat64 converts the next word to a floating-point number.
double getNextFloat64(shared_ptr<stringstream> scanner) {
	double i;
	*scanner >> i;
	return i;
}

// Segment struct represents a segment tree and includes methods to initialize it and update/query it.
struct Segment {
	int n, h, i, chunk;
	vector<int> unit;
	vector<vector<int>> bucket;

	// init initializes the segment tree with a given size n.
	void init(int n) {
		this->n = n;
		unit.push_back(1);
		bucket.push_back(vector<int>(n));

		chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n-1)/chunk + 1;
			bucket.push_back(vector<int>(n));
			unit.push_back(unit[i]*chunk);
		}
		h = unit.size();
		i = 0;
	}

	// maximize updates the value at a given index in the segment tree.
	void maximize(int index, int value) {
		bucket[0][index] = value;
		for (i = 0; i < h-1; i++) {
			int s = index - index%chunk;
			int t = s + chunk;
			if (t > bucket[i].size()) {
				t = bucket[i].size();
			}
			int parent = index / chunk;
			int max = 0;
			for (int j = s; j < t; j++) {
				if (max < bucket[i][j]) {
					max = bucket[i][j];
				}
			}
			bucket[i+1][parent] = max;
			index /= chunk;
		}
	}

	// top returns the index of the maximum value in the segment tree.
	int top() {
		int index = 0;
		for (i = h - 2; i >= 0; i--) {
			int s = index * chunk;
			int t = s + chunk;
			if (t > bucket[i].size()) {
				t = bucket[i].size();
			}
			for (int j = s; j < t; j++) {
				if (bucket[i][j] == bucket[i+1][index]) {
					index = j;
					break;
				}
			}
		}

		return index;
	}
};

// Main function handles file input, initializes a segment tree, and processes the input to compute an answer.
int main() {
	auto scanner = getScanner(stdin);
	auto writer = make_shared<stringstream>(ios_base::in | ios_base::out);

	// Read the number of elements (n) and the number of operations (m).
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Initialize the segment tree.
	Segment seg;
	seg.init(n);

	// Populate the segment tree with initial values.
	for (int i = 0; i < n; i++) {
		seg.maximize(i, getNextInt(scanner));
	}

	// Perform the specified number of operations on the segment tree.
	for (int i = 0; i < m; i++) {
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1);
	}

	// Calculate the sum of the values in the root bucket of the segment tree.
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += int64_t(seg.bucket[0][i]);
	}

	// Write the result to the standard output.
	*writer << ans << endl;
	cout << *writer.get();
	return 0;
}

