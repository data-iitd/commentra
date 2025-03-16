
#include <stdio.h>
#include <math.h>

// Define input variables and some auxiliary variables
int n, a[50], p, b = 0, c = 0;

// Function to calculate nPr (n choose r)
long long nPr(long long n, long long r) {
	// Initialize result to 1
	long long res = 1;
	// Iterate from 0 to r and multiply result with (n-i)
	for (int i = 0; i < r; i++) {
		res *= (n - i);
		// Add comment explaining what is being done
		// Multiply result with factorial of (n-i)
		// to get the value of nPr(n, r)
		//printf("Calculating nPr(%lld, %lld) = %lld\n", n, r, res);
	}

	// Return the result
	return res;
}

// Function to calculate nCr (n choose r)
long long nCr(long long n, long long r) {
	// Initialize result to 1
	double res = 1;
	// Iterate from 0 to r and multiply result with (n-i) and divide by (i+1)
	for (int i = 0; i < r; i++) {
		res *= (n - i);
		res /= (i+1);
		// Add comment explaining what is being done
		// Multiply result with factorial of (n-i) and divide by (i+1)
		// to get the value of nCr(n, r)
		//printf("Calculating nCr(%lld, %lld) = %lld\n", n, r, res);
	}
	// Convert the double result to long long and return it
	return (long long)res;
}

// Main function
int main() {
	// Read input values of n and p from the user
	scanf("%d %d", &n, &p);
	// Initialize b and c to count the number of even and odd elements in the array a
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0) {
			b++;
		}
		else {
			c++;
		}
		// Add comment explaining what is being done
		// Read an element from the array a and check if it is even or odd
		// Increment the corresponding counter (b for even and c for odd)
	}

	// Calculate the sum of 2^b and c
	long long bsum = 1, csum = 0;
	bsum = pow(2, b);

	// Calculate the sum of nCr(c, i) for i from 0 to c
	if (p == 0) {
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 0) {
				csum += nCr(c, i);
			}
			// Add comment explaining what is being done
			// If i is even, add nCr(c, i) to csum
		}
	}
	else {
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 1) {
				csum += nCr(c, i);
			}
			// Add comment explaining what is being done
			// If i is odd, add nCr(c, i) to csum
		}
	}

	// Multiply bsum and csum and store the result in ans
	long long ans = bsum * csum;
	// Add comment explaining what is being done
	// Multiply bsum and csum to get the final answer

	// Print the final answer
	printf("%lld\n", ans);
}

