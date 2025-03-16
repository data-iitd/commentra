#include <bits/stdc++.h>

using namespace std;

// Constants and global variables
const int mod = 1000000007;

// Function to read input
int nextInt() {
	int x;
	cin >> x;
	return x;
}

int main() {
	// Reading the first two integers h and n
	int h = nextInt();
	int n = nextInt();

	// Initializing variable a to 0
	int a = 0;

	// Iterating through the array of size n and adding each integer to variable a
	for (int i = 0; i < n; i++) {
		a += nextInt();
	}

	// Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
	if (h > a) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
}

