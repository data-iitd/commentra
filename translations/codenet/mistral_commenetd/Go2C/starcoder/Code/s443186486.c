#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Function to calculate the number of combinations of 'n' elements taken 'r' at a time
int combi(int n, int r) {
	// Initialize the result 'c' to 1
	int c = 1;
	// Iterate from 1 to 'r' to calculate the result
	for (int i = 1; i <= r; i++) {
		// Multiply the result with the product of 'n-i+1' and the previous result
		c = c * (n - i + 1) / i;
	}
	// Return the result
	return c;
}

// Function to sort the array in ascending order
void sort(int *a, int n) {
	// Initialize a boolean variable'swapped' to true
	bool swapped = true;
	// Iterate while'swapped' is true
	while (swapped) {
		// Set'swapped' to false
		swapped = false;
		// Iterate from 0 to 'n-2'
		for (int i = 0; i < n-1; i++) {
			// If the current element is greater than the next element, swap them
			if (a[i] > a[i+1]) {
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				// Set'swapped' to true
				swapped = true;
			}
		}
	}
}

// Function to calculate the answer
int answer(int *a, int n) {
	// Sort the array in ascending order
	sort(a, n);
	// Initialize variables 'ans' and 'count' to calculate the answer
	int ans = 0;
	int count = 0;
	// Iterate through the sorted array to find the answer
	for (int i = 0; i < n; i++) {
		// If the current element is equal to the next element, increment 'count'
		if (a[i] == a[i+1]) {
			count++;
		} else { // If 'count' is greater than zero, calculate the number of combinations of 'count+1' elements taken 2 at a time and add it to 'ans'
			if (count > 0) {
				ans += combi(count+1, 2);
				count = 0;
			}
		}
	}
	// If 'count' is greater than zero after the loop, calculate the number of combinations of 'count+1' elements taken 2 at a time and add it to 'ans'
	if (count > 0) {
		ans += combi(count+1, 2);
	}
	// Return the answer
	return ans;
}

// Main function
int main() {
	// Read the number of elements in the array from the standard input
	int n;
	scanf("%d", &n);

	// Initialize an array 'a' of size 'n' to store the input elements
	int *a = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		// Read each element of the array 'a' from the standard input
		scanf("%d", &a[i]);
	}

	// Calculate the answer
	int ans = answer(a, n);

	// Print the answer
	printf("%d", ans);
	return 0;
}

