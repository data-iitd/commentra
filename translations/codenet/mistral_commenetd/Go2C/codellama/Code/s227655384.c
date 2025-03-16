
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000000

// ReadLongLines function reads long lines from standard input
char** ReadLongLines(int times) {
	// Initialize result slice with the given size
	char** result = (char**)malloc(times * sizeof(char*));
	// Initialize a new buffered reader
	char buffer[MAX_LINE_LENGTH];
	// Initialize readBytes variable to keep track of the total number of bytes read
	int readBytes = 2;

	// For each iteration, read a line from the standard input
	for (int i = 0; i < times; i++) {
		// Read a line from the standard input
		for (int j = 0; j < MAX_LINE_LENGTH; j++) {
			// Read a line from the standard input
			int readBuf = getchar();
			// Check if an error occurred during the read operation
			if (readBuf == EOF) {
				// If the error is of type io.EOF, it means that the end of the input has been reached
				if (readBuf == EOF) {
					printf("EOF\n");
					// Break the loop if the end of the input has been reached
					break;
				} else {
					// Return an error if an error other than io.EOF occurred
					return result;
				}
			}
			// Write the read line to the buffer
			buffer[j] = readBuf;
			// Check if the line read is the last line of the input
			if (readBuf == '\n') {
				// Store the content of the line in the result slice
				result[i] = (char*)malloc(readBytes * sizeof(char));
				strcpy(result[i], buffer);
				// Reset the buffer for the next iteration
				memset(buffer, 0, MAX_LINE_LENGTH);
				// Break the inner loop if the line read is the last line of the input
				break;
			}
			// Increment the readBytes variable
			readBytes++;
		}
		// Seek back the standard input stream to the position before the last read operation
		fseek(stdin, -readBytes, SEEK_CUR);
	}
	// Return the result and nil error
	return result;
}

// Console type is used to manage the standard output
typedef struct {
	FILE* writer;
} Console;

// NewConsole function initializes a new Console instance
Console NewConsole() {
	// Initialize a new Console instance with the standard output as the writer
	Console con;
	con.writer = stdout;
	return con;
}

// Printf function prints formatted strings to the Console writer
void Printf(Console con, char* format, ...) {
	// Format and print the given arguments to the Console writer
	va_list args;
	va_start(args, format);
	vfprintf(con.writer, format, args);
	va_end(args);
}

// Println function prints a newline character followed by the given string to the Console writer
void Println(Console con, char* s) {
	// Format and print the given string followed by a newline character to the Console writer
	fprintf(con.writer, "%s\n", s);
}

// Close function flushes the Console writer and closes it
void Close(Console con) {
	// Flush and close the Console writer
	fflush(con.writer);
}

// PrintList function prints an integer slice to the standard output
void PrintList(int* list, int size) {
	// Initialize a new Console instance
	Console con = NewConsole();
	// Defer the Flush function to be called when the function returns
	defer(Close(con));
	// Iterate through the given integer slice and print each element to the standard output
	for (int i = 0; i < size; i++) {
		// If it's the first element, print it without a separator
		if (i == 0) {
			Printf(con, "%d", list[i]);
		} else {
			// Otherwise, print it with a separator
			Printf(con, " %d", list[i]);
		}
	}
	// Print a newline character to the standard output
	Println(con, "");
}

// main function is the entry point of the program
int main() {
	// Initialize a new Console instance
	Console con = NewConsole();
	// Defer the Flush function to be called when the function returns
	defer(Close(con));

	// Initialize an empty map to store unique integers
	int* m = (int*)malloc(200000 * sizeof(int));
	// Read long lines from the standard input
	char** lines = ReadLongLines(4);
	// Split the second line into an integer slice
	char* a = strtok(lines[1], " ");
	// Iterate through the integer slice and add each integer to the map
	int i = 0;
	while (a != NULL) {
		// Parse the integer from the string and add it to the map
		int n = atoi(a);
		m[i] = n;
		i++;
		a = strtok(NULL, " ");
	}

	// Read integers from the fourth line and add them to the map if they are not already present
	char* b = strtok(lines[3], " ");
	while (b != NULL) {
		// Parse the integer from the string and add it to the map if it's not already present
		int n = atoi(b);
		if (m[n] == 0) {
			m[n] = n;
		}
		b = strtok(NULL, " ");
	}

	// Extract the unique integers from the map and store them in a slice
	int* result = (int*)malloc(200000 * sizeof(int));
	int j = 0;
	for (int k = 0; k < 200000; k++) {
		// Append the integer to the result slice
		if (m[k] != 0) {
			result[j] = m[k];
			j++;
		}
	}

	// Sort the result slice in ascending order
	qsort(result, j, sizeof(int), compare);

	// Iterate through the sorted result slice and print each integer to the standard output
	for (int l = 0; l < j; l++) {
		// Print each integer to the standard output
		Printf(con, "%d\n", result[l]);
	}
	// Print the end of the code
	Println(con, "