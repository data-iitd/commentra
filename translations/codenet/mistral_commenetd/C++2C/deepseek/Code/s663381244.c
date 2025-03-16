#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	// Initialize cin and ios streams to disable buffering and synchronization
	// (Note: In C, we don't have cin and cout, so we use scanf and printf)

	// Initialize an empty vector 'm' to store the multipliers
	int m[4] = {10, 50, 100, 500};

	// Main loop to read the input money and calculate the change
	int money;
	while (scanf("%d", &money) == 1 && money) {
		bool first = true; // Initialize a boolean variable 'first' to check if it's the first iteration of the loop

		// Initialize variables 'sum' and 'num'
		int sum = 0;
		int num[4] = {0};

		// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
		for(int i = 0; i < 4; ++i) {
			scanf("%d", &num[i]); // Read the number
			sum += num[i] * m[i]; // Calculate the product and add it to the sum
		}

		// Calculate the change
		int change = sum - money;

		// Adjust the numbers to get the exact change
		for(int i = 3; i >= 0; --i) {
			// If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
			if(change / m[i]) {
				num[i] = num[i] - change / m[i];
				change %= m[i];
			}
		}

		// Print the numbers that still have a positive value
		for(int i = 0; i < 4; ++i)
			if(num[i] > 0)
				printf("%d %d\n", m[i], num[i]);

		// If it's not the first iteration, print a newline character to separate the outputs
		if (!first) {
			printf("\n");
		}
	}

	// Return EXIT_SUCCESS to indicate successful execution
	return EXIT_SUCCESS;
}
