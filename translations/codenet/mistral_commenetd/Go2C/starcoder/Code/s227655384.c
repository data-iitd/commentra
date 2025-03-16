
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ReadLongLines function reads long lines from standard input
char** ReadLongLines(int times) {
	// Initialize result slice with the given size
	char** result = (char**)malloc(sizeof(char*) * times);
	// Initialize a new buffered reader
	FILE* reader = fopen("CONIN$", "r");
	// Initialize a new bytes.Buffer
	char* buffer = (char*)malloc(sizeof(char) * 1024);
	// Initialize readBytes variable to keep track of the total number of bytes read
	int readBytes = 2;

	// For each iteration, read a line from the standard input
	for (int i = 0; i < times; i++) {
		// Read a line from the standard input
		while (1) {
			// Read a line from the standard input
			fgets(buffer, 1024, reader);
			// Check if the line read is the last line of the input
			if (buffer[strlen(buffer) - 1] == '\n') {
				// Store the content of the line in the result slice
				result[i] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
				strcpy(result[i], buffer);
				// Reset the buffer for the next iteration
				memset(buffer, 0, 1024);
				// Break the inner loop if the line read is the last line of the input
				break;
			}
		}
		// Seek back the standard input stream to the position before the last read operation
		fseek(reader, -readBytes, SEEK_CUR);
	}
	// Return the result
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
	con.writer = fopen("CONOUT$", "w");
	return con;
}

// Printf function prints formatted strings to the Console writer
void Printf(Console con, char* format,...) {
	// Initialize a new va_list variable
	va_list args;
	// Initialize a new buffer
	char buffer[1024];
	// Initialize a new buffer
	va_start(args, format);
	// Format and print the given arguments to the Console writer
	vsprintf(buffer, format, args);
	fprintf(con.writer, buffer);
	// Initialize a new va_end variable
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
	Flush(con);
	fclose(con.writer);
}

// Flush function flushes the Console writer
void Flush(Console con) {
	// Flush the Console writer
	fflush(con.writer);
}

// PrintList function prints an integer slice to the standard output
void PrintList(int* list, int size) {
	// Initialize a new Console instance
	Console con = NewConsole();
	// Defer the Flush function to be called when the function returns
	defer Close(con);
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
	defer Close(con);

	// Initialize an empty map to store unique integers
	int* m = (int*)malloc(sizeof(int) * 200000);
	memset(m, 0, sizeof(int) * 200000);
	// Read long lines from the standard input
	char** lines = ReadLongLines(4);
	// Split the second line into an integer slice
	char* a = lines[1];
	char* b = strchr(a,'');
	int size = 0;
	while (b!= NULL) {
		*b = '\0';
		b++;
		size++;
	}
	int* numbers = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		numbers[i] = atoi(a);
		a = b;
		b = strchr(a,'');
		if (b!= NULL) {
			*b = '\0';
			b++;
		}
	}
	// Iterate through the integer slice and add each integer to the map
	for (int i = 0; i < size; i++) {
		// Add the integer to the map
		m[numbers[i]] = 1;
	}

	// Read integers from the fourth line and add them to the map if they are not already present
	a = lines[3];
	b = strchr(a,'');
	size = 0;
	while (b!= NULL) {
		*b = '\0';
		b++;
		size++;
	}
	numbers = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		numbers[i] = atoi(a);
		a = b;
		b = strchr(a,'');
		if (b!= NULL) {
			*b = '\0';
			b++;
		}
	}
	for (int i = 0; i < size; i++) {
		// Add the integer to the map if it's not already present
		if (m[numbers[i]] == 0) {
			m[numbers[i]] = 1;
		}
	}

	// Extract the unique integers from the map and store them in a slice
	int* result = (int*)malloc(sizeof(int) * 200000);
	int resultSize = 0;
	for (int i = 0; i < 200000; i++) {
		// Check if the integer is present in the map
		if (m[i] == 1) {
			// Add the integer to the result slice
			result[resultSize] = i;
			resultSize++;
		}
	}

	// Sort the result slice in ascending order
	qsort(result, resultSize, sizeof(int), (int (*)(const void*, const void*))strcmp);

	// Iterate through the sorted result slice and print each integer to the standard output
	for (int j = 0; j < resultSize; j++) {
		// Print each integer to the standard output
		Printf(con, "%d\n", result[j]);
	}
}

// 