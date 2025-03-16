#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} Scanner;

Scanner* newScanner() {
    Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
    sc->capacity = 1000;
    sc->buffer = (char *)malloc(sc->capacity);
    sc->size = 0;
    return sc;
}

void freeScanner(Scanner *sc) {
    free(sc->buffer);
    free(sc);
}

void readLine(Scanner *sc) {
<<<<<<< HEAD
    sc->size = fread(sc->buffer, 1, sc->capacity, stdin);
    if (sc->size > 0 && sc->buffer[sc->size - 1] == '\n') {
        sc->buffer[--sc->size] = '\0'; // Remove newline character
    } else {
        sc->buffer[sc->size] = '\0'; // Null-terminate
    }
}

int nextInt(Scanner *sc) {
    readLine(sc);
    return atoi(sc->buffer);
=======
    sc->size = 0;
    fgets(sc->buffer, sc->capacity, stdin);
    sc->size = strlen(sc->buffer);
}

int nextInt(Scanner *sc) {
    int value;
    sscanf(sc->buffer, "%d", &value);
    // Move the buffer forward to skip the read integer
    char *next_space = strchr(sc->buffer, ' ');
    if (next_space) {
        memmove(sc->buffer, next_space + 1, sc->size - (next_space - sc->buffer));
        sc->size -= (next_space - sc->buffer + 1);
    } else {
        sc->size = 0; // No more integers
    }
    return value;
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    Scanner *sc = newScanner(); // Initialize a new Scanner instance

<<<<<<< HEAD
    int n = nextInt(sc); // Read an integer n from the standard input
    double ans = 0.0; // Initialize a variable ans to 0.0
    for (int i = 0; i < n; i++) { // Enter a loop that runs n times
        int tmpInt = nextInt(sc); // Read an integer
        double tmp = 1.0 / (double)tmpInt; // Convert it to a float and divide 1 by this value
        ans += tmp; // Add this result to ans
    }
=======
    readLine(sc); // Read a line from the standard input
    int n = nextInt(sc); // Read an integer n from the input
    double ans = 0.0; // Initialize a variable ans to 0.0

    for (int i = 0; i < n; i++) { // Enter a loop that runs n times
        int tmpInt = nextInt(sc); // Read an integer
        double tmp = 1.0 / (double)tmpInt; // Divide 1 by this value
        ans += tmp; // Add this result to ans
    }

>>>>>>> 98c87cb78a (data updated)
    printf("%lf\n", 1.0 / ans); // Calculate the reciprocal of ans and print it

    freeScanner(sc); // Free the allocated memory for the scanner
    return 0;
}

// <END-OF-CODE>
