
#include <bits/stdc++.h>
using namespace std;

// Initialize scanner and writer for input and output
#define sc cin
#define wr cout

// Function to scan a single string from input
string scanString() {
	string s;
	getline(sc, s);
	return s;
}

// Function to scan a slice of runes from input
vector<char> scanRunes() {
	string s = scanString();
	vector<char> res;
	for (char c : s) {
		res.push_back(c);
	}
	return res;
}

// Function to scan a single integer from input
int scanInt() {
	int a;
	sc >> a;
	return a;
}

// Function to scan a single int64 from input
long long scanInt64() {
	long long a;
	sc >> a;
	return a;
}

// Function to scan a single float64 from input
double scanFloat64() {
	double a;
	sc >> a;
	return a;
}

// Function to scan n integers from input and return them as a slice
vector<int> scanInts(int n) {
	vector<int> res;
	for (int i = 0; i < n; i++) {
		res.push_back(scanInt());
	}
	return res;
}

// Debug function to print messages to stderr
void debug(vector<string> a) {
	for (string s : a) {
		cerr << s << endl;
	}
}

// Function to return the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Function to return the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Main function where the program execution begins
int main() {
	// Ensure the buffered writer flushes its content before exiting
	wr.sync_with_stdio(false);

	// Read the first string of runes (s)
	vector<char> s = scanRunes();
	// Read the second string of runes (t)
	vector<char> t = scanRunes();

	// Initialize a vector to hold possible answers
	vector<string> ans;
	
	// Iterate through the first string to find occurrences of the second string
	for (int i = 0; i < s.size()-t.size()+1; i++) {
		bool f = true; // Flag to check if the current position is valid
		vector<char> ss = s; // Create a copy of the original string
		// Check if the substring of s can match t
		for (int j = 0; j < t.size(); j++) {
			// If characters do not match and are not '?', set flag to false
			if (s[i+j]!= t[j] && s[i+j]!= '?') {
				f = false;
				break;
			} else {
				// Replace '?' with the corresponding character from t
				ss[i+j] = t[j];
			}
		}
		// If the substring matched, replace remaining '?' with 'a' and store the result
		if (f) {
			string res = "";
			for (char c : ss) {
				if (c == '?') {
					res += 'a';
				} else {
					res += c;
				}
			}
			ans.push_back(res);
		}
	}

	// Sort the possible answers
	sort(ans.begin(), ans.end());

	// Output the result: either the first valid answer or "UNRESTORABLE"
	if (ans.empty()) {
		wr << "UNRESTORABLE" << endl;
	} else {
		wr << ans[0] << endl;
	}
}

