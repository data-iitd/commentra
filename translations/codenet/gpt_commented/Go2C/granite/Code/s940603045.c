
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an infinite value for comparison
#define inf INT_MAX

// Initialize a new scanner for input
typedef struct {
    char *buf;
    int p;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(10000 * sizeof(char));
    s->p = 0;
    return s;
}

// Read the next token from the input
char *next(Scanner *s) {
    s->pre(s); // Ensure the buffer is filled
    int start = s->p; // Mark the start of the token
    while (s->p < 10000 && s->buf[s->p]!='') { // Stop at space
        s->p++;
    }
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start); // Extract the token
    result[s->p - start] = '\0';
    s->p++; // Move past the space
    return result;
}

// Read the entire line from the input
char *Line(Scanner *s) {
    s->pre(s); // Ensure the buffer is filled
    int start = s->p; // Mark the start of the line
    s->p = 10000; // Move to the end of the buffer
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start); // Return the line
    result[s->p - start] = '\0';
    return result;
}

// Read the next string from the input
char *String(Scanner *s) {
    return next(s); // Call next to get the next token
}

// Read the next integer from the input
int Int(Scanner *s) {
    char *token = next(s); // Get the next token
    int result = atoi(token); // Convert the token to an integer
    free(token); // Free the memory allocated for the token
    return result;
}

// Read multiple integers from the input
int *Ints(Scanner *s, int n) {
    int *result = (int *)malloc(n * sizeof(int)); // Create a slice to hold the integers
    for (int i = 0; i < n; i++) {
        result[i] = Int(s); // Read each integer
    }
    return result;
}

// Read the next int64 from the input
long long Int64(Scanner *s) {
    char *token = next(s); // Get the next token
    long long result = atoll(token); // Convert the token to int64
    free(token); // Free the memory allocated for the token
    return result;
}

// Read the next uint64 from the input
unsigned long long Uint64(Scanner *s) {
    char *token = next(s); // Get the next token
    unsigned long long result = strtoull(token, NULL, 10); // Convert the token to uint64
    free(token); // Free the memory allocated for the token
    return result;
}

// Read the next float64 from the input
double Float64(Scanner *s) {
    char *token = next(s); // Get the next token
    double result = atof(token); // Convert the token to float64
    free(token); // Free the memory allocated for the token
    return result;
}

// Pre-read to ensure there is data in the buffer
void pre(Scanner *s) {
    if (s->p >= 10000) { // If current position is at the end of the buffer
        readLine(s); // Read a new line
        s->p = 0; // Reset position to the start of the new buffer
    }
}

// Read a line from the input and fill the buffer
void readLine(Scanner *s) {
    free(s->buf); // Free the existing buffer
    s->buf = (char *)malloc(10000 * sizeof(char)); // Reset the buffer
    while (1) {
        char *l = (char *)malloc(10000 * sizeof(char)); // Read a line
        fgets(l, 10000, stdin); // Read a line
        strncat(s->buf, l, 10000); // Append line to buffer
        free(l); // Free the memory allocated for the line
        if (feof(stdin)) { // If the end of the file is reached
            break;
        }
    }
}

int main() {
    Scanner *s = newScanner(); // Create a new scanner
    char *N = String(s); // Read the input as a string
    int n = 0; // Initialize sum of digits
    for (int i = 0; i < strlen(N); i++) {
        n += N[i] - '0'; // Convert each character to an integer and accumulate
    }
    free(N); // Free the memory allocated for the input string
    int m = Int(s); // Read the input as an integer
    if (m % n == 0) {
        printf("Yes\n"); // Print "Yes" if divisible
    } else {
        printf("No\n"); // Print "No" if not divisible
    }
    free(s->buf); // Free the memory allocated for the buffer
    free(s); // Free the memory allocated for the scanner
    return 0;
}

