
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ReadLongLines reads a specified number of long lines from standard input.
char** ReadLongLines(int times) {
	char** result = (char**)malloc(times * sizeof(char*)); // Create a slice to hold the lines read
	char* buffer = (char*)malloc(2 * sizeof(char)); // Buffer to accumulate line data
	int readBytes = 2; // Initialize readBytes to track the number of bytes read

	// Loop to read the specified number of lines
	for (int i = 0; i < times; i++) {
		for (;;) {
			char* readBuf = (char*)malloc(2 * sizeof(char)); // Read a line from input
			readBytes += strlen(readBuf) + 1; // Update the byte count
			if (feof(stdin)) { // Check for end of file
				printf("EOF\n");
				break;
			}
			strcat(buffer, readBuf); // Write the read buffer to the accumulator
			if (strchr(buffer, '\n') != NULL) { // Check if the line is complete (not a prefix)
				result[i] = buffer; // Store the complete line in the result
				buffer = (char*)malloc(2 * sizeof(char)); // Reset the buffer for the next line
				break; // Break out of the inner loop to read the next line
			}
		}
	}
	// Seek back to the previous position to avoid reading ahead
	fseek(stdin, -readBytes, SEEK_CUR);
	return result; // Return the lines read
}

// PrintList prints a list of integers to the console
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]); // Print the first element without a leading space
		} else {
			printf(" %d", list[i]); // Print subsequent elements with a leading space
		}
	}
	printf("\n"); // Print a newline after the list
}

// main function where the program execution begins
int main() {
	int* list = (int*)malloc(200000 * sizeof(int)); // Slice to hold the result integers
	int size = 0; // Size of the result slice
	char** lines = ReadLongLines(4); // Read 4 lines from input
	char** a = (char**)malloc(200000 * sizeof(char*)); // Slice to hold the integers
	int* m = (int*)malloc(200000 * sizeof(int)); // Map to track unique integers
	int n; // Temporary integer variable

	// Convert strings to integers and store them in the map
	for (int i = 0; i < 200000; i++) {
		sscanf(lines[1], "%d", &n); // Convert string to integer
		m[i] = n; // Add the integer to the map
	}

	// Process the integers from the fourth line
	for (int i = 0; i < 200000; i++) {
		sscanf(lines[3], "%d", &n); // Convert string to integer
		if (m[n] != 0) { // Check if the integer exists in the map
			m[n] = 0; // Remove it from the map if it exists
		} else {
			m[n] = 1; // Add it to the map if it does not exist
		}
	}

	// Collect remaining integers from the map into the result slice
	for (int i = 0; i < 200000; i++) {
		if (m[i] != 0) {
			list[size++] = i; // Append the key to the result slice
		}
	}

	// Sort the result slice in ascending order
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (list[i] > list[j]) {
				int temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}

	// Print the sorted result
	for (int i = 0; i < size; i++) {
		printf("%d\n", list[i]); // Print each integer in the result
	}
	return 0;
}

