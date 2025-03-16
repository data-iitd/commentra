
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Arithmetic functions

// max returns the maximum value from a list of integers
int max(int nums[], int n) {
	int m = nums[0]; // Initialize max with the first element
	for (int i = 1; i < n; i++) {
		if (m < nums[i]) {
			m = nums[i]; // Update max if a larger value is found
		}
	}
	return m;
}

// min returns the minimum value from a list of integers
int min(int nums[], int n) {
	int m = nums[0]; // Initialize min with the first element
	for (int i = 1; i < n; i++) {
		if (m > nums[i]) {
			m = nums[i]; // Update min if a smaller value is found
		}
	}
	return m;
}

// abs returns the absolute value of an integer
int abs(int x) {
	if (x > 0) {
		return x; // Return x if positive
	}
	return -x; // Return -x if negative
}

// pow computes x raised to the power of y
int pow(int x, int y) {
	int res = 1; // Initialize result
	for (int i = 0; i < y; i++) {
		res *= x; // Multiply res by x, y times
	}
	return res;
}

// Sort related types and methods

// Val struct to hold a value and its associated ID
struct Val {
	int id, num;
};

// ByNum is a type that implements sort.Interface based on the num field
struct ByNum {
	Val vals[3];
	int n;
};

// Len returns the number of elements in the collection
int ByNum::Len() { return n; }

// Less reports whether the element with index i should sort before the element with index j
bool ByNum::Less(int i, int j) { return vals[i].num < vals[j].num; }

// Swap exchanges the elements with indexes i and j
void ByNum::Swap(int i, int j) { Val tmp = vals[i]; vals[i] = vals[j]; vals[j] = tmp; }

// Main function
int main() {
	int A, B, C, K; // Declare four integers

	// Read four integers from input
	cin >> A >> B >> C >> K;

	// Determine the maximum value among A, B, and C
	int ma = max({ A, B, C }, 3);
	int rest = 0; // Initialize the rest variable to hold the sum of the other two values

	// Calculate the sum of the two smaller values
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}

	// Double the maximum value K times
	for (int i = 1; i <= K; i++) {
		ma *= 2;
	}

	// Output the final result: doubled max value plus the sum of the other two
	cout << ma + rest << endl;

	return 0;
}

