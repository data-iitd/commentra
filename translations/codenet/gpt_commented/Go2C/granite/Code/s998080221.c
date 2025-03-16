
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define bufReader struct to handle buffered reading from standard input
typedef struct {
    char *buf;
    int i;
} bufReader;

// Initialize a global bufReader instance for reading input
bufReader reader = {NULL, 0};

// readLine reads a line from the buffered reader into the buffer
void readLine() {
    if (reader.i < strlen(reader.buf)) {
        return; // Return if there are still bytes to read
    }
    free(reader.buf); // Reset buffer
    reader.buf = NULL; // Reset buffer
    reader.i = 0; // Reset index
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin)!= -1) {
        reader.buf = line; // Set buffer to the read line
        break; // Break if the line is not a prefix
    }
}

// next reads the next token from the buffer
char *next() {
    readLine(); // Ensure the buffer is filled
    char *from = reader.buf + reader.i; // Store the starting index
    for (; reader.i < strlen(reader.buf); reader.i++) {
        if (reader.buf[reader.i] =='') { // Stop at space
            break;
        }
    }
    char *s = strndup(from, reader.i - from); // Extract the token
    reader.i++; // Move index forward
    return s;
}

// nextLine reads the next full line from the buffer
char *nextLine() {
    readLine(); // Ensure the buffer is filled
    char *s = strndup(reader.buf + reader.i, strlen(reader.buf) - reader.i); // Get the remaining line
    reader.i = strlen(reader.buf); // Move index to the end of buffer
    return s;
}

// nextInt reads the next token as an int
int nextInt() {
    char *s = next(); // Read the next token
    int i = atoi(s); // Convert token to int
    free(s); // Free the allocated memory for the token
    return i;
}

// nextInt64 reads the next token as an int64
int64_t nextInt64() {
    char *s = next(); // Read the next token
    int64_t i = atoll(s); // Convert token to int64
    free(s); // Free the allocated memory for the token
    return i;
}

// out writes the output to the standard output
void out(int a,...) {
    va_list args; // Initialize variable arguments
    va_start(args, a); // Start processing variable arguments
    for (int i = 0; i < a; i++) {
        int value = va_arg(args, int); // Get the next argument
        printf("%d ", value); // Print the argument to the standard output
    }
    printf("\n"); // Print a new line
    va_end(args); // End processing variable arguments
}

// max returns the maximum of two int values
int max(int x, int y) {
    return x > y? x : y; // Return the maximum of x and y
}

// min returns the minimum of two int values
int min(int x, int y) {
    return x < y? x : y; // Return the minimum of x and y
}

// abs returns the absolute value of an int
int abs(int x) {
    return x < 0? -x : x; // Return the absolute value of x
}

// joinInts joins a slice of ints into a string with a separator
char *joinInts(int *a, int n, char *sep) {
    char *result = malloc(1024 * sizeof(char)); // Allocate memory for the result
    int len = 0; // Initialize length of the result
    for (int i = 0; i < n; i++) {
        len += sprintf(result + len, "%d%s", a[i], i == n - 1? "" : sep); // Append each element to the result
    }
    return result; // Return the joined string
}

// divUp performs ceiling division on two int values
int divUp(int x, int y) {
    return (x + y - 1) / y; // Ceiling division
}

// gcd computes the greatest common divisor of two int values
int gcd(int x, int y) {
    if (x < y) {
        int t = x; // Swap x and y if x is smaller
        x = y;
        y = t;
    }
    while (y!= 0) {
        int t = x % y; // Euclidean algorithm
        x = y;
        y = t;
    }
    return x; // Return GCD
}

// lcm computes the least common multiple of two int values
int lcm(int x, int y) {
    return x * y / gcd(x, y); // LCM using GCD
}

// pow computes x raised to the power of y for int values
int pow(int x, int y) {
    int result = 1; // Initialize result to 1
    for (int i = 0; i < y; i++) {
        result *= x; // Multiply result by x
    }
    return result; // Return the result
}

// main function to execute the program
int main() {
    int N = nextInt(); // Read number of elements
    int _ = nextInt(); // Ignore the second value
    int *A = malloc(N * sizeof(int)); // Allocate memory for the elements
    for (int i = 0; i < N; i++) {
        A[i] = nextInt(); // Read each element into the array
    }
    int maxProfit = 0; // Initialize maximum profit
    int maxCnt = 0; // Initialize count of maximum profit occurrences
    int maxA = A[N - 1]; // Start with the last element as the maximum
    for (int i = N - 2; i >= 0; i--) { // Iterate backwards through the array
        int profit = max(0, maxA - A[i]); // Calculate profit based on the current element
        if (profit > maxProfit) { // If we found a new maximum profit
            maxProfit = profit; // Update maximum profit
            maxCnt = 1; // Reset count to 1
        } else if (profit == maxProfit) { // If we found another occurrence of the maximum profit
            maxCnt++; // Increment the count
        }
        maxA = max(maxA, A[i]); // Update the maximum element seen so far
    }
    out(maxCnt); // Output the count of maximum profit occurrences
    free(A); // Free the allocated memory for the elements
    return 0; // Return 0 to indicate successful execution
}

