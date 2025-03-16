
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;

// Initialize a new scanner to read input from standard input
istream& sc = cin;

// Scanner function reads a line of input and returns it as a string
string Scanner() {
	string s;
	sc >> s;
	return s;
}

// intScanner function reads an integer from input and returns it
int intScanner() {
	int n;
	sc >> n;
	return n;
}

// floatScanner function reads a float64 from input and returns it
float floatScanner() {
	float n;
	sc >> n;
	return n;
}

// stringToInt converts a string to an integer
int stringToInt(string s) {
	int n;
	n = stoi(s);
	return n;
}

// Declare a variable for the modulus value
int mod;

int main() {
	// Set the modulus value to 1000000007
	mod = 1000000007;
	
	// Create a buffer for the scanner with a size limit defined by mod
	char buf[mod];
	sc.rdbuf()->pubsetbuf(buf, mod);
	
	// Set the scanner to split input by whitespace
	sc.imbue(locale(locale(), new myctype));
	
	// Read the number of elements
	int n = intScanner();
	
	// Initialize a vector to hold the integers
	vector<int> as(n);
	
	// Read n integers from input
	for (int i = 0; i < n; i++) {
		as[i] = intScanner();
	}
	
	// Initialize a vector to hold the unique sorted integers
	vector<int> xs(1, as[0]);
	
	// Iterate through the input integers starting from the second element
	for (int j = 1; j < n; j++) {
		// Use binary search to find the position to insert the current integer
		int idx = lower_bound(xs.begin(), xs.end(), as[j]) - xs.begin();
		
		// If the index is equal to the length of xs, append the integer
		if (idx == xs.size()) {
			xs.push_back(as[j]);
		} else {
			// Otherwise, replace the existing integer at the found index
			xs[idx] = as[j];
		}
	}
	
	// Print the number of unique integers found
	cout << xs.size() << endl;
	
	return 0;
}

// Define a custom ctype class to split input by whitespace
class myctype : public ctype<char> {
public:
	myctype() : ctype<char>(0) {}
	virtual ~myctype() {}
	
	virtual bool is(mask m, char c) const {
		switch (m) {
			case space:
				return isspace(c);
			case print:
				return isprint(c);
			case cntrl:
				return iscntrl(c);
			case upper:
				return isupper(c);
			case lower:
				return islower(c);
			case alpha:
				return isalpha(c);
			case digit:
				return isdigit(c);
			case punct:
				return ispunct(c);
			case xdigit:
				return isxdigit(c);
			case alnum:
				return isalnum(c);
			case graph:
				return isgraph(c);
			default:
				return false;
		}
	}
	
	virtual const char* name() const {
		return "myctype";
	}
};

