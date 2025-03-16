// Include the header file for formatted I/O operations
#include <stdio.h>

// Include the header file for dynamic memory allocation
#include <stdlib.h>

// Include the header file for sorting
#include <stdlib.h>

// Define the function 'main'
int main() {
	// Declare an integer variable 'n' and read its value from the standard input
	int n;
	scanf("%d", &n);

	// Declare an array 'a' of 'n' float64 elements
	float64 a[n];

	// Read 'n' float64 values from the standard input and assign them to the array 'a'
	for (int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}

	// Declare an empty slice 'na' of float64
	float64 na[0];

	// Iterate through the slice 'a' starting from index 2 and append its elements to the slice 'na'
	for (int j = 2; j < n; j++) {
		na[j] = a[j];
	}

	// Reassign the value of the slice 'a' with the slice 'na' and the first two elements being the average of the first two elements of the original slice 'a'
	a[0] = (a[0] + a[1]) / 2;
	a[1] = na[0];

	// Print the first element of the sorted slice 'a' to the standard output
	printf("%f\n", a[0]);

	// Return the value 0 to indicate successful execution
	return 0;
}

