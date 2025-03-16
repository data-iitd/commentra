
#include <stdio.h>

int main() {
	// Initialize variables
	int n, x, i, j, tmpL, tmpSum, rs;

	// Read input values for n and x
	printf("Enter the number of arrays: ");
	scanf("%d", &n);
	printf("Enter the sum of elements in an array that should not exceed: ");
	scanf("%d", &x);

	// Initialize an empty slice l to store the arrays
	int l[n];

	// Read input values for each array and append them to the slice l
	for (i = 0; i < n; i++) {
		// Read the length of the current array
		printf("Enter the length of array number %d: ", i + 1);
		scanf("%d", &tmpL);

		// Append the length of the current array to the slice l
		l[i] = tmpL;
	}

	// Initialize variables for sum and result slice index
	tmpSum = 0;
	rs = 0;

	// Iterate through the slice l to find the index of the last array whose sum is less than or equal to x
	for (i = 0; i < n; i++) {
		// Initialize a variable tmpSum to store the sum of elements in the current array
		tmpSum = 0;

		// Calculate the sum of elements in the current array
		for (j = 0; j < l[i]; j++) {
			// Read the value of the current element and add it to the sum
			int tmp;
			printf("Enter the value of element number %d in array number %d: ", j + 1, i + 1);
			scanf("%d", &tmp);
			tmpSum += tmp;
		}

		// Check if the sum of elements in the current array is greater than x
		if (tmpSum > x) {
			// If yes, break the loop as we don't need to check further arrays
			break;
		}

		// If the sum of elements in the current array is less than or equal to x, update the result slice index
		rs = i + 1;
	}

	// Print the result slice index
	printf("The last array index whose sum of elements is less than or equal to %d is: %d\n", x, rs);

	// End of code
	return 0;
}