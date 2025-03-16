#include <bits/stdc++.h>

using namespace std;

// Function to find the minimum of two integers.
int min(int a, int b) {
	return a < b? a : b;
}

// Function to find the maximum of two integers.
int max(int a, int b) {
	return a > b? a : b;
}

// Function to sort the given slice in ascending order.
void sortAsc(vector<int> &ls) {
	sort(ls.begin(), ls.end());
}

// Function to sort the given slice in descending order.
void sortDesc(vector<int> &ls) {
	sort(ls.begin(), ls.end(), greater<int>());
}

// Function to find the left boundary of the given range.
int leftBoundary(vector<int> &ls, int x) {
	return lower_bound(ls.begin(), ls.end(), x) - ls.begin();
}

// Function to find the right boundary of the given range.
int rightBoundary(vector<int> &ls, int x) {
	return upper_bound(ls.begin(), ls.end(), x) - ls.begin();
}

// Function to calculate the number of valid pairs.
int countPairs(vector<int> &ls, int x, int y) {
	// Find the left boundary.
	int l = leftBoundary(ls, x);
	// Find the right boundary.
	int r = rightBoundary(ls, y);
	// Calculate the number of valid pairs.
	int ans = r - l;
	// Adjust the number of valid pairs if the current indices are within the range.
	if (l <= 0) && (0 <= r) {
		ans--;
	}
	if (l <= 1) && (1 <= r) {
		ans--;
	}
	// Ensure the number of valid pairs is not negative.
	ans = max(0, ans);
	// Return the number of valid pairs.
	return ans;
}

// Main function to run the program.
int main() {
	// Read the number of elements in the slice.
	int n = getInt();
	// Read the slice of integers.
	vector<int> ls = getIntSlice(n);
	// Create a reversed version of the slice.
	vector<int> lsRev(n);
	copy(lsRev.begin(), lsRev.end(), ls.begin());
	// Sort the original slice in ascending order.
	sortAsc(ls);
	// Sort the reversed slice in descending order.
	sortDesc(lsRev);

	// Initialize the answer variable.
	int ans = 0;
	// Loop through the slice to calculate the answer.
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Calculate p and q based on the current elements.
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			// Calculate x and y based on p and q.
			int x = q - p;
			int y = q + p;

			// Find the left boundary using binary search.
			int l = leftBoundary(ls, x);
			// Find the right boundary using binary search.
			int r = rightBoundary(lsRev, y);

			// Calculate the sum of valid pairs.
			int sum = r - l;
			// Adjust the sum if the current indices are within the range.
			if (i >= l) && (i <= r) {
				sum--;
			}
			if (j >= l) && (j <= r) {
				sum--;
			}
			// Ensure the sum is not negative.
			sum = max(0, sum);
			// Add the sum to the answer.
			ans += sum;
		}
	}

	// Divide the answer by 3 to get the final result.
	ans /= 3;
	// Print the final answer.
	puts(ans);
}

// Helper function to read an integer from the standard input.
int getInt() {
	int n;
	cin >> n;
	return n;
}

// Helper function to read a slice of integers from the standard input.
vector<int> getIntSlice(int n) {
	vector<int> ls(n);
	for (int i = 0; i < n; i++) {
		ls[i] = getInt();
	}
	return ls;
}

// Helper function to print the given arguments to the standard output.
void puts(int a, int b, int c) {
	cout << a << " " << b << " " << c << endl;
}

// Helper function to print the given arguments to the standard output.
void puts(int a, int b) {
	cout << a << " " << b << endl;
}

// Helper function to print the given arguments to the standard output.
void puts(int a) {
	cout << a << endl;
}

// 