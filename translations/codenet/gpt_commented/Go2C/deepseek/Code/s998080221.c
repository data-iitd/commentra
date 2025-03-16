#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure to handle buffered reading from standard input
typedef struct {
    char *buf;
    size_t bufSize;
    size_t index;
} bufReader;

// Initialize a global bufReader instance for reading input
bufReader reader = {NULL, 0, 0};

// Initialize a global writer for output
FILE *writer = stdout;

// Function to initialize the bufReader
void initBufReader() {
    reader.bufSize = 1024;
    reader.buf = (char *)malloc(reader.bufSize * sizeof(char));
    if (reader.buf == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

// Function to read a line from the buffered reader into the buffer
void readLine() {
    if (reader.index < reader.bufSize) {
        return; // Return if there are still bytes to read
    }
    reader.index = 0; // Reset index
    size_t bytesRead = fread(reader.buf, sizeof(char), reader.bufSize, stdin);
    if (bytesRead == 0) {
        fprintf(stderr, "End of input\n");
        exit(EXIT_SUCCESS);
    }
}

// Function to read the next token from the buffer
char* next() {
    readLine(); // Ensure the buffer is filled
    size_t from = reader.index; // Store the starting index
    while (reader.index < strlen(reader.buf) && reader.buf[reader.index] != ' ') {
        reader.index++; // Move index forward until space
    }
    char *token = (char *)malloc((reader.index - from + 1) * sizeof(char));
    if (token == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(token, reader.buf + from, reader.index - from);
    token[reader.index - from] = '\0'; // Null-terminate the token
    reader.index++; // Move index forward to skip the space
    return token;
}

// Function to read the next token as an int64_t
int64_t nextInt64() {
    char *token = next(); // Get the next token
    int64_t result = strtoll(token, NULL, 10); // Parse token to int64_t
    free(token); // Free the allocated memory for the token
    return result;
}

// Function to read the next token as an int
int nextInt() {
    return (int)nextInt64(); // Convert int64_t to int
}

// Function to read the next full line from the buffer
char* nextLine() {
    readLine(); // Ensure the buffer is filled
    size_t from = reader.index; // Store the starting index
    while (reader.index < strlen(reader.buf) && reader.buf[reader.index] != '\n') {
        reader.index++; // Move index forward until newline
    }
    char *line = (char *)malloc((reader.index - from + 1) * sizeof(char));
    if (line == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(line, reader.buf + from, reader.index - from);
    line[reader.index - from] = '\0'; // Null-terminate the line
    reader.index++; // Move index forward to skip the newline
    return line;
}

// Function to output the results
void out(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(writer, format, args);
    va_end(args);
}

// Function to return the maximum of two int64_t values
int64_t max64(int64_t x, int64_t y) {
    return x > y ? x : y; // Return x if it's greater
}

// Function to return the maximum of two int values
int max(int x, int y) {
    return (int)max64((int64_t)x, (int64_t)y); // Convert int to int64_t and find max
}

// Function to return the minimum of two int64_t values
int64_t min64(int64_t x, int64_t y) {
    return x < y ? x : y; // Return x if it's lesser
}

// Function to return the minimum of two int values
int min(int x, int y) {
    return (int)min64((int64_t)x, (int64_t)y); // Convert int to int64_t and find min
}

// Function to return the absolute value of an int64_t
int64_t abs64(int64_t x) {
    return x < 0 ? -x : x; // Return negation if x is negative
}

// Function to return the absolute value of an int
int abs(int x) {
    return (int)abs64((int64_t)x); // Convert int to int64_t and find absolute
}

// Function to join a slice of int64_t values into a string with a separator
char* joinInt64s(int64_t *a, int len, const char *sep) {
    char *result = (char *)malloc(1024 * sizeof(char)); // Allocate initial buffer
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    result[0] = '\0'; // Initialize result as an empty string
    for (int i = 0; i < len; i++) {
        char temp[21]; // Buffer to hold each int64_t as string
        snprintf(temp, sizeof(temp), "%lld", a[i]);
        if (i > 0) {
            strcat(result, sep); // Append separator if not the first element
        }
        strcat(result, temp); // Append the current element
    }
    return result;
}

// Function to join a slice of int values into a string with a separator
char* joinInts(int *a, int len, const char *sep) {
    char *result = (char *)malloc(1024 * sizeof(char)); // Allocate initial buffer
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    result[0] = '\0'; // Initialize result as an empty string
    for (int i = 0; i < len; i++) {
        char temp[12]; // Buffer to hold each int as string
        snprintf(temp, sizeof(temp), "%d", a[i]);
        if (i > 0) {
            strcat(result, sep); // Append separator if not the first element
        }
        strcat(result, temp); // Append the current element
    }
    return result;
}

// Function to perform ceiling division on two int64_t values
int64_t divUp64(int64_t x, int64_t y) {
    return (x + y - 1) / y; // Ceiling division
}

// Function to perform ceiling division on two int values
int divUp(int x, int y) {
    return (int)divUp64((int64_t)x, (int64_t)y); // Convert to int64_t and perform division
}

// Function to compute the greatest common divisor of two int64_t values
int64_t gcd64(int64_t x, int64_t y) {
    if (x < y) {
        int64_t temp = x;
        x = y;
        y = temp; // Ensure x is the larger value
    }
    while (y != 0) {
        int64_t temp = y;
        y = x % y;
        x = temp; // Euclidean algorithm
    }
    return x; // Return GCD
}

// Function to compute the greatest common divisor of two int values
int gcd(int x, int y) {
    return (int)gcd64((int64_t)x, (int64_t)y); // Convert to int64_t and find GCD
}

// Function to compute the least common multiple of two int64_t values
int64_t lcm64(int64_t x, int64_t y) {
    return x * y / gcd64(x, y); // LCM using GCD
}

// Function to compute the least common multiple of two int values
int lcm(int x, int y) {
    return (int)lcm64((int64_t)x, (int64_t)y); // Convert to int64_t and find LCM
}

// Function to compute x raised to the power of y for int64_t values
int64_t pow64(int64_t x, int64_t y) {
    return (int64_t)pow((double)x, (double)y); // Use pow for exponentiation
}

// Function to compute x raised to the power of y for int values
int pow(int x, int y) {
    return (int)pow64((int64_t)x, (int64_t)y); // Convert to int64_t and find power
}

// Main function to execute the program
int main() {
    initBufReader(); // Initialize the bufReader
    solve(); // Call the solve function
    fflush(writer); // Flush the writer to output results
    free(reader.buf); // Free the allocated memory for the buffer
    return 0;
}

// Function to compute the maximum profit and count
void solve() {
    int N = nextInt(); // Read number of elements
    int M = nextInt(); // Ignore the second value
    int A[N]; // Create an array to hold the elements
    for (int i = 0; i < N; i++) {
        A[i] = nextInt(); // Read each element into the array
    }
    int maxProfit = 0; // Initialize maximum profit
    int maxCnt = 0;    // Initialize count of maximum profit occurrences
    int maxA = A[N-1]; // Start with the last element as the maximum
    for (int i = N - 2; i >= 0; i--) { // Iterate backwards through the array
        int profit = max(0, maxA - A[i]); // Calculate profit based on the current element
        if (maxProfit < profit) { // If we found a new maximum profit
            maxProfit = profit; // Update maximum profit
            maxCnt = 1;         // Reset count to 1
        } else if (maxProfit == profit) { // If we found another occurrence of the maximum profit
            maxCnt++; // Increment the count
        }
        maxA = max(maxA, A[i]); // Update the maximum element seen so far
    }
    out("%d\n", maxCnt); // Output the count of maximum profit occurrences
}
