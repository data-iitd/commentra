

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for storing integers
typedef struct {
	int length; // Number of integers in the array
	int* data; // Pointer to the first integer in the array
} IntArray;

// Initialize a new IntArray
IntArray newIntArray(int length) {
	IntArray array; // Declare a new IntArray
	array.length = length; // Set the length
	array.data = (int*) malloc(length * sizeof(int)); // Allocate memory for the array
	return array; // Return the new IntArray
}

// Free the memory allocated for an IntArray
void freeIntArray(IntArray array) {
	free(array.data); // Free the memory
}

// Read a line of integers from stdin and store them in an IntArray
IntArray readIntArray() {
	IntArray array; // Declare a new IntArray
	char* line = NULL; // Declare a string to hold the line of text
	size_t len = 0; // Length of the line
	getline(&line, &len, stdin); // Read a line of text from stdin
	char* token = strtok(line, " "); // Get the first token from the line
	array.length = 0; // Initialize the length of the array
	while (token!= NULL) { // Loop until there are no more tokens
		array.length++; // Increment the length
		token = strtok(NULL, " "); // Get the next token
	}
	array.data = (int*) malloc(array.length * sizeof(int)); // Allocate memory for the array
	token = strtok(line, " "); // Get the first token from the line again
	int i = 0; // Initialize counter
	while (token!= NULL) { // Loop until there are no more tokens
		array.data[i] = atoi(token); // Convert the string to an integer and store it in the array
		i++; // Increment the counter
		token = strtok(NULL, " "); // Get the next token
	}
	free(line); // Free the memory allocated for the line
	return array; // Return the IntArray
}

// Print an IntArray to stdout
void printIntArray(IntArray array) {
	for (int i = 0; i < array.length; i++) { // Loop through the array
		printf("%d ", array.data[i]); // Print the integer
	}
	printf("\n"); // Print a newline
}

// Get the maximum integer from an IntArray
int maxIntArray(IntArray array) {
	int max = array.data[0]; // Initialize max with the first integer
	for (int i = 1; i < array.length; i++) { // Loop through the array
		if (max < array.data[i]) { // Check if the current integer is larger than max
			max = array.data[i]; // Update max
		}
	}
	return max; // Return the maximum integer
}

// Get the minimum integer from an IntArray
int minIntArray(IntArray array) {
	int min = array.data[0]; // Initialize min with the first integer
	for (int i = 1; i < array.length; i++) { // Loop through the array
		if (min > array.data[i]) { // Check if the current integer is smaller than min
			min = array.data[i]; // Update min
		}
	}
	return min; // Return the minimum integer
}

// Calculate the power of an integer base raised to an integer exponent
int powInt(int a, int e) {
	if (a < 0 || e < 0) { // Check if either argument is negative
		printf("[argument error]: PowInt does not accept negative integers\n");
		exit(1); // Exit with an error
	}
	return (int) pow((double) a, (double) e); // Return the result as an integer
}

// Calculate the absolute value of an integer
int absInt(int a) {
	return (int) abs((double) a); // Return the result as an integer
}

// Delete an element at a specified index from an IntArray
IntArray deleteElement(IntArray array, int i) {
	if (i < 0 || array.length <= i) { // Check if the index is out of bounds
		printf("[index error]\n");
		exit(1); // Exit with an error
	}
	IntArray newArray = newIntArray(array.length - 1); // Create a new IntArray with one less element
	for (int j = 0; j < i; j++) { // Loop through the array
		newArray.data[j] = array.data[j]; // Copy the element to the new array
	}
	for (int j = i; j < array.length - 1; j++) { // Loop through the array
		newArray.data[j] = array.data[j + 1]; // Copy the element to the new array
	}
	freeIntArray(array); // Free the memory allocated for the old array
	return newArray; // Return the new array
}

// Concatenate two IntArrays
IntArray concat(IntArray s, IntArray t) {
	IntArray newArray = newIntArray(s.length + t.length); // Create a new IntArray with combined length
	for (int i = 0; i < s.length; i++) { // Loop through the first array
		newArray.data[i] = s.data[i]; // Copy the element to the new array
	}
	for (int i = 0; i < t.length; i++) { // Loop through the second array
		newArray.data[i + s.length] = t.data[i]; // Copy the element to the new array
	}
	freeIntArray(s); // Free the memory allocated for the first array
	freeIntArray(t); // Free the memory allocated for the second array
	return newArray; // Return the new array
}

// Main function
int main() {
	IntArray array = readIntArray(); // Read a line of integers
	int x = array.data[0]; // Store the first integer in variable x
	freeIntArray(array); // Free the memory allocated for the array
	int i = 1; // Initialize counter
	int sum = 0; // Initialize sum
	while (1) {
		sum += i; // Incrementally add to sum
		if (sum >= x) { // Check if sum has reached or exceeded x
			break; // Exit the loop if condition is met
		}
		i++; // Increment counter
	}
	printf("%d\n", i); // Print the result
	return 0;
}

