#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000

// Function prototypes
char* tenToN(int number, int n);
int readInt();
void write(const char* s);
void flush();

int main() {
    // Read input numbers N and K
    int N = readInt();
    int K = readInt();

    // Calculate the base-10 representation of N up to digit count K
    char* s = tenToN(N, K);

    // Print the length of the calculated string
    printf("%lu\n", strlen(s));

    // Free allocated memory
    free(s);
    return 0;
}

// Function to convert a number to its base-10 string representation
// with digit count K
char* tenToN(int number, int n) {
    char* s = (char*)malloc(32); // Allocate memory for the string
    if (!s) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    s[0] = '\0'; // Initialize the string

    int tmp = number; // Initialize temporary variable

    // Repeat the following process until the number becomes less than N
    while (1) {
        // Append the remainder of the division by N to the result string
        char buffer[12]; // Buffer to hold the string representation of the number
        sprintf(buffer, "%d", tmp % n);
        strcat(s, buffer);

        // If the number is less than N, break the loop
        if (tmp < n) {
            break;
        }

        // Divide the number by N
        tmp /= n;
    }

    // Reverse the string
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

    return s;
}

// Read an integer from standard input
int readInt() {
    int read;
    scanf("%d", &read);
    return read;
}

// Write a string to the output (not used in this code)
void write(const char* s) {
    printf("%s", s);
}

// Flush the output (not used in this code)
void flush() {
    fflush(stdout);
}
