
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// getScanner initializes a new Scanner to read from a file pointer.
// It sets the split function to ScanWords and buffers to 500001 bytes.
ifstream getScanner(ifstream *fp) {
	ifstream scanner(fp);
	scanner.rdbuf()->pubsetbuf(500001);
	return scanner;
}

// getNextString reads the next token from the Scanner and returns it as a string.
string getNextString(ifstream *scanner) {
	string token;
	*scanner >> token;
	return token;
}

// getNextInt reads the next token as a string, converts it to an integer, and returns it.
int getNextInt(ifstream *scanner) {
	string token = getNextString(scanner);
	return stoi(token);
}

// getNextInt64 reads the next token as a string, converts it to an int64, and returns it.
int64_t getNextInt64(ifstream *scanner) {
	string token = getNextString(scanner);
	return stoll(token);
}

// getNextUint64 reads the next token as a string, converts it to a uint64, and returns it.
uint64_t getNextUint64(ifstream *scanner) {
	string token = getNextString(scanner);
	return stoull(token);
}

// getNextFloat64 reads the next token as a string, converts it to a float64, and returns it.
double getNextFloat64(ifstream *scanner) {
	string token = getNextString(scanner);
	return stod(token);
}

// main function handles file input/output based on command-line arguments.
// It reads integers from the specified file or standard input, sorts them,
// and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
int main(int argc, char *argv[]) {
	ifstream fp(argv[1]);
	ofstream wfp(argv[2]);

	// Check if file paths are provided as command-line arguments.
	if (argc < 2) {
		fp = cin;
		if (argc > 1) {
			wfp = ofstream(argv[2]);
		}
	}

	ifstream scanner = getScanner(&fp);
	ofstream writer = ofstream(wfp);

	// Read the number of elements.
	int n = getNextInt(&scanner);
	vector<int> ll(n);

	// Read n integers into the slice ll.
	for (int i = 0; i < n; i++) {
		ll[i] = getNextInt(&scanner);
	}

	// Sort the slice ll.
	sort(ll.begin(), ll.end());

	// Initialize the answer variable.
	int ans = 0;

	// Iterate through possible triplets (i, j, m) where i < j < m.
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			int l = j + 1;
			int r = n;
			while (l < r) {
				int m = (l + r) >> 1;
				if (ll[m] < ll[i]+ll[j]) {
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
	writer << ans << endl;

	// Flush the writer to ensure all data is written to the file or standard output.
	writer.flush();

	return 0;
}

