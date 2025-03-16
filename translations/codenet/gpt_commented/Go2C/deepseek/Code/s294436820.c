#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define DEBUG 0

// -----------------------------------------------------------------------------

// IO helper functions

// nextToken and nextLine are function variables that will be initialized 
// by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
char* nextToken();
char* nextLine();

// OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
FILE* OutputBuffer = NULL;

// OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
FILE* OutputWriter = NULL;

// SetInteractive configures the IO functions for interactive input/output.
void SetInteractive(FILE* w, FILE* r) {
    SetUnbufferedInput(r); // Set unbuffered input for reading
    OutputBuffer = NULL;     // No output buffer for interactive mode
    OutputWriter = w;       // Set the output writer
}

// Setup OutputBuffer and OutputWriter for buffered output.
void SetOutput(FILE* w) {
    OutputBuffer = w; // Initialize the output buffer
    OutputWriter = OutputBuffer;         // Set the output writer to the buffer
}

// Flushes OutputBuffer to ensure all buffered data is written out.
void Flush() {
    if (OutputBuffer != NULL) {
        fflush(OutputBuffer); // Flush the buffer if it is initialized
    }
}

// IsSpace checks if a character is a whitespace character.
bool IsSpace(char c) {
    switch (c) {
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case ' ':
            return true;
    }
    return false;
}

// IsNewLine checks if a character is a newline character.
bool IsNewLine(char c) {
    switch (c) {
        case '\n':
        case '\r':
            return true;
    }
    return false;
}

// SetInput initializes the nextToken function with an input buffer.
void SetInput(FILE* r) {
    // Function to read the next token from the input
    char* rest() {
        static char buffer[1024];
        int i = 0;
        char c;
        while (isspace(c = fgetc(r)) && c != EOF); // Skip whitespace
        if (c == EOF) return NULL;
        buffer[i++] = c;
        while (!isspace(c = fgetc(r)) && c != EOF) {
            buffer[i++] = c;
        }
        buffer[i] = '\0';
        return buffer;
    }

    // Function to initialize reading from the input
    char* initial() {
        char buffer[1024];
        int i = 0;
        char c;
        while ((c = fgetc(r)) != EOF) {
            buffer[i++] = c;
        }
        buffer[i] = '\0';
        nextToken = rest;
        return rest();
    }
    nextToken = initial;

    // Function to read the next line from the input
    char* restLn() {
        static char buffer[1024];
        int i = 0;
        char c;
        while (IsNewLine(c = fgetc(r)) && c != EOF); // Skip new line characters
        if (c == EOF) return NULL;
        buffer[i++] = c;
        while (!IsNewLine(c = fgetc(r)) && c != EOF) {
            buffer[i++] = c;
        }
        buffer[i] = '\0';
        return buffer;
    }

    // Function to initialize reading lines from the input
    char* initialLn() {
        char buffer[1024];
        int i = 0;
        char c;
        while ((c = fgetc(r)) != EOF) {
            buffer[i++] = c;
        }
        buffer[i] = '\0';
        nextLine = restLn;
        return restLn();
    }
    nextLine = initialLn;
}

// SetUnbufferedInput configures the nextToken function for unbuffered input.
void SetUnbufferedInput(FILE* r) {
    // Function to read the next token from the input
    char* nextToken() {
        static char buffer[1024];
        int i = 0;
        char c;
        while (isspace(c = fgetc(r)) && c != EOF); // Skip whitespace
        if (c == EOF) return NULL;
        buffer[i++] = c;
        while (!isspace(c = fgetc(r)) && c != EOF) {
            buffer[i++] = c;
        }
        buffer[i] = '\0';
        return buffer;
    }
}

// -----------------------------------------------------------------------------

// IO functions

// readb reads the next token and returns it as a byte slice.
char* readb() {
    char* b = nextToken(); // Read the next token
    if (b == NULL) {
        fprintf(stderr, "Error: Unexpected EOF\n");
        exit(1);
    }
    return b;
}

// reads reads the next token and returns it as a string.
char* reads() {
    return readb(); // Convert byte slice to string
}

// readbln reads the next line as a byte slice, excluding the trailing newline.
char* readbln() {
    char* b = nextLine(); // Read the next line
    if (b == NULL) {
        fprintf(stderr, "Error: Unexpected EOF\n");
        exit(1);
    }
    return b;
}

// readsln reads the next line and returns it as a string.
char* readsln() {
    return readbln(); // Convert byte slice to string
}

// readll reads the next token and returns it as an int64.
int64_t readll() {
    char* str = reads(); // Read the next token as a string
    int64_t i = strtoll(str, NULL, 10); // Parse the string as int64
    free(str); // Free the allocated memory for the string
    return i; // Return the parsed int64
}

// readi reads the next token and returns it as an int.
int readi() {
    return (int)readll(); // Convert int64 to int
}

// readf reads the next token and returns it as a float64.
double readf() {
    char* str = reads(); // Read the next token as a string
    double f = strtod(str, NULL); // Parse the string as float64
    free(str); // Free the allocated memory for the string
    return f; // Return the parsed float64
}

// printf writes formatted output to OutputWriter.
int printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vfprintf(OutputWriter, format, args);
    va_end(args);
    return ret;
}

// println writes output to OutputWriter without formatting.
int println(const char* args) {
    return fprintf(OutputWriter, "%s\n", args);
}

// eprintf writes formatted output to stderr.
int eprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vfprintf(stderr, format, args);
    va_end(args);
    return ret;
}

// eprintln writes output to stderr without formatting.
int eprintln(const char* args) {
    return fprintf(stderr, "%s\n", args);
}

// debugf writes formatted debug output to stderr if DEBUG is enabled.
void debugf(const char* format, ...) {
    if (!DEBUG) {
        return; // Do nothing if DEBUG is not enabled
    }
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

// debug writes debug output to stderr if DEBUG is enabled.
void debug(const char* args) {
    if (!DEBUG) {
        return; // Do nothing if DEBUG is not enabled
    }
    fprintf(stderr, "%s\n", args);
}

// -----------------------------------------------------------------------------

// Utilities

// sumSlice calculates the sum of a slice of integers.
int sumSlice(int* a, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += a[i]; // Accumulate the sum
    }
    return res; // Return the total sum
}

// sumSlicell calculates the sum of a slice of int64.
int64_t sumSlicell(int64_t* a, int size) {
    int64_t res = 0;
    for (int i = 0; i < size; i++) {
        res += a[i]; // Accumulate the sum
    }
    return res; // Return the total sum
}

// readInts reads N integers from input and returns the count and the slice.
int readInts(int* a, int N) {
    if (N == 0) {
        N = readi(); // Read N if it is zero
    }
    for (int i = 0; i < N; i++) {
        a[i] = readi(); // Read each integer
    }
    return N; // Return the count
}

// readIntsll reads N int64 values from input and returns the count and the slice.
int readIntsll(int64_t* a, int N) {
    if (N == 0) {
        N = readi(); // Read N if it is zero
    }
    for (int i = 0; i < N; i++) {
        a[i] = readll(); // Read each int64 value
    }
    return N; // Return the count
}

// -----------------------------------------------------------------------------

// Simple math functions

#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

// min returns the smaller of two integers.
int min(int a, int b) {
    return a < b ? a : b; // Return a if it is smaller
}

// minll returns the smaller of two int64 values.
int64_t minll(int64_t a, int64_t b) {
    return a < b ? a : b; // Return a if it is smaller
}

// minf returns the smaller of two float64 values.
double minf(double a, double b) {
    return a < b ? a : b; // Return a if it is smaller
}

// max returns the larger of two integers.
int max(int a, int b) {
    return a < b ? b : a; // Return b if it is larger
}

// maxll returns the larger of two int64 values.
int64_t maxll(int64_t a, int64_t b) {
    return a < b ? b : a; // Return b if it is larger
}

// maxf returns the larger of two float64 values.
double maxf(double a, double b) {
    return a < b ? b : a; // Return b if it is larger
}

// abs returns the absolute value of an integer.
int abs(int a) {
    return a < 0 ? -a : a; // Return negative if a is less than zero
}

// absll returns the absolute value of an int64.
int64_t absll(int64_t a) {
    return a < 0 ? -a : a; // Return negative if a is less than zero
}

// absf returns the absolute value of a float64.
double absf(double a) {
    return a < 0 ? -a : a; // Return negative if a is less than zero
}

// egcd computes the extended GCD of a and b, returning d, x, y.
int egcd(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int d, x1, y1;
    d = egcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - a / b * y1;
    return d;
}

// egcdll computes the extended GCD of a and b for int64 values.
int64_t egcdll(int64_t a, int64_t b, int64_t* x, int64_t* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int64_t d, x1, y1;
    d = egcdll(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - a / b * y1;
    return d;
}

// gcd computes the GCD of a and b.
int gcd(int a, int b) {
    int d, x, y;
    d = egcd(a, b, &x, &y);
    return d;
}

// gcdll computes the GCD of a and b for int64 values.
int64_t gcdll(int64_t a, int64_t b) {
    int64_t d, x, y;
    d = egcdll(a, b, &x, &y);
    return d;
}

// set up IO functions
void init() {
    // Initialize input and output for non-interactive mode
    SetInput(stdin);
    SetOutput(stdout);

    // Uncomment below to enable interactive mode
    // SetInteractive(stdout, stdin);
}

// main function to execute the program logic
int main() {
    init(); // Initialize IO functions
    defer(Flush()); // Ensure output is flushed at the end

    int h = readi(), w = readi(), k = readi(); // Read height, width, and target count
    int m[h][w]; // Create a 2D array for the grid
    for (int i = 0; i < h; i++) {
        char* s = readsln(); // Read the row as a string
        for (int j = 0; j < w; j++) {
            m[i][j] = s[j]; // Convert each character to int and store
        }
    }

    int answer = solve(h, w, k, m); // Solve the problem and get the answer
    printf("%d\n", answer); // Print the answer

    return 0;
}

#define Black 35 // Define a constant for the black color

// countBlack counts the number of black cells in the grid.
int countBlack(int h, int w, int m[h][w]) {
    int count = 0; // Initialize count
    debug("new table\n"); // Debug output for new table
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == Black) {
                count++; // Increment count if the cell is black
            }
        }
        debug("%d\n", m[i][j]); // Debug output for the current row
    }
    debug("result : %d\n", count); // Debug output for the result
    return count; // Return the count of black cells
}

// solve calculates the number of ways to paint the grid to achieve the target count of black cells.
int solve(int h, int w, int a, int m[h][w]) {
    int result = 0; // Initialize result
    for (int i = 0; i < 1 << h; i++) { // Iterate over all possible row paint combinations
        for (int k = 0; k < 1 << w; k++) { // Iterate over all possible column paint combinations
            int tmp[h][w]; // Create a temporary grid to simulate painting
            memcpy(tmp, m, sizeof(m)); // Copy original grid to temporary grid
            // Paint rows based on the current combination
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) { // Check if the current row is painted
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1; // Paint the entire row
                    }
                }
            }
            // Paint columns based on the current combination
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) { // Check if the current column is painted
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1; // Paint the entire column
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) { // Check if the count of black cells matches the target
                result++; // Increment result if it matches
            }
        }
    }
    return result; // Return the total number of valid combinations
}

