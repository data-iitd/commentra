
#include <bits/stdc++.h>

using namespace std;

// getScanner function returns a bufio.Scanner instance configured for reading words
inline istream& getScanner(istream& fp, int& n) {
	fp >> n;
	return fp;
}

// getNextString function returns the next word as a string
inline string getNextString(istream& fp) {
	string s;
	fp >> s;
	return s;
}

// getNextInt function returns the next integer from the scanner
inline int getNextInt(istream& fp) {
	int i;
	fp >> i;
	return i;
}

// getNextInt64 function returns the next 64-bit integer from the scanner
inline int64_t getNextInt64(istream& fp) {
	int64_t i;
	fp >> i;
	return i;
}

// getNextUint64 function returns the next 64-bit unsigned integer from the scanner
inline uint64_t getNextUint64(istream& fp) {
	uint64_t i;
	fp >> i;
	return i;
}

// getNextFloat64 function returns the next 64-bit floating-point number from the scanner
inline double getNextFloat64(istream& fp) {
	double i;
	fp >> i;
	return i;
}

// Segment type represents a segment tree data structure
struct Segment {
	int n, h, i, chunk;
	vector<int> unit;
	vector<vector<int>> bucket;

	// init function initializes the Segment struct with the given size n
	void init(int n) {
		this->n = n;
		unit.push_back(1);
		bucket.push_back(vector<int>(n));

		// Calculate the chunk size for the segment tree
		chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n-1)/chunk + 1;
			bucket.push_back(vector<int>(n));
			unit.push_back(unit[i]*chunk);
		}
		h = unit.size();
		i = 0;
	}

	// maximize function updates the segment tree with the given index and value
	void maximize(int index, int value) {
		// Update the leaf node with the given index and value
		bucket[0][index] = value;

		// Propagate the update to the parent nodes
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

	// top function returns the index of the maximum value in the current segment
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

// main function is the entry point of the program
int main() {
	// Open the standard input file if a command-line argument is provided
	ifstream fp;
	if (argc > 1) {
		fp.open(argv[1]);
	} else {
		fp.open("/dev/stdin");
	}

	// Initialize a bufio.Writer for formatted output
	ostream& writer = cout;

	// Read the first two integers from the input
	int n;
	getScanner(fp, n);
	int m;
	getScanner(fp, m);

	// Initialize the Segment struct with the given size n
	Segment seg;
	seg.init(n);

	// Process the input data by maximizing the segments
	for (int i = 0; i < n; i++) {
		seg.maximize(i, getNextInt(fp));
	}
	for (int i = 0; i < m; i++) {
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1);
	}

	// Calculate the answer and print it to the output
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += int64_t(seg.bucket[0][i]);
	}

	// Print the answer to the output
	cout << ans << endl;

	// Flush the writer buffer to ensure all data is written
	writer.flush();
}

