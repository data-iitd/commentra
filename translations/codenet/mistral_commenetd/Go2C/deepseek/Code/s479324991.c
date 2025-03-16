#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the scanner state
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t position;
} Scanner;

// Initialize a new scanner object
Scanner* newScanner() {
    Scanner *sc = (Scanner*)malloc(sizeof(Scanner));
    sc->buffer_size = 1000;
    sc->buffer = (char*)malloc(sc->buffer_size);
    sc->position = 0;
    return sc;
}

// Read a single token from the standard input
char* next(Scanner *sc) {
    while (sc->position < sc->buffer_size && sc->buffer[sc->position] == ' ' || sc->buffer[sc->position] == '\n') {
        sc->position++;
    }
    if (sc->position >= sc->buffer_size) {
        fgets(sc->buffer, sc->buffer_size, stdin);
        sc->position = 0;
    }
    size_t start = sc->position;
    while (sc->position < sc->buffer_size && sc->buffer[sc->position] != ' ' && sc->buffer[sc->position] != '\n') {
        sc->position++;
    }
    char *result = (char*)malloc(sc->position - start + 1);
    strncpy(result, sc->buffer + start, sc->position - start);
    result[sc->position - start] = '\0';
    return result;
}

// Read an integer from the standard input
int nextInt(Scanner *sc) {
    char *token = next(sc);
    int value = atoi(token);
    free(token);
    return value;
}

// Read a line from the standard input
char* nextLine(Scanner *sc) {
    while (sc->position < sc->buffer_size && (sc->buffer[sc->position] == ' ' || sc->buffer[sc->position] == '\n')) {
        sc->position++;
    }
    if (sc->position >= sc->buffer_size) {
        fgets(sc->buffer, sc->buffer_size, stdin);
        sc->position = 0;
    }
    size_t start = sc->position;
    while (sc->position < sc->buffer_size && sc->buffer[sc->position] != '\n') {
        sc->position++;
    }
    char *result = (char*)malloc(sc->position - start + 1);
    strncpy(result, sc->buffer + start, sc->position - start);
    result[sc->position - start] = '\0';
    return result;
}

// Main function to read input and calculate the average
int main() {
    Scanner *sc = newScanner();

    // Read the number of elements in the array from the standard input
    int n = nextInt(sc);

    // Allocate memory for the array of size n
    double *arr = (double*)malloc(n * sizeof(double));

    // Read n integers from the standard input and store them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt(sc);
    }

    // Sort the array in ascending order
    qsort(arr, n, sizeof(double), (int (*)(const void *, const void *))compare);

    // Initialize a variable prev to store the previous element in the sorted array
    double prev = arr[0];

    // Iterate through the sorted array from the second element to the last
    for (int i = 1; i < n; i++) {
        // Calculate the average of the previous and current elements
        prev = (prev + arr[i]) / 2;
    }

    // Print the result to the standard output
    printf("%f\n", prev);

    // Free allocated memory
    free(arr);
    free(sc->buffer);
    free(sc);

    return 0;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    double diff = (*(double*)a - *(double*)b);
    return (diff > 0) - (diff < 0);
}
