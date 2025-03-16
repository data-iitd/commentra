#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Read the next token from the input stream.
string getNextString() {
	string token;
	cin >> token;
	return token;
}

// Read the next token as an integer.
int getNextInt() {
	return stoi(getNextString());
}

// Read the next token as an int64.
int64_t getNextInt64() {
	return stoll(getNextString());
}

// Read the next token as a uint64.
uint64_t getNextUint64() {
	return stoull(getNextString());
}

// Read the next token as a float64.
double getNextFloat64() {
	return stod(getNextString());
}

int main(int argc, char* argv[]) {
	istream& fp = argc > 1 ? *new ifstream(argv[1]) : cin;
	ostream& wfp = argc > 2 ? *new ofstream(argv[2]) : cout;

	// Read the number of elements.
	int n = getNextInt();
	vector<int> ll(n);

	// Read n integers into the vector ll.
	for (int i = 0; i < n; i++) {
		ll[i] = getNextInt();
	}

	// Sort the vector ll.
	sort(ll.begin(), ll.end());

	// Initialize the answer variable.
	int ans = 0;

	// Iterate through possible triplets (i, j, m) where i < j < m.
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int l = j + 1;
			int r = n;
			while (l < r) {
				int m = (l + r) >> 1;
				if (ll[m] < ll[i] + ll[j]) {
					l = m + 1;
				} else {
					r = m;
				}
			}

			// Add the number of valid m's to the answer.
			ans += l - (j + 1);
		}
	}

	// Print the final answer to the standard output.
	wfp << ans << endl;

	return 0;
}
