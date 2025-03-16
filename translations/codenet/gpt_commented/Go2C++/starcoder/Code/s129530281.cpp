#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new scanner for reading from the provided file pointer.
auto getScanner(FILE *fp) {
	return make_shared<stringstream>(stringstream(ios::in | ios::out));
}

// getNextString retrieves the next string from the scanner.
auto getNextString(shared_ptr<stringstream> scanner) {
	return getline(*scanner,'','', ios_base::sync_with_stdio(false));
}

// getNextInt retrieves the next integer from the scanner.
auto getNextInt(shared_ptr<stringstream> scanner) {
	int i;
	*scanner >> i;
	return i;
}

// getNextInt64 retrieves the next int64 from the scanner.
auto getNextInt64(shared_ptr<stringstream> scanner) {
	int64_t i;
	*scanner >> i;
	return i;
}

// getNextUint64 retrieves the next uint64 from the scanner.
auto getNextUint64(shared_ptr<stringstream> scanner) {
	uint64_t i;
	*scanner >> i;
	return i;
}

// getNextFloat64 retrieves the next float64 from the scanner.
auto getNextFloat64(shared_ptr<stringstream> scanner) {
	double i;
	*scanner >> i;
	return i;
}

int main() {
	// Determine the input source: either standard input or a file specified as a command-line argument
	auto fp = fopen(argc > 1? argv[1] : "input.txt", "r");
	auto scanner = getScanner(fp); // Initialize the scanner for the input source
	auto writer = make_shared<stringstream>(stringstream(ios::in | ios::out)); // Create a buffered writer for output

	// Read the number of elements and operations
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Initialize the Segment structure
	Segment seg;
	seg.init(n); // Initialize the segment with size n

	// Populate the segment with initial values
	for (int i = 0; i < n; i++) {
		seg.maximize(i, getNextInt(scanner)); // Maximize the segment with the input values
	}

	// Perform m operations to maximize the segment
	for (int i = 0; i < m; i++) {
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1); // Maximize using the top value and half of the last bucket's first element
	}

	// Calculate the final answer by summing up the values in the first bucket
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += int64_t(seg.bucket[0][i]); // Accumulate the values
	}

	// Output the final result
	*writer << ans << endl;
	cout << *writer.get(); // Flush the buffered writer to ensure all output is written
}

// Segment structure to hold the segment data and operations
struct Segment {
	int n, h, i, chunk;
	vector<int> unit;
	vector<vector<int>> bucket;

	// init initializes the segment structure with the given size n.
	void init(int n) {
		this->n = n;
		unit.push_back(1); // Initialize unit array
		bucket.push_back(vector<int>(n));

		chunk = 8; // Define the chunk size
		for (int i = 0; n > 1; i++) {
			n = (n-1)/chunk + 1; // Reduce n based on the chunk size
			bucket.push_back(vector<int>(n)); // Append a new bucket
			unit.push_back(unit[i]*chunk); // Update unit array
		}
		h = unit.size(); // Set the height of the segment
		chunk = chunk; // Set the chunk size
	}

	// maximize updates the segment at a given index with a new value.
	void maximize(int index, int value) {
		bucket[0][index] = value; // Set the value in the first bucket
		for (i = 0; i < h-1; i++) {
			int s = index - index%chunk; // Calculate the start of the current chunk
			int t = s + chunk; // Calculate the end of the current chunk
			if (t > bucket[i].size()) {
				t = bucket[i].size(); // Adjust end if it exceeds the bucket length
			}
			int parent = index / chunk; // Determine the parent index
			int max = 0; // Initialize max value
			for (int i = s; i < t; i++) {
				if (max < bucket[i]) {
					max = bucket[i]; // Find the maximum value in the current chunk
				}
			}
			bucket[i+1][parent] = max; // Update the parent bucket with the maximum value
			index /= chunk; // Move to the parent index for the next iteration
		}
	}

	// top retrieves the index of the top value in the segment.
	int top() {
		int index = 0; // Start from the root index
		for (i = h - 2; i >= 0; i--) {
			int s = index * chunk; // Calculate the start of the current chunk
			int t = s + chunk; // Calculate the end of the current chunk
			if (t > bucket[i].size()) {
				t = bucket[i].size(); // Adjust end if it exceeds the bucket length
			}
			for (int i = s; i < t; i++) {
				if (bucket[i] == bucket[i+1][index]) {
					index = i; // Update index if the value matches the top value
					break;
				}
			}
		}

		return index; // Return the index of the top value
	}
};

