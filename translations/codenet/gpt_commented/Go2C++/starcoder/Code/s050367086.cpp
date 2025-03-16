#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new scanner for reading from the provided file pointer.
auto getScanner(FILE* fp) {
	return make_shared<stringstream>(stringstream(ios::in | ios::out));
}

// getNextString retrieves the next string from the scanner.
auto getNextString(stringstream* scanner) {
	return getline(*scanner, *scanner,'');
}

// getNextInt retrieves the next integer from the scanner.
auto getNextInt(stringstream* scanner) {
	int i;
	*scanner >> i;
	return i;
}

// getNextInt64 retrieves the next int64 from the scanner.
auto getNextInt64(stringstream* scanner) {
	int64_t i;
	*scanner >> i;
	return i;
}

// getNextUint64 retrieves the next uint64 from the scanner.
auto getNextUint64(stringstream* scanner) {
	uint64_t i;
	*scanner >> i;
	return i;
}

// getNextFloat64 retrieves the next float64 from the scanner.
auto getNextFloat64(stringstream* scanner) {
	double i;
	*scanner >> i;
	return i;
}

int main() {
	// Initialize file pointers for input and output
	auto fp = fopen(getenv("MASPY"), "r");
	auto wfp = fopen(getenv("MASPYPY"), "w");

	// Check for environment variables to override input and output file pointers
	if (!fp) {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
	}
	if (!wfp) {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	// Create a scanner for reading input and a writer for output
	auto scanner = getScanner(fp);
	auto writer = make_shared<ostream>(ostream(wfp));

	// Read two strings from input
	auto s = getNextString(scanner);
	auto t = getNextString(scanner);

	// Calculate lengths of the input strings
	auto ns = s.length();
	auto nt = t.length();

	// Create a slice to hold repeated instances of string s
	auto ss = make_shared<vector<string>>(vector<string>(nt / ns + 1));
	for (int i = 0; i < ss->size(); i++) {
		ss->at(i) = s; // Fill the slice with string s
	}

	// Concatenate the repeated strings to form a new string
	auto sss = ss->front() + ss->front();

	// Initialize a boolean slice to track matches
	auto ok = make_shared<vector<bool>>(vector<bool>(ns));

	// Initialize a unique index array and a pattern matching structure
	auto uni = make_shared<vector<int>>(vector<int>(ns));
	auto mp = make_shared<MP>();
	mp->init(t); // Initialize the pattern matching table with string t
	auto m = 0;
	for (int i = 0; i < ns; i++) {
		uni->at(i) = i; // Set each index to itself initially
	}
	bool o;

	// Check for matches of string t in the concatenated string sss
	for (int i = 0; i < ns; i++) {
		o = true;
		for (m = 0; m < nt; m++) {
			if (t[m]!= sss[i + m]) { // Compare characters
				o = false;
				break;
			}
		}
		ok->at(i) = o; // Store the result of the match
		if (o) {
			i += nt - mp->table[m]; // Update index based on the pattern table
			m = mp->table[m]; // Update match index
		}
		for (m = 0; m >= 0 && t[m]!= sss[i + m]; m--) {
			i += m - mp->table[m]; // Update index if mismatch occurs
			m = mp->table[m]; // Update match index
		}
		i--; // Adjust index for the next iteration
		m++; // Move to the next character
	}

	// Calculate the answer based on the matches found
	auto ans = 0;
	auto r, rr;
	for (int i = 0; i < ns; i++) {
		if (!ok->at(i)) {
			continue; // Skip if no match
		}
		if (!ok->at((i + nt) % ns)) {
			continue; // Skip if no match for the next index
		}
		r = root(i, uni); // Find the root of the current index
		rr = root((i + nt) % ns, uni); // Find the root of the next index
		if (rr == r) {
			*writer << -1 << endl; // Output -1 if they are in the same component
			return 0;
		}
		uni->at(rr) = r; // Union the two components
	}

	// Count the number of matches for each unique root
	auto counter = make_shared<vector<int>>(vector<int>(ns));
	for (int i = 0; i < ns; i++) {
		r = root(i, uni); // Find the root for the current index
		if (!ok->at(r)) {
			continue; // Skip if no match
		}
		counter->at(r)++; // Increment the count for the root
	}
	for (int i = 0; i < ns; i++) {
		if (ans < counter->at(i)) {
			ans = counter->at(i); // Update the answer with the maximum count
		}
	}

	// Output the final answer
	*writer << ans << endl;

	return 0;
}

// root function finds the root of the given index using path compression.
auto root(int i, vector<int>* uni) {
	if (i == uni->at(i)) {
		return i; // Return if the index is its own root
	}

	uni->at(i) = root(uni->at(i), uni); // Path compression
	return uni->at(i); // Return the root
}

// MP struct holds the string and its pattern matching table.
struct MP {
	string s;
	vector<int> table;

	// init initializes the pattern matching table for the string.
	void init(string s) {
		this->s = s;
		auto n = s.length();
		table = vector<int>(n + 1);
		table[0] = -1; // Initialize the first value of the table
		auto j = -1;
		for (int i = 0; i < n; i++) {
			for (j = j; j >= 0 && s[i]!= s[j]; j = table[j]) {
				; // Update j based on the table
			}
			j++;
			table[i + 1] = j; // Fill the table with the length of the longest prefix
		}
	}
};

