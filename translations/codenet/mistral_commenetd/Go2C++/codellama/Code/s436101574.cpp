
#include <bits/stdc++.h>

using namespace std;

// Function to read a single string
string scanString() {
	string s;
	getline(cin, s);
	return s;
}

// Function to read a single rune
vector<rune> scanRunes() {
	string s = scanString();
	vector<rune> res;
	for (int i = 0; i < s.length(); i++) {
		res.push_back(s[i]);
	}
	return res;
}

// Function to read a single integer
int scanInt() {
	int a;
	cin >> a;
	return a;
}

// Function to read a single integer64
int64_t scanInt64() {
	int64_t a;
	cin >> a;
	return a;
}

// Function to read a single float64
double scanFloat64() {
	double a;
	cin >> a;
	return a;
}

// Function to read multiple integers
vector<int> scanInts(int n) {
	vector<int> res;
	for (int i = 0; i < n; i++) {
		res.push_back(scanInt());
	}
	return res;
}

// Function to print debug information
void debug(string a) {
	cout << a << endl;
}

// Function to get absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Function to get minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to get maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Main function
int main() {
	// Reading input strings s and t
	vector<rune> s = scanRunes();
	vector<rune> t = scanRunes();

	// Initializing an empty vector to store answers
	vector<string> ans;

	// Iterating through all possible substrings of s that have the same length as t
	for (int i = 0; i < s.size() - t.size() + 1; i++) {
		// Initializing a vector to store the modified string s
		vector<rune> ss = s;

		// Checking if the current substring matches the pattern t
		bool f = true;
		for (int j = 0; j < t.size(); j++) {
			// If the current character of s does not match the current character of t or is not '?'
			if (ss[i + j] != t[j] && ss[i + j] != '?') {
				// Setting flag to false and breaking the loop
				f = false;
				break;
			} else {
				// Replacing the current character of s with the corresponding character of t
				ss[i + j] = t[j];
			}
		}
		// If the current substring matches the pattern t
		if (f) {
			// Appending the modified string to the answer vector
			ans.push_back(string(ss.begin() + i, ss.begin() + i + t.size()));
		}
	}
	// Sorting the answer vector in ascending order
	sort(ans.begin(), ans.end());
	// Checking if the answer vector is empty
	if (ans.size() == 0) {
		// Printing "UNRESTORABLE" if the answer vector is empty
		cout << "UNRESTORABLE" << endl;
	} else {
		// Printing the first element of the answer vector
		cout << ans[0] << endl;
	}
	return 0;
}

