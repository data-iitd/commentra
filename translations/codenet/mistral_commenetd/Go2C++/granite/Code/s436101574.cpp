

#include <bits/stdc++.h>
using namespace std;

// Initializing scanner and writer
#define sc cin
#define wr cout

// Function to read a single string
string scanString() {
	string s;
	getline(sc, s);
	return s;
}

// Function to read a single rune
string scanRunes() {
	return scanString();
}

// Function to read a single integer
int scanInt() {
	int a;
	sc >> a;
	return a;
}

// Function to read a single integer64
long long scanInt64() {
	long long a;
	sc >> a;
	return a;
}

// Function to read a single float64
double scanFloat64() {
	double a;
	sc >> a;
	return a;
}

// Function to read multiple integers
vector<int> scanInts(int n) {
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = scanInt();
	}
	return res;
}

// Function to print debug information
void debug(vector<string> a) {
	for (auto s : a) {
		cerr << s << endl;
	}
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Reading input strings s and t
	string s = scanRunes();
	string t = scanRunes();

	// Initializing an empty vector to store answers
	vector<string> ans;

	// Iterating through all possible substrings of s that have the same length as t
	for (int i = 0; i < s.length() - t.length() + 1; i++) {
		// Initializing a string to store the modified string s
		string ss = s;

		// Checking if the current substring matches the pattern t
		bool f = true;
		for (int j = 0; j < t.length(); j++) {
			// If the current character of s does not match the current character of t or is not '?'
			if (ss[i + j]!= t[j] && ss[i + j]!= '?') {
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
			// Replacing all '?' characters in the modified string with 'a'
			replace(ss.begin(), ss.end(), '?', 'a');
			// Appending the modified string to the answer vector
			ans.push_back(ss);
		}
	}
	// Sorting the answer vector in ascending order
	sort(ans.begin(), ans.end());
	// Checking if the answer vector is empty
	if (ans.empty()) {
		// Printing "UNRESTORABLE" if the answer vector is empty
		wr << "UNRESTORABLE" << endl;
	} else {
		// Printing the first element of the answer vector
		wr << ans[0] << endl;
	}
}

