#include <stdio.h>

int main() {
	int n, x, i, j, k, c; // Declare variables to hold the input values

	while (1) { // Start of the infinite loop
		scanf("%d %d", &n, &x); // Read two integers from standard input
		if (n == 0 && x == 0) { // Check if both n and x are zero
			break; // Exit the loop if true
		}

		c = 0; // Initialize a counter to zero
		for (i = 1; i <= n-2; i++) { // Loop over the first number
			for (j = i + 1; j <= n-1; j++) { // Loop over the second number
				for (k = j + 1; k <= n; k++) { // Loop over the third number
					if (i+j+k == x) { // Check if the sum of the three numbers equals x
						c++; // Increment the counter if true
					}
				}
			}
		}
		printf("%d\n", c); // Print the count of valid combinations
	}

	return 0;
}

