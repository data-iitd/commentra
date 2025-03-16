
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Scanner struct for handling input
typedef struct {
    char *buf;
    size_t size;
    size_t cap;
} Scanner;

// NewScanner initializes a new Scanner for reading input
Scanner *NewScanner() {
    Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
    sc->buf = (char *)malloc(10240 * sizeof(char));
    sc->size = 0;
    sc->cap = 10240;
    return sc;
}

// nextStr reads the next string from input
char *nextStr(Scanner *sc) {
    char *res = (char *)malloc(sc->cap * sizeof(char));
    int i = 0;
    while (sc->buf[sc->size]!='' && sc->size < sc->cap) {
        res[i] = sc->buf[sc->size];
        i++;
        sc->size++;
    }
    res[i] = '\0';
    return res;
}

// nextInt reads the next integer from input
int nextInt(Scanner *sc) {
    int res = 0;
    while (sc->buf[sc->size]!='' && sc->size < sc->cap) {
        res = res * 10 + (sc->buf[sc->size] - '0');
        sc->size++;
    }
    sc->size++;
    return res;
}

// nextFloat reads the next float from input
float nextFloat(Scanner *sc) {
    float res = 0;
    int i = 0;
    while (sc->buf[sc->size]!='' && sc->size < sc->cap) {
        res = res * 10 + (sc->buf[sc->size] - '0');
        i++;
        sc->size++;
    }
    sc->size++;
    return (float)res / (float)pow(10, i);
}

// nextRuneSlice reads the next string and converts it to a byte slice
char *nextRuneSlice(Scanner *sc) {
    char *res = (char *)malloc(sc->cap * sizeof(char));
    int i = 0;
    while (sc->size < sc->cap) {
        res[i] = sc->buf[sc->size];
        i++;
        sc->size++;
    }
    res[i] = '\0';
    return res;
}

// nextIntSlice reads a slice of integers from input
int *nextIntSlice(Scanner *sc, int n) {
    int *res = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(sc);
    }
    return res;
}

// nextFloatSlice reads a slice of floats from input
float *nextFloatSlice(Scanner *sc, int n) {
    float *res = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        res[i] = nextFloat(sc);
    }
    return res;
}

// run processes the input and produces output
int run(FILE *input, FILE *output) {
    Scanner *sc = NewScanner(); // Create a new scanner instance
    int N = nextInt(sc); // Read the number of elements
    char *S = nextStr(sc); // Read the string of colors

    // Handle case where there are no elements
    if (N == 0) {
        return 0;
    }

    // If there are fewer than 4 elements, output 0
    if (N < 4) {
        fprintf(output, "%d\n", 0);
        return 0;
    }

    // Count occurrences of each color
    int nr = 0, nb = 0, ng = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            nr++;
        }
        if (S[i] == 'B') {
            nb++;
        }
        if (S[i] == 'G') {
            ng++;
        }
    }

    int same = 0; // Counter for same color combinations

    // Iterate through possible combinations of indices
    for (int a = 1; a < N; a++) {
        int i = 0, j = a, k = 2 * a;
        if (k >= N) {
            break; // Exit if index exceeds string length
        }
        for (k = 2 * a; k < N; k++) {
            // Check if the colors at the indices are different
            if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
                same++; // Increment same color combination counter
            }
            i++; // Move to the next index
            j++;
            k++;
        }
    }

    // Calculate total combinations of different colors
    int tot = nr * nb * ng;

    // Output the result by subtracting same combinations from total
    fprintf(output, "%d\n", tot - same);

    return 0; // Return success
}

// main function to execute the program
int main() {
    FILE *input = fopen("input.txt", "r"); // Open input file
    FILE *output = fopen("output.txt", "w"); // Open output file
    int result = run(input, output); // Run the program
    fclose(input); // Close input file
    fclose(output); // Close output file
    return result; // Return the result
}

