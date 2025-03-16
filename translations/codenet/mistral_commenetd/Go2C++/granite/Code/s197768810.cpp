

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cassert>
#include <random>
#include <chrono>

using namespace std;

// Function to read an integer from standard input
int readInt() {
	int x;
	cin >> x;
	return x;
}

// Function to read a float from standard input
float readFloat() {
	float x;
	cin >> x;
	return x;
}

// Function to read a string from standard input
string readString() {
	string x;
	cin >> x;
	return x;
}

// Main function
int main() {
	// Read the number of elements n and the number of queries m from standard input
	int n, m;
	cin >> n >> m;
	// Allocate an array a of size n
	vector<int> a(n);
	// Initialize a variable sum to keep track of the sum of elements in the array
	int sum = 0;
	// Process each query
	for (int i = 0; i < m; i++) {
		// Read an integer from standard input and add it to the array a
		cin >> a[i];
		// Add the current element to the sum
		sum += a[i];
		// Check if the sum is greater than the size of the array
		if (sum > n) {
			// If so, print -1 and exit the program
			cout << -1 << endl;
			return 0;
		}
	}
	// Print the result, which is the difference between the size of the array and the sum of its elements
	cout << n - sum << endl;
	return 0;
}

