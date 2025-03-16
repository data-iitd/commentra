
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// getNextString retrieves the next string from the scanner.
string getNextString(istream& scanner) {
	string s;
	scanner >> s;
	return s;
}

// getNextInt retrieves the next integer from the scanner.
int getNextInt(istream& scanner) {
	int i;
	scanner >> i;
	return i;
}

// getNextInt64 retrieves the next int64 from the scanner.
int64_t getNextInt64(istream& scanner) {
	int64_t i;
	scanner >> i;
	return i;
}

// getNextUint64 retrieves the next uint64 from the scanner.
uint64_t getNextUint64(istream& scanner) {
	uint64_t i;
	scanner >> i;
	return i;
}

// getNextFloat64 retrieves the next float64 from the scanner.
double getNextFloat64(istream& scanner) {
	double i;
	scanner >> i;
	return i;
}

// root function finds the root of the given index using path compression.
int root(int i, vector<int>& uni) {
	if (i == uni[i]) {
		return i; // Return if the index is its own root
	}

	uni[i] = root(uni[i], uni); // Path compression
	return uni[i]; // Return the root
}

// MP struct holds the string and its pattern matching table.
struct MP {
	string s;
	vector<int> table;

	// init initializes the pattern matching table for the string.
	void init(string s) {
		this->s = s;
		int n = s.length();
		vector<int> table(n+1, -1); // Initialize the table
		int j = -1;
		for (int i = 0; i < n; i++) {
			for (; j >= 0 && s[i] != s[j]; j = table[j]);
			j++;
			table[i+1] = j; // Fill the table with the length of the longest prefix
		}
		this->table = table; // Assign the completed table to the MP struct
	}
};

int main() {
	// Initialize file pointers for input and output
	ifstream fp(getenv("MASPY") ? getenv("MASPY") : ""); // Open specified input file
	ofstream wfp(getenv("MASPYPY") ? getenv("MASPYPY") : ""); // Create specified output file

	// Create a scanner for reading input and a writer for output
	istream& scanner = fp;
	ostream& writer = wfp;

	// Read two strings from input
	string s = getNextString(scanner);
	string t = getNextString(scanner);

	// Calculate lengths of the input strings
	int ns = s.length();
	int nt = t.length();

	// Create a slice to hold repeated instances of string s
	vector<string> ss(nt/ns+1);
	for (int i = 0; i < ss.size(); i++) {
		ss[i] = s; // Fill the slice with string s
	}

	// Concatenate the repeated strings to form a new string
	string sss = ss[0] + ss[0];

	// Initialize a boolean slice to track matches
	vector<bool> ok(ns);

	// Initialize a unique index array and a pattern matching structure
	vector<int> uni(ns);
	MP mp;
	mp.init(t); // Initialize the pattern matching table with string t
	int m = 0;
	for (int i = 0; i < ns; i++) {
		uni[i] = i; // Set each index to itself initially
	}
	bool o;

	// Check for matches of string t in the concatenated string sss
	for (int i = 0; i < ns; i++) {
		o = true;
		for (m = 0; m < nt; m++) {
			if (t[m] != sss[i+m]) { // Compare characters
				o = false;
				break;
			}
		}
		ok[i] = o; // Store the result of the match
		if (o) {
			i += nt - mp.table[m]; // Update index based on the pattern table
			m = mp.table[m]; // Update match index
		}
		for (; m >= 0 && t[m] != sss[i+m]; m = mp.table[m]);
		i--; // Adjust index for the next iteration
		m++; // Move to the next character
	}

	// Calculate the answer based on the matches found
	int ans = 0;
	int r, rr;
	for (int i = 0; i < ns; i++) {
		if (!ok[i]) {
			continue; // Skip if no match
		}
		if (!ok[(i+nt)%ns]) {
			continue; // Skip if no match for the next index
		}
		r = root(i, uni); // Find the root of the current index
		rr = root((i+nt)%ns, uni); // Find the root of the next index
		if (rr == r) {
			writer << -1 << endl; // Output -1 if they are in the same component
			return 0;
		}
		uni[rr] = r; // Union the two components
	}

	// Count the number of matches for each unique root
	vector<int> counter(ns);
	for (int i = 0; i < ns; i++) {
		if (!ok[i]) {
			continue; // Skip if no match
		}
		r = root(i, uni); // Find the root for the current index
		counter[r]++; // Increment the count for the root
	}
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i]; // Update the answer with the maximum count
		}
	}

	// Output the final answer
	writer << ans << endl;

	return 0;
}

