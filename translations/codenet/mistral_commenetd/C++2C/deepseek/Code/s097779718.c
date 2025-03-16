#include <stdio.h>

// Function to find the greatest common divisor (GCD) of two numbers using Euclid's algorithm
long long Euclid(long long x, long long y) {
	long long tmp; // Variable to store the temporary value

	// Swap x and y if x is smaller than y
	if (x < y) {
		tmp = x;
		x = y;
		y = tmp;
	}

	// If x is divisible by y, return y as the GCD
	if (!(x%y)) return y;

	// Recursively call Euclid function with y and the remainder of x divided by y
	return Euclid(y, x%y);
}

int main() {
	long long A, B; // Declare variables to store input numbers

	// Read input values of A and B from the standard input
	scanf("%lld %lld", &A, &B);

	// Calculate the product of A and B and print the result divided by their GCD
	printf("%lld\n", (A*B) / Euclid(A, B));
}
