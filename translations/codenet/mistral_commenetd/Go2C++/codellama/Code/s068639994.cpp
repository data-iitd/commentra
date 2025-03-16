
#include <bits/stdc++.h>

using namespace std;

// Go:
// Package main is the entry point of the program
int main() {
	// Get the number of elements in the input array
	int n = getInt();
	// Get the input array
	vector<int> ls = getIntSlice(n);
	// Create a reversed copy of the input array
	vector<int> lsRev(n);
	// Copy the input array to the reversed copy
	copy(lsRev.begin(), lsRev.end(), ls.begin());
	// Sort the input array in ascending order
	sort(ls.begin(), ls.end());
	// Sort the reversed copy of the array in descending order
	sort(lsRev.begin(), lsRev.end(), greater<int>());

	// Initialize the answer variable
	int ans = 0;
	// Iterate through all pairs of elements in the array
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Find the minimum and maximum elements of the current pair
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			// Calculate the difference between the maximum and minimum elements
			int x = q - p;
			int y = q + p;
			// Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
			int l = lower_bound(ls.begin(), ls.end(), x) - ls.begin();
			int r = n - (upper_bound(lsRev.begin(), lsRev.end(), y) - lsRev.begin());
			// Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
			int sum = r - l;
			// Check if the current pair lies within the range [l, r]
			if (i >= l && i <= r) {
				sum--;
			}
			if (j >= l && j <= r) {
				sum--;
			}
			// Ensure that the sum is not negative
			sum = max(0, sum);
			// Add the sum to the answer variable
			ans += sum;
		}
	}
	// Divide the answer by 3 and print it
	ans /= 3;
	puts(ans);
	return 0;
}

// Go:
// getInt reads an integer from the standard input
int getInt() {
	int i;
	cin >> i;
	return i;
}

// Go:
// getIntSlice reads an array of integers from the standard input
vector<int> getIntSlice(int n) {
	// Allocate memory for the array
	vector<int> is(n);
	// Read each element of the array from the standard input
	for (int i = 0; i < n; i++) {
		cin >> is[i];
	}
	// Return the array
	return is;
}

// Go:
// getString reads a string from the standard input
string getsString() {
	string s;
	cin >> s;
	return s;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a) {
	cout << a << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a) {
	cout << a << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b) {
	cout << a << " " << b << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b) {
	cout << a << " " << b << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b) {
	cout << a << " " << b << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b) {
	cout << a << " " << b << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b, int c) {
	cout << a << " " << b << " " << c << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b, string c) {
	cout << a << " " << b << " " << c << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b, int c) {
	cout << a << " " << b << " " << c << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b, string c) {
	cout << a << " " << b << " " << c << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b, string c) {
	cout << a << " " << b << " " << c << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b, int c) {
	cout << a << " " << b << " " << c << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b, int c, int d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b, string c, string d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b, string c, int d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b, string c, string d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b, string c, string d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b, int c, string d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b, int c, int d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b, int c, string d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b, int c, int d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b, string c, int d) {
	cout << a << " " << b << " " << c << " " << d << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b, string c, int d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b, string c, string d, string e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b, string c, string d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b, int c, string d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b, int c, int d, string e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b, int c, string d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b, string c, int d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b, string c, int d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b, string c, int d, string e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b, string c, int d, string e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b, string c, int d, string e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b, int c, int d, string e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, string b, int c, string d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, int b, int c, string d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a, int b, int c, string d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline character
void puts(string a, string b, string c, string d, int e) {
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}

// Go:
// puts writes the given arguments to the standard output, followed by a newline ch