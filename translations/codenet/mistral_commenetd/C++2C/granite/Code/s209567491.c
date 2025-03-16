

#include <stdio.h>

int main(int argc, char *args[]) {
	// Initialize variables
	int N, D, X; // Number of days, maximum days, and extra chocolate
	int num_of_chocolate; // Total number of chocolate pieces
	int counter; // Number of chocolate pieces eaten in one day
	int days; // Number of days eaten from one chocolate piece

	// Read input
	scanf("%d %d %d", &N, &D, &X);

	// Initialize array A to store the number of chocolate pieces for each day
	int A[101];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]); // Read the number of chocolate pieces for the i-th day
	}

	// Calculate the total number of chocolate pieces
	num_of_chocolate = 0;
	for (int i = 0; i < N; i++) {
		// Initialize variables for inner loop
		days = 0;
		counter = 0;

		// Calculate the number of days this chocolate piece lasts
		for (int j = 0;; j++) {
			days = j * A[i] + 1; // Calculate the number of days
			if (days <= D) { // Check if the number of days is less than or equal to the maximum number of days
				counter++; // Increment the counter
			}
			else { // If the number of days is greater than the maximum number of days, break the loop
				break;
			}
		}

		// Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
		num_of_chocolate = num_of_chocolate + counter;
	}

	// Add the extra chocolate
	num_of_chocolate = num_of_chocolate + X;

	// Output the result
	printf("%d\n", num_of_chocolate);

	return 0;
}

