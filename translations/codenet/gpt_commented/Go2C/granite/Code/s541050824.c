
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the buffered reader and writer
typedef struct {
    char buf[1000000]; // Buffer to hold the read data
    int i; // Current index in the buffer
} bufReader;

// Initialize a global bufReader instance for reading input
bufReader reader = {0};

// next retrieves the next token from the buffer
char* next() {
    // Read a line from the reader
    fgets(reader.buf, sizeof(reader.buf), stdin);
    char* from = reader.buf; // Store the starting index of the token
    // Iterate through the buffer until a space is found
    for (; *from!='' && *from!= '\n'; from++);
    *from = '\0'; // Null-terminate the token
    reader.i = from - reader.buf + 1; // Move the index forward
    return reader.buf; // Return the token
}

// nextInt retrieves the next token and converts it to an int
int nextInt() {
    int result;
    sscanf(next(), "%d", &result); // Parse the next token as int
    return result; // Return the parsed integer
}

// nextLine retrieves the next line from the buffer
char* nextLine() {
    // Read a line from the reader
    fgets(reader.buf, sizeof(reader.buf), stdin);
    reader.i = strlen(reader.buf); // Set index to the end of the buffer
    return reader.buf; // Return the line
}

// out prints the output to the standard output
void out(int a,...) {
    va_list args; // Initialize a variable argument list
    va_start(args, a); // Start the variable argument list
    vprintf(reader.buf, args); // Print the arguments to the writer
    va_end(args); // End the variable argument list
}

// max returns the maximum of two int values
int max(int x, int y) {
    return x > y? x : y; // Return x if it is greater, otherwise return y
}

// min returns the minimum of two int values
int min(int x, int y) {
    return x < y? x : y; // Return x if it is lesser, otherwise return y
}

// joinInts converts a slice of int to a string with a separator
char* joinInts(int* a, int n, char* sep) {
    char* result = (char*)malloc(1000000); // Allocate memory for the result string
    int len = 0; // Initialize the length of the result string
    for (int i = 0; i < n; i++) {
        len += sprintf(result + len, "%d", a[i]); // Convert each int to string and append to the result
        if (i < n - 1) {
            len += sprintf(result + len, "%s", sep); // Append the separator if it is not the last element
        }
    }
    return result; // Return the result string
}

// divUp performs ceiling division of x by y
int divUp(int x, int y) {
    return (x + y - 1) / y; // Return the result of ceiling division
}

int main() {
    int N = nextInt(); // Read the number of pairs
    int* T = (int*)malloc(sizeof(int) * N); // Allocate memory for T
    int* A = (int*)malloc(sizeof(int) * N); // Allocate memory for A
    // Read pairs of integers into T and A
    for (int i = 0; i < N; i++) {
        T[i] = nextInt();
        A[i] = nextInt();
    }
    int t = T[0], a = A[0]; // Initialize t and a with the first pair
    // Iterate through the remaining pairs to compute the required values
    for (int i = 1; i < N; i++) {
        int r = max(divUp(t, T[i]), divUp(a, A[i])); // Calculate the required multiplier
        t = T[i] * r; // Update t based on the multiplier
        a = A[i] * r; // Update a based on the multiplier
    }
    out("%d\n", t + a); // Output the final result
    return 0;
}
