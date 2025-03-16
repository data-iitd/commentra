
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an array of integers from stdin and return it
int* scanArrayInt() {
	// Initialize an empty array to store the integers
	int* ret = (int*)malloc(sizeof(int));
	// Read the input line from stdin
	char* input = (char*)malloc(sizeof(char));
	scanf("%s", input);
	// Split the input line by space
	char* token = strtok(input, " ");
	// Iterate through each element in the input slice and convert it to integer
	while (token!= NULL) {
		// Convert the string to integer and append it to the slice
		int i = atoi(token);
		ret = (int*)realloc(ret, sizeof(int)*(ret[0]+1));
		ret[ret[0]] = i;
		ret[0]++;
		// Read the next input line from stdin
		scanf("%s", input);
		// Split the input line by space
		token = strtok(input, " ");
	}
	// Return the slice of integers
	return ret;
}

// Function to initialize variables and start the main logic
int main() {
	// Read the array of integers from stdin
	int* arr = scanArrayInt();
	// Initialize variables a and b with the first two elements of the array
	int a = arr[0], b = arr[1];
	// Initialize variables tap and consent with default values
	int tap = 0, consent = 1;
	// Loop until consent is greater than or equal to b
	while (consent < b) {
		// Increment consent by the sum of a and consent minus one
		consent = consent + a - 1;
		// Increment tap by one for each iteration
		tap++;
	}
	// Print the result, i.e., the number of taps required
	printf("%d", tap);
	// Free the memory allocated to the array
	free(arr);
	// Return from the main function
	return 0;
}

