
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to scan a single string from input
string scanString() {
	string s;
	cin >> s;
	return s;
}

// Function to scan a slice of runes from input
vector<char> scanRunes() {
	string s = scanString();
	vector<char> v(s.begin(), s.end());
	return v;
}

// Function to scan a single integer from input
int scanInt() {
	int a;
	cin >> a;
	return a;
}

// Function to scan a single int64 from input
int64_t scanInt64() {
	int64_t a;
	cin >> a;
	return a;
}

// Function to scan a single float64 from input
double scanFloat64() {
	double a;
	cin >> a;
	return a;
}

// Function to scan n integers from input and return them as a slice
vector<int> scanInts(int n) {
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = scanInt();
	}
	return res;
}

// Debug function to print messages to stderr
void debug(string a) {
	cerr << a << endl;
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
	// Read the first string of runes (s)
	vector<char> s = scanRunes();
	// Read the second string of runes (t)
	vector<char> t = scanRunes();

	// Initialize a slice to hold possible answers
	vector<string> ans;
	
	// Iterate through the first string to find occurrences of the second string
	for (int i = 0; i < s.size() - t.size() + 1; i++) {
		bool f = true; // Flag to check if the current position is valid
		vector<char> ss(s); // Create a copy of the original string

		// Check if the substring of s can match t
		for (int j = 0; j < t.size(); j++) {
			// If characters do not match and are not '?', set flag to false
			if (s[i+j] != t[j] && s[i+j] != '?') {
				f = false;
				break;
			} else {
				// Replace '?' with the corresponding character from t
				ss[i+j] = t[j];
			}
		}
		// If the substring matched, replace remaining '?' with 'a' and store the result
		if (f) {
			ans.push_back(string(ss.begin(), ss.end()).replace(s.size(), ss.size() - s.size(), "a"));
		}
	}

	// Sort the possible answers
	sort(ans.begin(), ans.end());

	// Output the result: either the first valid answer or "UNRESTORABLE"
	if (ans.size() == 0) {
		cout << "UNRESTORABLE" << endl;
	} else {
		cout << ans[0] << endl;
	}

	return 0;
}

