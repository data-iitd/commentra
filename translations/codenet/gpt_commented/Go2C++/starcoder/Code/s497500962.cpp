#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to read the next integer from input
int nextInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function to read the next float from input
float nextFloat() {
	float x;
	scanf("%f", &x);
	return x;
}

// Function to read the next string from input
string nextString() {
	string x;
	getline(cin, x);
	return x;
}

// ---------- Input.

// Util. ----------

// Function to compute the absolute value of an integer
int abs(int x) {
	return x < 0? -x : x;
}

// Function to compute the minimum of two integers
int min(int x, int y) {
	return x < y? x : y;
}

// Function to compute the maximum of two integers
int max(int x, int y) {
	return x > y? x : y;
}

// ---------- Util.

int main() {
	// Read the values for R, G, B, and N from standard input
	int R = nextInt(); // Number of red items
	int G = nextInt(); // Number of green items
	int B = nextInt(); // Number of blue items
	int N = nextInt(); // Total number of items to choose

	int ans = 0; // Variable to store the count of valid combinations

	// Iterate over possible counts of red items (x)
	for (int x = 0; x <= N; x++) {
		// Iterate over possible counts of green items (y)
		for (int y = 0; y <= N; y++) {
			// Calculate the remaining items after choosing x red and y green
			int tmp = N - R*x - G*y;
			// Check if the remaining items can be fully represented by blue items
			if (tmp >= 0 && tmp%B == 0) {
				ans++; // Increment the count of valid combinations
			}
		}
	}

	// Output the total count of valid combinations
	printf("%d\n", ans);
}

