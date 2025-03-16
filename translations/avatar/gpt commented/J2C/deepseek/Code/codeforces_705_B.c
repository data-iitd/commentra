#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastReader structure to handle fast input
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t input_pos;
} FastReader;

// Function to initialize FastReader
void initFastReader(FastReader *fr, size_t buffer_size) {
    fr->buffer = (char *)malloc(buffer_size);
    fr->buffer_size = buffer_size;
    fr->input_pos = 0;
}

// Function to read the next token from input
char* next(FastReader *fr) {
    // Read new line if no tokens are available
    if (fr->input_pos >= fr->buffer_size) {
        fread(fr->buffer, 1, fr->buffer_size, stdin);
        fr->input_pos = 0;
    }
    return fr->buffer + fr->input_pos++;
}

// Function to read the next integer from input
int nextInt(FastReader *fr) {
    char *token = next(fr);
    int value = 0;
    while (*token >= '0' && *token <= '9') {
        value = value * 10 + (*token - '0');
        token = next(fr);
    }
    return value;
}

// Function to read the next long from input
long nextLong(FastReader *fr) {
    char *token = next(fr);
    long value = 0;
    while (*token >= '0' && *token <= '9') {
        value = value * 10 + (*token - '0');
        token = next(fr);
    }
    return value;
}

// Function to read the next double from input
double nextDouble(FastReader *fr) {
    char *token = next(fr);
    double value = 0.0;
    while (*token >= '0' && *token <= '9') {
        value = value * 10 + (*token - '0');
        token = next(fr);
    }
    if (*token == '.') {
        token = next(fr);
        double decimal_place = 0.1;
        while (*token >= '0' && *token <= '9') {
            value += (*token - '0') * decimal_place;
            decimal_place *= 0.1;
            token = next(fr);
        }
    }
    return value;
}

// Function to read the next line from input
char* nextLine(FastReader *fr) {
    char *line = (char *)malloc(1000);
    fgets(line, 1000, stdin);
    return line;
}

// Create an instance of FastReader for input
FastReader fr;

// Function to solve the problem
void solve() {
    // Read the number of elements in the array
    int t = nextInt(&fr);
    int arr[t];

    // Populate the array with input values
    for (int i = 0; i < t; i++) {
        arr[i] = nextInt(&fr);
    }

    int prevWinner = 0; // Variable to track the previous winner

    // Iterate through the array to determine the winner for each element
    for (int i = 0; i < t; i++) {
        // Check if the current element is 1
        if (arr[i] == 1) {
            // If the previous winner is 0, set the previous winner to 2
            if (prevWinner == 0) {
                prevWinner = 2;
            }
        }

        // Determine the winner based on the previous winner and the current element
        if (prevWinner == 2 || prevWinner == 0) {
            // If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) {
                printf("2\n"); // Print winner 2
                prevWinner = 2; // Update previous winner
            } else {
                printf("1\n"); // Print winner 1
                prevWinner = 1; // Update previous winner
            }
        } else {
            // If the previous winner is 1, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) {
                printf("1\n"); // Print winner 1
                prevWinner = 1; // Update previous winner
            } else {
                printf("2\n"); // Print winner 2
                prevWinner = 2; // Update previous winner
            }
        }
    }
}

int main() {
    initFastReader(&fr, 1024); // Initialize FastReader with buffer size 1024
    int t = 1; // Number of test cases (currently set to 1)
    while (t-- > 0) {
        solve(); // Call the solve method for processing
    }
    return 0;
}
