
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for buffer sizes
#define INITIAL_BUF_SIZE 10000 // Initial buffer size for the scanner
#define MAX_BUF_SIZE 10000000 // Maximum buffer size for the scanner

// Create a new scanner to read from standard input
static char buf[MAX_BUF_SIZE];
static int buf_pos = 0;
static int buf_len = 0;

// Function to read the next word from input
static char* next() {
    while (buf_pos >= buf_len) {
        buf_pos = 0;
        buf_len = fread(buf, 1, MAX_BUF_SIZE, stdin);
        if (buf_len == 0) {
            exit(1);
        }
    }
    while (buf[buf_pos] =='' || buf[buf_pos] == '\n') {
        buf_pos++;
    }
    int start_pos = buf_pos;
    while (buf[buf_pos]!='' && buf[buf_pos]!= '\n') {
        buf_pos++;
    }
    char* res = (char*)malloc(buf_pos - start_pos + 2);
    memcpy(res, buf + start_pos, buf_pos - start_pos);
    res[buf_pos - start_pos] = '\0';
    return res;
}

// Function to return the minimum of two integers
static int min(int x, int y) {
    return x < y? x : y;
}

// Main function where the program execution begins
int main() {
    char* S = next(); // Read the input string

    int l0 = 0, l1 = 0; // Initialize counters for '0's and '1's
    // Loop through each character in the input string
    for (int i = 0; S[i]!= '\0'; i++) {
        if (S[i] == '0') {
            l0++; // Increment the counter for '0'
        } else {
            l1++; // Increment the counter for '1'
        }
    }
    // Print the result, which is twice the minimum count of '0's or '1's
    printf("%d\n", 2 * min(l0, l1)); // Print the result
    free(S); // Free the memory allocated for the input string
    return 0;
}
