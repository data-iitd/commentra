
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Segment type represents a segment tree data structure
struct Segment {
	int n, h, i, chunk;
	vector<int> unit;
	vector<vector<int>> bucket;

	// init function initializes the Segment struct with the given size n
	void init(int n) {
		this->n = n;
		this->unit.push_back(1);
		this->bucket.push_back(vector<int>(n));

		// Calculate the chunk size for the segment tree
		chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n - 1) / chunk + 1;
			this->bucket.push_back(vector<int>(n));
			this->unit.push_back(this->unit[i] * chunk);
		}
		h = this->unit.size();
	}

	// maximize function updates the segment tree with the given index and value
	void maximize(int index, int value) {
		// Update the leaf node with the given index and value
		this->bucket[0][index] = value;

		// Propagate the update to the parent nodes
		for (i = 0; i < h - 1; i++) {
			int s = index - index % chunk;
			int t = s + chunk;
			if (t > this->bucket[i].size()) {
				t = this->bucket[i].size();
			}
			int parent = index / chunk;
			int max = 0;
			for (int i = s; i < t; i++) {
				if (max < this->bucket[i][i]) {
					max = this->bucket[i][i];
				}
			}
			this->bucket[i + 1][parent] = max;
			index /= chunk;
		}
	}

	// top function returns the index of the maximum value in the current segment
	int top() {
		int index = 0;
		for (i = h - 2; i >= 0; i--) {
			int s = index * chunk;
			int t = s + chunk;
			if (t > this->bucket[i].size()) {
				t = this->bucket[i].size();
			}
			for (int i = s; i < t; i++) {
				if (this->bucket[i][i] == this->bucket[i + 1][index]) {
					index = i;
					break;
				}
			}
		}

		return index;
	}
};

// getScanner function returns a bufio.Scanner instance configured for reading words
bufio::Scanner getScanner(ifstream *fp) {
	bufio::Scanner scanner(fp);
	scanner.split(bufio::ScanWords);
	scanner.buffer(make_unique<char[]>(500001), 500000); // Buffer size for efficient reading
	return scanner;
}

// getNextString function returns the next word as a string
string getNextString(bufio::Scanner *scanner) {
	scanner->scan();
	return scanner->text();
}

// getNextInt function returns the next integer from the scanner
int getNextInt(bufio::Scanner *scanner) {
	return stoi(getNextString(scanner));
}

// getNextInt64 function returns the next 64-bit integer from the scanner
int64_t getNextInt64(bufio::Scanner *scanner) {
	return stoll(getNextString(scanner));
}

// getNextUint64 function returns the next 64-bit unsigned integer from the scanner
uint64_t getNextUint64(bufio::Scanner *scanner) {
	return stoull(getNextString(scanner));
}

// getNextFloat64 function returns the next 64-bit floating-point number from the scanner
double getNextFloat64(bufio::Scanner *scanner) {
	return stod(getNextString(scanner));
}

// main function is the entry point of the program
int main() {
	// Open the standard input file if a command-line argument is provided
	ifstream fp;
	if (argc > 1) {
		fp.open(argv[1]);
	}

	// Initialize a bufio.Writer for formatted output
	bufio::Writer writer(cout.rdbuf());

	// Read the first two integers from the input
	int n = getNextInt(&getScanner(&fp));
	int m = getNextInt(&getScanner(&fp));

	// Initialize the Segment struct with the given size n
	Segment seg;
	seg.init(n);

	// Process the input data by maximizing the segments
	for (int i = 0; i < n; i++) {
		seg.maximize(i, getNextInt(&getScanner(&fp)));
	}
	for (int i = 0; i < m; i++) {
		seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
	}

	// Calculate the answer and print it to the output
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += seg.bucket[0][i];
	}

	// Print the answer to the output
	writer.println(ans);

	// Flush the writer buffer to ensure all data is written
	writer.flush();

	return 0;
}

