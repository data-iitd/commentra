

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <assert.h>

// ReadLongLines reads a specified number of long lines from standard input.
char** ReadLongLines(int times) {
	char** result = (char**)malloc(sizeof(char*) * times); // Create a slice to hold the lines read
	if (result == NULL) {
		return NULL; // Return NULL if allocation fails
	}
	FILE* reader = fdopen(dup(0), "r"); // Create a buffered reader for standard input
	if (reader == NULL) {
		free(result); // Free the result slice
		return NULL; // Return NULL if opening the reader fails
	}
	char* buffer = (char*)malloc(sizeof(char) * 1024); // Buffer to accumulate line data
	if (buffer == NULL) {
		free(result); // Free the result slice
		fclose(reader); // Close the reader
		return NULL; // Return NULL if allocation fails
	}
	size_t readBytes = 2; // Initialize readBytes to track the number of bytes read

	// Loop to read the specified number of lines
	for (int i = 0; i < times; i++) {
		while (true) {
			char* readBuf = fgets(buffer, 1024, reader); // Read a line from input
			readBytes += strlen(readBuf) + 1; // Update the byte count
			if (readBuf == NULL) {
				if (ferror(reader)) { // Check for error
					free(result); // Free the result slice
					fclose(reader); // Close the reader
					free(buffer); // Free the buffer
					return NULL; // Return NULL if reading fails
				} else {
					break; // Break out of the inner loop to read the next line
				}
			}
			char* newBuf = (char*)realloc(buffer, readBytes); // Reallocate the buffer
			if (newBuf == NULL) {
				free(result); // Free the result slice
				fclose(reader); // Close the reader
				free(buffer); // Free the buffer
				return NULL; // Return NULL if reallocation fails
			}
			buffer = newBuf; // Update the buffer pointer
			result[i] = buffer; // Store the complete line in the result
			buffer += strlen(buffer); // Advance the buffer pointer to the next line
		}
	}
	// Seek back to the previous position to avoid reading ahead
	fseek(reader, -readBytes, SEEK_CUR);
	return result; // Return the lines read
}

// Console struct for handling output
typedef struct {
	FILE* writer; // Buffered writer for output
} Console;

// NewConsole initializes a new Console instance
Console NewConsole() {
	Console con; // Create a new console instance
	con.writer = fdopen(dup(1), "w"); // Create a new writer for standard output
	return con; // Return the console instance
}

// Printf formats and writes output to the console
void Printf(Console con, const char* format,...) {
	va_list args;
	va_start(args, format);
	vfprintf(con.writer, format, args);
	va_end(args);
}

// Println writes a string followed by a newline to the console
void Println(Console con, const char* s) {
	fprintf(con.writer, "%s\n", s);
}

// Close flushes the buffered writer
void Close(Console con) {
	fflush(con.writer); // Ensure all buffered data is written out
}

// Flush flushes the buffered writer
void Flush(Console con) {
	fflush(con.writer); // Flush the writer to output
}

// PrintList prints a list of integers to the console
void PrintList(int* list, int length) {
	Console con = NewConsole(); // Create a new console instance
	defer Close(con); // Ensure flushing on function exit

	// Loop through the list and print each integer
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			Printf(con, "%d", list[i]); // Print the first element without a leading space
		} else {
			Printf(con, " %d", list[i]); // Print subsequent elements with a leading space
		}
	}
	Println(con, ""); // Print a newline after the list
}

// main function where the program execution begins
int main(int argc, char* argv[]) {
	Console con = NewConsole(); // Create a new console instance
	defer Close(con); // Ensure flushing on function exit

	int* m = (int*)malloc(sizeof(int) * 200000); // Create a map to track unique integers
	char** lines = ReadLongLines(4); // Read 4 lines from input
	char* a = lines[1]; // Split the second line into individual strings
	char* b = lines[3]; // Split the fourth line into individual strings

	// Convert strings to integers and store them in the map
	for (int i = 0; i < strlen(a); i++) {
		int n = atoi(a + i); // Convert string to integer
		m[n] = 1; // Add the integer to the map
	}

	// Process the integers from the fourth line
	for (int i = 0; i < strlen(b); i++) {
		int n = atoi(b + i); // Convert string to integer
		if (m[n] == 1) { // Check if the integer exists in the map
			m[n] = 0; // Remove it from the map if it exists
		} else {
			m[n] = 1; // Add it to the map if it does not exist
		}
	}

	// Collect remaining integers from the map into the result slice
	int resultLength = 0;
	for (int i = 0; i < 200000; i++) {
		if (m[i] == 1) {
			resultLength++; // Increment the result length
		}
	}
	int* result = (int*)malloc(sizeof(int) * resultLength);
	int resultIndex = 0;
	for (int i = 0; i < 200000; i++) {
		if (m[i] == 1) {
			result[resultIndex] = i; // Append the key to the result slice
			resultIndex++; // Increment the result index
		}
	}

	// Sort the result slice in ascending order
	qsort(result, resultLength, sizeof(int), (int (*)(const void*, const void*))strcmp);

	// Print the sorted result
	PrintList(result, resultLength);
	free(result);
	free(m);
	free(lines);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <assert.h>

// ReadLongLines reads a specified number of long lines from standard input.
char** ReadLongLines(int times) {
	char** result = (char**)malloc(sizeof(char*) * times); // Create a slice to hold the lines read
	if (result == NULL) {
		return NULL; // Return NULL if allocation fails
	}
	FILE* reader = fdopen(dup(0), "r"); // Create a buffered reader for standard input
	if (reader == NULL) {
		free(result); // Free the result slice
		return NULL; // Return NULL if opening the reader fails
	}
	char* buffer = (char*)malloc(sizeof(char) * 1024); // Buffer to accumulate line data
	if (buffer == NULL) {
		free(result); // Free the result slice
		fclose(reader); // Close the reader
		return NULL; // Return NULL if allocation fails
	}
	size_t readBytes = 2; // Initialize readBytes to track the number of bytes read

	// Loop to read the specified number of lines
	for (int i = 0; i < times; i++) {
		while (true) {
			char* readBuf = fgets(buffer, 1024, reader); // Read a line from input
			readBytes += strlen(readBuf) + 1; // Update the byte count
			if (readBuf == NULL) {
				if (ferror(reader)) { // Check for error
					free(result); // Free the result slice
					fclose(reader); // Close the reader
					free(buffer); // Free the buffer
					return NULL; // Return NULL if reading fails
				} else {
					break; // Break out of the inner loop to read the next line
				}
			}
			char* newBuf = (char*)realloc(buffer, readBytes); // Reallocate the buffer
			if (newBuf == NULL) {
				free(result); // Free the result slice
				fclose(reader); // Close the reader
				free(buffer); // Free the buffer
				return NULL; // Return NULL if reallocation fails
			}
			buffer = newBuf; // Update the buffer pointer
			result[i] = buffer; // Store the complete line in the result
			buffer += strlen(buffer); // Advance the buffer pointer to the next line
		}
	}
	// Seek back to the previous position to avoid reading ahead
	fseek(reader, -readBytes, SEEK_CUR);
	return result; // Return the lines read
}

// Console struct for handling output
typedef struct {
	FILE* writer; // Buffered writer for output
} Console;

// NewConsole initializes a new Console instance
Console NewConsole() {
	Console con; // Create a new console instance
	con.writer = fdopen(dup(1), "w"); // Create a new writer for standard output
	return con; // Return the console instance
}

// Printf formats and writes output to the console
void Printf(Console con, const char* format,...) {
	va_list args;
	va_start(args, format);
	vfprintf(con.writer, format, args);
	va_end(args);
}

// Println writes a string followed by a newline to the console
void Println(Console con, const char* s) {
	fprintf(con.writer, "%s\n", s);
}

// Close flushes the buffered writer
void Close(Console con) {
	fflush(con.writer); // Ensure all buffered data is written out
}

// Flush flushes the buffered writer
void Flush(Console con) {
	fflush(con.writer); // Flush the writer to output
}

// PrintList prints a list of integers to the console
void PrintList(int* list, int length) {
	Console con = NewConsole(); // Create a new console instance
	defer Close(con); // Ensure flushing on function exit

	// Loop through the list and print each integer
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			Printf(con, "%d", list[i]); // Print the first element without a leading space
		} else {
			Printf(con, " %d", list[i]); // Print subsequent elements with a leading space
		}
	}
	Println(con, ""); // Print a newline after the list
}

// main function where the program execution begins
int main(int argc, char* argv[]) {
	Console con = NewConsole(); // Create a new console instance
	defer Close(con); // Ensure flushing on function exit

	int* m = (int*)malloc(sizeof(int) * 200000); // Create a map to track unique integers
	char** lines = ReadLongLines(4); // Read 4 lines from input
	char* a = lines[1]; // Split the second line into individual strings
	char* b = lines[3]; // Split the fourth line into individual strings

	// Convert strings to integers and store them in the map
	for (int i = 0; i < strlen(a