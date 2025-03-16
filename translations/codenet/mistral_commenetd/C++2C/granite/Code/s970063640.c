

#include <stdio.h>
#include <stdlib.h> // Include the standard library for dynamic memory allocation
#include <string.h> // Include the string library for string manipulation
#include <math.h> // Include the math library for mathematical operations
#include <time.h> // Include the time library for time-related operations
#include <assert.h> // Include the assert library for error checking

int main(){
	// Declare and initialize variables
	int n; // Number of elements in the array
	scanf("%d",&n); // Read the number of elements from the user
	int a; // Size of the subarray to be summed
	scanf("%d",&a); // Read the size of the subarray from the user
	int sum = 0; // Initialize the sum variable to zero
	int s[n]; // Declare an array of size n to store the input elements

	// Read the elements of the array from the user
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]); // Read the i-th element of the array
	}

	// Sort the array in ascending order
	qsort(s,n,sizeof(int)); // Sort the array using the qsort function from the standard library

	// Calculate the sum of the last 'a' elements of the sorted array
	for(int i=n-1;i>n-a-1;i--){
		sum += s[i]; // Add the current element to the sum
	}

	// Print the result
	printf("%d\n",sum); // Print the sum of the last 'a' elements
	return 0; // Indicate successful termination of the program
}

