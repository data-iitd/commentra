
#include <stdio.h>

int n, ans; // Declare variables n and ans to store the size of the array and the result respectively.

#define arraySize 101 // Define a constant arraySize to set the size of the 2D array.

int a[arraySize][arraySize]; // Declare a 2D array a with dimensions [arraySize][arraySize].

// findAns is a recursive function that explores all possible paths from the top-left to the bottom-right corner of the array.
void findAns(int i, int j, int sum) {
	if (i == 1 && j == n-1 && sum+a[i][j] > ans) { // Check if the current position is the bottom-right corner and if the current sum plus the value at a[i][j] is greater than the current ans.
		ans = sum + a[i][j]; // Update ans if the condition is met.
		return; // Return to stop further recursion.
	}
	if (i == 0) { // If the current row is the first row, move to the next row.
		findAns(i+1, j, sum+a[i][j]); // Recursively call findAns with the next row.
	}
	if (j+1 < n) { // If the current column is within bounds, move to the next column.
		findAns(i, j+1, sum+a[i][j]); // Recursively call findAns with the next column.
	}
}

// main function to execute the program.
int main() {
	scanf("%d", &n); // Read the value of n from the input.
	for (int i = 0; i < 2; i++) { // Loop through the first two rows of the array.
		for (int j = 0; j < n; j++) { // Loop through each column of the current row.
			scanf("%d", &a[i][j]); // Read the value into the array a from the input.
		}
	}
	findAns(0, 0, 0); // Call the findAns function with initial parameters (0, 0, 0).
	printf("%d\n", ans); // Print the final value of ans.
}

