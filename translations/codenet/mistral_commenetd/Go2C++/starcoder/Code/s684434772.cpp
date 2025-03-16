
#include <bits/stdc++.h>

using namespace std;

// Util functions for performing basic mathematical operations.

// Abs returns the absolute value of a given integer.
int Abs(int x) {
	// If the number is positive, return the number itself.
	// Otherwise, return the negative of the number.
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min returns the minimum value among the given integers.
int Min(int values...) {
	// Initialize the minimum value with the first integer.
	int min = values[0];
	// Compare each integer with the minimum value and update the minimum value if necessary.
	for (int i = 1; i < sizeof(values) / sizeof(int); i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	// Return the minimum value.
	return min;
}

// Max returns the maximum value among the given integers.
int Max(int values...) {
	// Initialize the maximum value with the first integer.
	int max = values[0];
	// Compare each integer with the maximum value and update the maximum value if necessary.
	for (int i = 1; i < sizeof(values) / sizeof(int); i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	// Return the maximum value.
	return max;
}

// Pow returns the result of raising the base to the given exponent.
int Pow(int base, uint exponent) {
	// Initialize the answer with 1.
	int answer = 1;
	// Multiply the answer with the base for each bit in the exponent.
	for (int i = 0; i < exponent; i++) {
		answer *= base;
	}
	// Return the answer.
	return answer;
}

// Abs64 returns the absolute value of a given integer64.
int64_t Abs64(int64_t x) {
	// If the number is positive, return the number itself.
	// Otherwise, return the negative of the number.
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min64 returns the minimum value among the given integer64s.
int64_t Min64(int64_t values...) {
	// Initialize the minimum value with the first integer.
	int64_t min = values[0];
	// Compare each integer with the minimum value and update the minimum value if necessary.
	for (int i = 1; i < sizeof(values) / sizeof(int64_t); i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	// Return the minimum value.
	return min;
}

// Max64 returns the maximum value among the given integer64s.
int64_t Max64(int64_t values...) {
	// Initialize the maximum value with the first integer.
	int64_t max = values[0];
	// Compare each integer with the maximum value and update the maximum value if necessary.
	for (int i = 1; i < sizeof(values) / sizeof(int64_t); i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	// Return the maximum value.
	return max;
}

// Pow64 returns the result of raising the base to the given exponent.
int64_t Pow64(int64_t base, uint exponent) {
	// Initialize the answer with 1.
	int64_t answer = 1;
	// Multiply the answer with the base for each bit in the exponent.
	for (int i = 0; i < exponent; i++) {
		answer *= base;
	}
	// Return the answer.
	return answer;
}

// The combi function calculates the number of combinations of 'n' taken 'k' at a time using a simplified formula.
int64_t combi(int n, int k) {
	// Calculate the minimum and maximum number of combinations.
	int64_t min = (int64_t)(k - 1) * (int64_t)(k) / 2;
	int64_t max = (int64_t)(2 * n - k + 1) * (int64_t)(k) / 2;
	// Return the difference between the maximum and minimum number of combinations.
	return max - min + 1;
}

// The main function is the entry point of the program.
int main() {
	// Initialize a new Scanner object named'sc'.
	Scanner sc;

	// Read 'n' and 'k' from the standard input.
	int n = sc.ReadInt();
	int k = sc.ReadInt();

	// Initialize a variable 'total' to store the sum of combinations.
	int64_t total = 0;

	// Calculate the sum of combinations of 'n' taken 'i' at a time, where 'i' ranges from 'k' to 'n+1'.
	for (int i = k; i <= n + 1; i++) {
		// Calculate the number of combinations using the combi function.
		int64_t comb = combi(n, i);
		// Add the number of combinations to the 'total' variable.
		total += comb;
		// Apply modulo operation to reduce the size of the number.
		total = total % (int64_t)(Pow64(10, 9) + 7);
	}

	// Print the result to the standard output.
	cout << total << endl;
}

