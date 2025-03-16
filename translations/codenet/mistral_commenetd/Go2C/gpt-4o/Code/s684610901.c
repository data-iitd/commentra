#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000
#define INF 100000000

// Function prototypes
int64_t readInt();
void write(const char *s);
void print();
int64_t max(int64_t a, int64_t b);
int64_t min(int64_t a, int64_t b);
int64_t abs(int64_t i);

// Main function
int main() {
    // Read input A, B, and C
    int64_t A = readInt();
    int64_t B = readInt();
    int64_t C = readInt();

    // Check if C is within the range of A and B
    if (C >= A && C <= B) {
        printf("Yes\n"); // Print "Yes" if condition is true
    } else {
        printf("No\n");  // Print "No" if condition is false
    }

    return 0;
}

// Function to read an integer from input
int64_t readInt() {
    int64_t num;
    scanf("%lld", &num);
    return num;
}

// Function to write a string to the output
void write(const char *s) {
    printf("%s", s);
}

// Function to print a newline
void print() {
    fflush(stdout);
}

// Function to get the maximum of two integers
int64_t max(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

// Function to get the minimum of two integers
int64_t min(int64_t a, int64_t b) {
    return (a < b) ? a : b;
}

// Function to get the absolute value of an integer
int64_t abs(int64_t i) {
    return (i < 0) ? -i : i;
}

// Additional helper functions can be added here as needed

// <END-OF-CODE>
