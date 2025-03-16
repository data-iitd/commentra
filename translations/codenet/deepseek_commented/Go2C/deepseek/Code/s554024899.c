#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Custom scanner struct to read input
typedef struct {
    FILE *file;
    char buffer[1000];
    int position;
} Scanner;

// Function to create a new scanner
Scanner* newScanner() {
    Scanner *sc = (Scanner*)malloc(sizeof(Scanner));
    sc->file = stdin;
    sc->position = 0;
    return sc;
}

// Function to read the next word
char* next(Scanner *sc) {
    while (sc->position < strlen(sc->buffer) && sc->buffer[sc->position] == ' ') {
        sc->position++;
    }
    int start = sc->position;
    while (sc->position < strlen(sc->buffer) && sc->buffer[sc->position] != ' ') {
        sc->position++;
    }
    char *result = (char*)malloc(sc->position - start + 1);
    strncpy(result, sc->buffer + start, sc->position - start);
    result[sc->position - start] = '\0';
    return result;
}

// Function to read the next line
char* nextLine(Scanner *sc) {
    while (sc->position < strlen(sc->buffer) && sc->buffer[sc->position] == ' ') {
        sc->position++;
    }
    int start = sc->position;
    while (sc->position < strlen(sc->buffer) && sc->buffer[sc->position] != '\n') {
        sc->position++;
    }
    char *result = (char*)malloc(sc->position - start + 1);
    strncpy(result, sc->buffer + start, sc->position - start);
    result[sc->position - start] = '\0';
    return result;
}

// Function to read the next integer
int nextInt(Scanner *sc) {
    char *str = next(sc);
    int result = atoi(str);
    free(str);
    return result;
}

// Function to preprocess the buffer
void pre(Scanner *sc) {
    if (sc->position >= strlen(sc->buffer)) {
        fgets(sc->buffer, sizeof(sc->buffer), sc->file);
        sc->position = 0;
    }
}

int main() {
    // Initialize scanner to read input
    Scanner *sc = newScanner();
    
    // Read two integers from the input
    int x = nextInt(sc);
    int y = nextInt(sc);
    
    // Define an array containing three slices, each representing a group of months with the same number of days
    int xt = 0, yt = 0;
    int a[3][3] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
    
    // Iterate over the array to determine which group each of the integers belongs to
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (x == a[i][j]) {
                xt = i;
            }
            if (y == a[i][j]) {
                yt = i;
            }
        }
    }
    
    // Compare the groups of x and y to determine if they belong to the same group
    if (xt == yt) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    // Free allocated memory
    free(sc);
    return 0;
}
