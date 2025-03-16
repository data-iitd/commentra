#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new Scanner to read from a file pointer.
// It sets the split function to ScanWords and buffers to 500001 bytes.
auto getScanner(FILE *fp) {
	return make_shared<Scanner>(fp, bufsize(500001), split(ScanWords));
}

// getNextString reads the next token from the Scanner and returns it as a string.
auto getNextString(Scanner &scanner) {
	scanner.Scan();
	return scanner.Text();
}

// getNextInt reads the next token as a string, converts it to an integer, and returns it.
auto getNextInt(Scanner &scanner) {
	return atoi(getNextString(scanner).c_str());
}

// getNextInt64 reads the next token as a string, converts it to an int64, and returns it.
auto getNextInt64(Scanner &scanner) {
	return atoll(getNextString(scanner).c_str());
}

// getNextUint64 reads the next token as a string, converts it to a uint64, and returns it.
auto getNextUint64(Scanner &scanner) {
	return stoull(getNextString(scanner).c_str());
}

// getNextFloat64 reads the next token as a string, converts it to a float64, and returns it.
auto getNextFloat64(Scanner &scanner) {
	return stod(getNextString(scanner).c_str());
}

// main function handles file input/output based on command-line arguments.
// It reads integers from the specified file or standard input, sorts them,
// and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
int main() {
	auto fp = fopen(argc > 1? argv[1] : "input.txt", "r");
	auto wfp = fopen(argc > 2? argv[2] : "output.txt", "w");
	auto scanner = getScanner(fp);
	auto writer = make_shared<Writer>(wfp);

	// Read the number of elements.
	auto n = getNextInt(scanner);
	auto ll = make_shared<vector<int>>(n);

	// Read n integers into the slice ll.
	for (auto i = 0; i < n; i++) {
		(*ll)[i] = getNextInt(scanner);
	}

	// Sort the slice ll.
	sort(ll->begin(), ll->end());

	// Initialize the answer variable.
	auto ans = 0;

	// Iterate through possible triplets (i, j, m) where i < j < m.
	for (auto i = 0; i < n-2; i++) {
		for (auto j = i + 1; j < n-1; j++) {
			auto l = j + 1;
			auto r = n;
			while (l < r) {
				auto m = (l + r) >> 1;
				if ((*ll)[m] < (*ll)[i]+(*ll)[j]) {
					l = m + 1;
					continue;
				}
				r = m;
			}

			// Add the number of valid m's to the answer.
			ans += l - (j + 1);
		}
	}

	// Print the final answer to the standard output.
	fmt::Fprintln(writer, ans);

	// Flush the writer to ensure all data is written to the file or standard output.
	writer->Flush();
}

