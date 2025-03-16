
#include <stdio.h>
#include <stdlib.h>

int main() {
	// Initialize variables'sum' and 'num'
	int sum = 0;
	int num[4];

	// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
	for(int i = 0; i < 4; ++i) {
		scanf("%d", &num[i]); // Read the number
		sum += num[i] * 10; // Calculate the product and add it to the sum
	}

	// Calculate the change
	int change = sum - money;

	// Adjust the numbers to get the exact change
	for(int i = 3; i >= 0; --i) {
		// If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
		if(change / 10) {
			num[i] = num[i] - change / 10;
			change %= 10;
		}
	}

	// Print the numbers that still have a positive value
	for(int i = 0; i < 4; ++i)
		if(num[i] > 0)
			printf("10 %d\n", num[i]);

	// Return EXIT_SUCCESS to indicate successful execution
	return EXIT_SUCCESS;
}
