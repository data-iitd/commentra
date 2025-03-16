
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Constants for infinity and modulo operations
#define inf 1e9
#define mod 1e9 + 7

// Function to check if a number is prime
int is_prime(long long x) {
    // Check divisibility from 2 to the square root of x
	for (long long i = 2; i * i <= x; i++)
		if (x % i == 0) return 0; // If divisible, not prime
	return 1; // If no divisors found, it is prime
}

int main() {
    // Read the input value N
	int N;
	scanf("%d", &N);

    // Initialize the answer variable to 1
	long long ans = 1;

    // Loop through all numbers from 2 to N
	for (int i = 2; i <= N; i++) {
        // Check if the current number i is prime
		if (is_prime((long long)i)) {
            // Store the original value of N for calculations
			int NN = N;
            // Initialize a counter for the prime factor's exponent
			int cnt = 0;

            // Count the number of times i is a factor in the numbers from 1 to N
			while (NN) {
				cnt += NN / i; // Count multiples of i
				NN /= i; // Reduce NN by dividing by i
			}

            // Update the answer by multiplying with the count of factors + 1
			ans *= cnt + 1;
			ans %= mod; // Take modulo to prevent overflow
		}
	}

    // Output the final result
	printf("%lld\n", ans);
    return 0; // End of the program
}


