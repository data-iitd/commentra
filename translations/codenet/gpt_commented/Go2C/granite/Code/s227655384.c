
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ReadLongLines reads a specified number of long lines from standard input.
char** ReadLongLines(int times) {
    char** result = (char**)malloc(times * sizeof(char*)); // Create a slice to hold the lines read
    char buf[1024]; // Buffer to accumulate line data
    int readBytes = 0; // Initialize readBytes to track the number of bytes read
    int i = 0; // Initialize i to track the current line index

    while (i < times) {
        char* line = fgets(buf, sizeof(buf), stdin); // Read a line from input
        readBytes += strlen(line); // Update the byte count
        if (line == NULL) { // Check for end of file
            if (feof(stdin)) {
                printf("EOF\n");
                break;
            } else {
                free(result); // Free the allocated memory
                return NULL; // Return NULL if reading fails
            }
        }
        result[i] = (char*)malloc(strlen(line) + 1); // Allocate memory for the line
        strcpy(result[i], line); // Copy the line to the allocated memory
        i++; // Increment the line index
    }
    // Seek back to the previous position to avoid reading ahead
    fseek(stdin, -readBytes, SEEK_CUR);
    return result; // Return the lines read
}

// Console struct for handling output
typedef struct {
    FILE* writer; // Writer for output
} Console;

// NewConsole initializes a new Console instance
Console* NewConsole() {
    Console* con = (Console*)malloc(sizeof(Console)); // Allocate memory for the console instance
    con->writer = stdout; // Set the writer to standard output
    return con; // Return the initialized console instance
}

// Printf formats and writes output to the console
void Printf(Console* con, const char* format,...) {
    va_list args; // Variable argument list
    va_start(args, format); // Initialize the variable argument list
    vfprintf(con->writer, format, args); // Format and write to the console
    va_end(args); // Clean up the variable argument list
}

// Println writes a string followed by a newline to the console
void Println(Console* con, const char* s) {
    fprintf(con->writer, "%s\n", s); // Write the string to the console
}

// Close flushes the console writer
void Close(Console* con) {
    fflush(con->writer); // Flush the writer to output
}

// PrintList prints a list of integers to the console
void PrintList(int* list, int size) {
    Console* con = NewConsole(); // Create a new console instance
    defer Close(con); // Ensure closing on function exit

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            Printf(con, "%d", list[i]); // Print the first element without a leading space
        } else {
            Printf(con, " %d", list[i]); // Print subsequent elements with a leading space
        }
    }
    Printf(con, "\n"); // Print a newline after the list
}

int main() {
    Console* con = NewConsole(); // Create a new console instance
    defer Close(con); // Ensure closing on function exit

    int m[200000]; // Create an array to track unique integers
    char** lines = ReadLongLines(4); // Read 4 lines from input
    char** a = lines[1]; // Split the second line into individual strings

    // Convert strings to integers and store them in the array
    int j = 0; // Initialize j to track the current string index
    char* token = strtok(a, " "); // Tokenize the string
    while (token!= NULL) {
        m[j] = atoi(token); // Convert string to integer
        j++; // Increment the string index
        token = strtok(NULL, " "); // Get the next token
    }

    int result[200000]; // Array to hold the result integers
    char** b = lines[3]; // Split the fourth line into individual strings

    // Process the integers from the fourth line
    j = 0; // Reset j to track the current string index
    token = strtok(b, " "); // Tokenize the string
    while (token!= NULL) {
        int n = atoi(token); // Convert string to integer
        if (n < 0 || n >= 200000) { // Check if the integer is within the range
            token = strtok(NULL, " "); // Get the next token
            continue; // Skip the current token if it is out of range
        }
        if (m[n] == 1) { // Check if the integer exists in the array
            m[n] = 0; // Remove it from the array if it exists
        } else {
            m[n] = 1; // Add it to the array if it does not exist
        }
        token = strtok(NULL, " "); // Get the next token
    }

    // Collect remaining integers from the array into the result array
    int k = 0; // Initialize k to track the current result index
    for (int i = 0; i < 200000; i++) {
        if (m[i] == 1) { // Check if the integer exists in the array
            result[k] = i; // Add it to the result array
            k++; // Increment the result index
        }
    }

    // Sort the result array in ascending order
    qsort(result, k, sizeof(int), compare); // Sort the result array

    // Print the sorted result
    for (int i = 0; i < k; i++) {
        Printf(con, "%d\n", result[i]); // Print each integer in the result
    }

    return 0; // Return 0 to indicate successful execution
}

