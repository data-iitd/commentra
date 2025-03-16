
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Set log flags to show the file name and line number for log messages
    setbuf(stderr, NULL);
    setvbuf(stdout, NULL, _IONBF, 0);

    // Initialize a new scanner to read input
    Scanner *sc = newScanner();

    // Read two integers from input
    int x = sc->nextInt(sc);
    int y = sc->nextInt(sc);

    // Initialize variables to store the category indices of x and y
    int xt = -1;
    int yt = -1;

    // Define a 2D array where each sub-array represents a category of numbers
    int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

    // Iterate through the categories to find the indices of x and y
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            // Check if the current number matches x
            if (x == a[i][j]) {
                xt = i; // Store the category index for x
            }
            // Check if the current number matches y
            if (y == a[i][j]) {
                yt = i; // Store the category index for y
            }
        }
    }

    // Compare the category indices of x and y and print the result
    if (xt == yt) {
        printf("Yes\n"); // x and y belong to the same category
    } else {
        printf("No\n");  // x and y belong to different categories
    }

    // Free the scanner memory
    freeScanner(sc);

    return 0;
}

// max returns the maximum of two integers
int max(int a, int b) {
    return a > b? a : b;
}

// Scanner struct to handle buffered input reading
typedef struct {
    char *buf; // Buffer to hold read data
    int p; // Current position in the buffer
    int size; // Size of the buffer
    FILE *fp; // File pointer
} Scanner;

// newScanner initializes a new scanner with a specified buffer size
Scanner *newScanner() {
    Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
    sc->buf = (char *)malloc(1000 * sizeof(char));
    sc->p = 0;
    sc->size = 1000;
    sc->fp = stdin;
    return sc;
}

// next reads the next token from the input
char *next(Scanner *sc) {
    sc->pre(sc); // Ensure there's data to read
    int start = sc->p; // Mark the start position
    for (; sc->p < sc->size; sc->p++) {
        if (sc->buf[sc->p] =='') { // Stop at space
            break;
        }
    }
    char *result = (char *)malloc((sc->p - start + 1) * sizeof(char));
    strncpy(result, sc->buf + start, sc->p - start); // Extract the token
    result[sc->p - start] = '\0';
    sc->p++; // Move past the space
    return result; // Return the token
}

// nextLine reads the next line from the input
char *nextLine(Scanner *sc) {
    sc->pre(sc); // Ensure there's data to read
    int start = sc->p; // Mark the start position
    sc->p = sc->size; // Move to the end of the buffer
    char *result = (char *)malloc((sc->p - start + 1) * sizeof(char));
    strncpy(result, sc->buf + start, sc->p - start); // Extract the line
    result[sc->p - start] = '\0';
    return result; // Return the line
}

// nextInt reads the next integer from the input
int nextInt(Scanner *sc) {
    char *s = next(sc); // Convert the next token to an integer
    int v = atoi(s);
    free(s);
    return v; // Return the integer
}

// pre checks if more data needs to be read into the buffer
void pre(Scanner *sc) {
    if (sc->p >= sc->size) { // If the current position is at or beyond the buffer length
        sc->readLine(sc); // Read a new line into the buffer
        sc->p = 0; // Reset the position to the start of the buffer
    }
}

// readLine reads a full line from the input into the buffer
void readLine(Scanner *sc) {
    free(sc->buf); // Clear the buffer
    sc->buf = (char *)malloc(1000 * sizeof(char));
    int c;
    int i = 0;
    while ((c = fgetc(sc->fp))!= EOF) {
        if (c == '\n') {
            break;
        }
        sc->buf[i++] = c;
    }
    sc->buf[i] = '\0';
    sc->size = i;
}

// freeScanner frees the memory allocated for the scanner
void freeScanner(Scanner *sc) {
    free(sc->buf);
    free(sc);
}

// END-OF-CODE