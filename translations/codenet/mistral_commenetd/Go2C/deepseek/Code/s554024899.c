#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Define a scanner structure
typedef struct {
    FILE *file;
    char *buffer;
    size_t bufferSize;
    size_t bufferIndex;
} Scanner;

// Initialize a new scanner object
Scanner* newScanner() {
    Scanner *scanner = (Scanner*)malloc(sizeof(Scanner));
    scanner->file = stdin;
    scanner->bufferSize = 1000;
    scanner->buffer = (char*)malloc(scanner->bufferSize);
    scanner->bufferIndex = 0;
    return scanner;
}

// Function to read a single word from the input
char* next(Scanner *scanner) {
    while (scanner->buffer[scanner->bufferIndex] == ' ' || scanner->buffer[scanner->bufferIndex] == '\n') {
        scanner->bufferIndex++;
    }
    size_t start = scanner->bufferIndex;
    while (scanner->buffer[scanner->bufferIndex] != ' ' && scanner->buffer[scanner->bufferIndex] != '\n' && scanner->buffer[scanner->bufferIndex] != '\0') {
        scanner->bufferIndex++;
    }
    char *result = (char*)malloc(scanner->bufferIndex - start + 1);
    strncpy(result, scanner->buffer + start, scanner->bufferIndex - start);
    result[scanner->bufferIndex - start] = '\0';
    return result;
}

// Function to read a line from the input
char* nextLine(Scanner *scanner) {
    size_t start = scanner->bufferIndex;
    while (scanner->buffer[scanner->bufferIndex] != '\n' && scanner->buffer[scanner->bufferIndex] != '\0') {
        scanner->bufferIndex++;
    }
    char *result = (char*)malloc(scanner->bufferIndex - start + 1);
    strncpy(result, scanner->buffer + start, scanner->bufferIndex - start);
    result[scanner->bufferIndex - start] = '\0';
    return result;
}

// Function to read an integer from the input
int nextInt(Scanner *scanner) {
    char *str = next(scanner);
    int result = atoi(str);
    free(str);
    return result;
}

// Function to prepare the scanner for the next input
void pre(Scanner *scanner) {
    if (scanner->bufferIndex >= scanner->bufferSize) {
        size_t bytesRead = fread(scanner->buffer, 1, scanner->bufferSize, scanner->file);
        if (bytesRead == 0) {
            scanner->buffer[0] = '\0';
            return;
        }
        scanner->buffer[bytesRead] = '\0';
        scanner->bufferIndex = 0;
    }
}

// Function to read a line from the input
void readLine(Scanner *scanner) {
    scanner->bufferIndex = 0;
    size_t bytesRead = fread(scanner->buffer, 1, scanner->bufferSize, scanner->file);
    if (bytesRead == 0) {
        scanner->buffer[0] = '\0';
        return;
    }
    scanner->buffer[bytesRead] = '\0';
}

int main() {
    Scanner *scanner = newScanner();

    // Read the first two integers from the standard input using the scanner
    int x = nextInt(scanner);
    int y = nextInt(scanner);

    // Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
    int xt = -1, yt = -1;

    // Define a 3x3 2D array a
    int a[3][7] = {
        {1, 3, 5, 7, 8, 10, 12},
        {4, 6, 9, 11},
        {2}
    };

    // Iterate through each inner loop of the outer loop
    for (int i = 0; i < 3; i++) {
        // Iterate through each element of the current inner loop
        for (int j = 0; j < sizeof(a[i]) / sizeof(a[i][0]); j++) {
            // Check if the current element is equal to x, if yes, store its index in xt
            if (x == a[i][j]) {
                xt = i;
            }
            // Check if the current element is equal to y, if yes, store its index in yt
            if (y == a[i][j]) {
                yt = i;
            }
        }
    }

    // Check if the indices xt and yt are equal, if yes, print "Yes"
    if (xt == yt) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free allocated memory
    free(scanner->buffer);
    free(scanner);

    return 0;
}
