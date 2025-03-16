#include <stdio.h> // Include the stdio library for input/output operations

int main() { // Beginning of the main function
	int m, f, r; // Declare variables m, f, and r to store user input

	while (scanf("%d %d %d", &m, &f, &r) != EOF) { // Start of the while loop
		// The loop continues as long as the user inputs valid integers (m, f, and r)
		// and at least one of them is not -1

		if (m == -1 || f == -1) { // Check if m or f is -1
			printf("F\n"); // If so, print "F" and move on to the next input
			continue;
		}

		if (m + f >= 80) { // Check if the sum of m and f is greater than or equal to 80
			printf("A\n"); // If so, print "A" and move on to the next input
			continue;
		}

		if (m + f >= 65) { // Check if the sum of m and f is greater than or equal to 65
			printf("B\n"); // If so, print "B" and move on to the next input
			continue;
		}

		if (m + f >= 50 || r >= 50) { // Check if the sum of m and f is greater than or equal to 50
									 // or if r is greater than or equal to 50
			printf("C\n"); // If so, print "C" and move on to the next input
			continue;
		}

		if (m + f >= 30) { // Check if the sum of m and f is greater than or equal to 30
			printf("D\n"); // If so, print "D" and move on to the next input
			continue;
		}

		printf("F\n"); // If none of the above conditions are met, print "F" and move on to the next input
	}

	return 0; // End of the main function, return 0 to indicate successful execution
}
