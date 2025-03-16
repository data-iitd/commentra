
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 512000

// Define a constant for the buffer size used in input and output operations
#define BUFFERSIZE 512000

// Initialize a Scanner for reading input with a buffered reader for efficiency
static Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in), BUFFERSIZE));

// Initialize a PrintWriter for output with a buffered output stream for efficiency
static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out, BUFFERSIZE));

// Method to solve the main problem
void solve() {
    // Read the position from input
    long position = sc.nextLong();

    // Initialize the nearest sequence start index
    long nrstSeqStartIndx = 1;

    // Find the nearest sequence start index such that its value is less than the position
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Increment the nearest sequence start index until its value exceeds the position
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    // Get the starting index value for the nearest sequence
    long startIndex = getValueAtIndex(nrstSeqStartIndx);

    // Output the result, which is the difference between the position and the start index plus one
    printf("%ld\n", (position - startIndex) + 1);
}

// Method to calculate the value at a given index based on a specific formula
long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

// Main method to execute the program
int main(int argc, char *argv[]) {
    // Initialize the input reader
    in.init(stdin);

    // Call the solve method to process the input and produce output
    solve();

    // Close the output stream
    fclose(stdout);

    return 0;
}

// Static inner class for handling input operations
static class in {
    static FILE *fp; // File pointer for reading input
    static char buffer[BUFFERSIZE + 1]; // Buffer for reading input
    static int bufIndex; // Index for tracking the current position in the buffer
    static int bufSize; // Size of the buffer

    // Method to initialize the input reader
    static void init(FILE *input) {
        fp = input;
        bufIndex = 0;
        bufSize = fread(buffer, 1, BUFFERSIZE, fp);
        buffer[bufSize] = '\n';
    }

    // Method to get the next token from input
    static char *next() {
        while (buffer[bufIndex] <='') {
            bufIndex++;
        }
        char *start = &buffer[bufIndex];
        while (buffer[bufIndex] >'') {
            bufIndex++;
        }
        buffer[bufIndex] = '\0';
        return start;
    }

    // Method to get the next integer from input
    static int nextInt() {
        int result = 0;
        int negative = 1;
        if (buffer[bufIndex] == '-') {
            negative = -1;
            bufIndex++;
        }
        while (buffer[bufIndex] >= '0' && buffer[bufIndex] <= '9') {
            result = result * 10 + buffer[bufIndex] - '0';
            bufIndex++;
        }
        return result * negative;
    }

    // Method to get the next double from input
    static double nextDouble() {
        double result = 0;
        int negative = 1;
        int decimalPlaces = 0;
        if (buffer[bufIndex] == '-') {
            negative = -1;
            bufIndex++;
        }
        while (buffer[bufIndex] >= '0' && buffer[bufIndex] <= '9') {
            result = result * 10 + buffer[bufIndex] - '0';
            bufIndex++;
        }
        if (buffer[bufIndex] == '.') {
            bufIndex++;
            while (buffer[bufIndex] >= '0' && buffer[bufIndex] <= '9') {
                result = result + (buffer[bufIndex] - '0') / pow(10, decimalPlaces);
                decimalPlaces++;
                bufIndex++;
            }
        }
        return result * negative;
    }

    // Method to get the next long from input
    static long nextLong() {
        long result = 0;
        int negative = 1;
        if (buffer[bufIndex] == '-') {
            negative = -1;
            bufIndex++;
        }
        while (buffer[bufIndex] >= '0' && buffer[bufIndex] <= '9') {
            result = result * 10 + buffer[bufIndex] - '0';
            bufIndex++;
        }
        return result * negative;
    }
}

