
#include <bits/stdc++.h>

using namespace std;

// mainFn contains the core logic of the program
void mainFn() {
	// Read the number of elements
	int n = getInt();
	// Read the integer slice from input
	vector<int> ls = getIntSlice(n);
	// Create a reversed copy of the original slice
	vector<int> lsRev = ls;
	reverse(lsRev.begin(), lsRev.end());
	// Sort the original slice in ascending order
	sort(ls.begin(), ls.end());
	// Sort the reversed slice in descending order
	sort(lsRev.begin(), lsRev.end(), greater<int>());

	// Initialize the answer variable
	int ans = 0;
	// Iterate through all pairs of elements in the sorted slice
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Determine the minimum and maximum of the two selected elements
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			// Calculate the differences and sums needed for searching
			int x = q - p;
			int y = q + p;

			// Find the left boundary for elements greater than x
			int l = lower_bound(ls.begin(), ls.end(), x) - ls.begin();
			// Find the right boundary for elements less than y
			int r = n - (upper_bound(lsRev.begin(), lsRev.end(), y) - lsRev.begin());

			// Calculate the number of valid elements in the range
			int sum = r - l;
			// Adjust the count if the current indices are within the range
			if (i >= l) && (i <= r) {
				sum--;
			}
			if (j >= l) && (j <= r) {
				sum--;
			}
			// Ensure the sum is non-negative
			sum = max(0, sum);
			// Accumulate the result
			ans += sum;
		}
	}

	// Divide the final answer by 3 as per the problem requirements
	ans /= 3;
	// Output the result
	puts(ans);
}

// getInt reads an integer from input
int getInt() {
	int i;
	cin >> i;
	return i;
}

// getIntSlice reads a slice of integers from input
vector<int> getIntSlice(int n) {
	vector<int> is(n);
	for (int i = 0; i < n; i++) {
		is[i] = getInt();
	}
	return is;
}

// getString reads a string from input
string getString() {
	string s;
	cin >> s;
	return s;
}

// puts writes the given arguments to the output
void puts(int a) {
	cout << a << endl;
}

int main() {
	mainFn();
	return 0;
}

