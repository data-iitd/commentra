#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	// Read an integer input from the user
	int n;
	scanf("%d", &n);
	
	// Calculate the integer square root of n
	int rt = (int)sqrt(n);
	
	// Initialize a variable to keep track of the minimum number of digits found
	int minf = 100;
	
	// Loop through all integers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if i is a divisor of n
		if (n % i == 0) {
			// Calculate the corresponding divisor b
			int b = n / i;
			
			// Initialize a counter for the number of digits in b
			int ndigit = 0;
			
			// Count the number of digits in b
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			
			// Update minf with the minimum number of digits found
			minf = min(minf, ndigit);
		}
	}
	
	// Print the minimum number of digits found among the divisors
	printf("%d\n", minf);
	
	return 0;
}

// Function to return the minimum of two integers
int min(int i, int j) {
	if (i > j) {
		return j;
	}
	return i;
}

