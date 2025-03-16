#include <stdio.h>

// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
long long Euclid(long long x, long long y) {
	long long tmp;

	// Ensure x is greater than y
	if (x < y) {
		tmp = x;
		x = y;
		y = tmp;
	}

	// Base case: if x is divisible by y, return y
	if (!(x % y)) return y;

	// Recursive case: apply the Euclidean algorithm
	return Euclid(y, x % y);
}

int main() {
	long long A, B; 

	// Read two long long integers from standard input
	scanf("%lld %lld", &A, &B);

	// Calculate and output the least common multiple (LCM) of A and B
	printf("%lld\n", (A * B) / Euclid(A, B));
}

