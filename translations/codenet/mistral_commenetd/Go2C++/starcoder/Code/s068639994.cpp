
#include <bits/stdc++.h>

using namespace std;

// -----------------------------------------

// mainFn is the main function of the program
void mainFn() {
	// Get the number of elements in the input array
	int n = getInt();
	// Get the input array
	vector<int> ls = getIntSlice(n);
	// Create a reversed copy of the input array
	vector<int> lsRev(n);
	// Copy the input array to the reversed copy
	copy(ls.begin(), ls.end(), lsRev.begin());
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
			int r = n - lower_bound(lsRev.begin(), lsRev.end(), y);
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
}

// min returns the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// max returns the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// -----------------------------------------

// Initialize some variables for reading and writing input/output
int main() {
	// Set the buffer size for reading input
	//cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// Set the splitting function for reading input
	cin.tie(0);
	// Call the main function
	mainFn();
	// Flush the writer buffer
	return 0;
}

// getInt reads an integer from the standard input
int getInt() {
	int n;
	cin >> n;
	return n;
}

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

// getString reads a string from the standard input
string getsString() {
	string s;
	getline(cin, s);
	return s;
}

// puts writes the given arguments to the standard output, followed by a newline character
void puts(int a) {
	cout << a << endl;
}

