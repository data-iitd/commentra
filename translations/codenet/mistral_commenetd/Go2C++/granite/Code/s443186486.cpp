
#include <iostream>
#include <algorithm>

using namespace std;

// Helper function to calculate the number of combinations of 'n' elements taken 'r' at a time
int combi(int n, int r) {
	// Initialize the result 'c' to 1
	int c = 1;
	// Iterate from 1 to 'r' to calculate the result
	for (int i = 1; i <= r; i++) {
		// Multiply the result with the product of 'n-i+1' and the previous result
		c = c * (n - i + 1) / i;
	}
	// Return the result
	return c;
}

int main() {
	// Read the number of elements in the array from the standard input
	int n;
	cin >> n;

	// Initialize an array 'a' of size 'n' to store the input elements
	int a[n];
	for (int i = 0; i < n; i++) {
		// Read each element of the array 'a' from the standard input
		cin >> a[i];
	}

	// Initialize a slice's' of size 'n+1' to store the cumulative sum of elements in 'a'
	int s[n+1];
	for (int i = 0; i < n; i++) {
		// Calculate the cumulative sum of elements in 'a' and store it in's'
		s[i+1] = s[i] + a[i];
	}

	// Sort the slice's' in ascending order
	sort(s, s+n+1);

	// Initialize variables 'ans' and 'count' to calculate the answer
	int ans = 0;
	int count = 0;
	// Iterate through the sorted slice's' to find the answer
	for (int i = 0; i < n; i++) {
		// If the current element in's' is equal to the next element, increment 'count'
		if (s[i] == s[i+1]) {
			count++;
		} else { // If 'count' is greater than zero, calculate the number of combinations of 'count+1' elements taken 2 at a time and add it to 'ans'
			if (count > 0) {
				ans += combi(count+1, 2);
				count = 0;
			}
		}
	}
	// If 'count' is greater than zero after the loop, calculate the number of combinations of 'count+1' elements taken 2 at a time and add it to 'ans'
	if (count > 0) {
		ans += combi(count+1, 2);
	}

	// Print the answer
	cout << ans << endl;

	return 0;
}

