#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read an integer from standard input
int nextInt() {
	int n;
	scanf("%d", &n);
	return n;
}

// Function to read multiple integers from standard input
int *scanNums(int len) {
	// Allocate memory for the array
	int *nums = malloc(len * sizeof(int));

	// Read each number from standard input and store it in the array
	for (int i = 0; i < len; i++) {
		scanf("%d", &nums[i]);
	}

	// Return the array
	return nums;
}

// Function to calculate the first pattern
int pattern1(int *l) {
	// Calculate the value of n using the given formula
	int n = (l[0] * l[3]) + (l[1] * l[4]);

	// Return the value of n
	return n;
}

// Function to calculate the second pattern
int pattern2(int *l) {
	// Calculate the maximum of l[3] and l[4]
	int maxNum = max(l[3], l[4]);

	// Calculate the value of n using the given formula
	int n = 2 * l[2] * maxNum;

	// Return the value of n
	return n;
}

// Function to calculate the third pattern
int pattern3(int *l) {
	// Calculate the minimum of l[3] and l[4]
	int minNum = min(l[3], l[4]);

	// Calculate the value of n using the given formula
	int n = 2 * l[2] * minNum + doch(l);

	// Return the value of n
	return n;
}

// Function to find the minimum of a list of numbers
int min(int nums[], int len) {
	// If the list is empty, panic with an error message
	if (len == 0) {
		printf("function min() requires at least one argument.\n");
		exit(1);
	}

	// Initialize the minimum value as the first number in the list
	int res = nums[0];

	// Iterate through the list and update the minimum value if necessary
	for (int i = 0; i < len; i++) {
		res = (res < nums[i])? res : nums[i];
	}

	// Return the minimum value
	return res;
}

// Function to find the maximum of a list of numbers
int max(int nums[], int len) {
	// If the list is empty, panic with an error message
	if (len == 0) {
		printf("function max() requires at least one argument.\n");
		exit(1);
	}

	// Initialize the maximum value as the first number in the list
	int res = nums[0];

	// Iterate through the list and update the maximum value if necessary
	for (int i = 0; i < len; i++) {
		res = (res > nums[i])? res : nums[i];
	}

	// Return the maximum value
	return res;
}

// Helper function to calculate the difference between the larger and smaller of two numbers
int doch(int *l) {
	// If l[3] is greater than l[4], return the product of l[0] and the difference between l[3] and l[4]
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		// Otherwise, return the product of l[1] and the difference between l[4] and l[3]
		return l[1] * (l[4] - l[3]);
	}
}

// Main function to read input and call the pattern functions
int main() {
	// Read the length of the input list
	int len = 5;

	// Read the input list from standard input
	int *l = scanNums(len);

	// Calculate and print the minimum of the three patterns
	printf("%d\n", min(pattern1(l), pattern2(l), pattern3(l)));

	// Free the memory allocated for the array
	free(l);

	// Return from main
	return 0;
}

