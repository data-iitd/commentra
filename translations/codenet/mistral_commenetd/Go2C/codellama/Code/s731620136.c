#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I/O
typedef struct Scanner {
    char* buffer;
    int bufferSize;
    int bufferIndex;
    FILE* file;
} Scanner;

Scanner* newScanner() {
    Scanner* sc = malloc(sizeof(Scanner));
    sc->bufferSize = 10240;
    sc->buffer = malloc(sc->bufferSize);
    sc->bufferIndex = 0;
    sc->file = stdin;
    return sc;
}

int nextInt(Scanner* sc) {
    int result;
    fscanf(sc->file, "%d", &result);
    return result;
}

char nextChar(Scanner* sc) {
    char result;
    fscanf(sc->file, "%c", &result);
    return result;
}

char* nextLine(Scanner* sc) {
    char* result = malloc(sc->bufferSize);
    fgets(result, sc->bufferSize, sc->file);
    return result;
}

// ... (rest of the Scanner methods)

int run(FILE* input, FILE* output) {
    Scanner* sc = newScanner(); // Initialize a new Scanner

    int N = nextInt(sc); // Read the first integer from input

    // ... (empty block for N == 0 case)

    if (N < 4) { // Check if N is less than 4
        fprintf(output, "0\n"); // Print 0 if N is less than 4
        return 0; // Return 0
    }

    // ... (variable initialization block)

    int nr, nb, ng; // Declare and initialize variables for red, blue, and green balls

    char* S = nextLine(sc); // Read the string S from input

    for (int i = 0; i < N; i++) { // Iterate through each character in the string S
        if (S[i] == 'R') { // If the character is 'R'
            nr++; // Increment the nr counter
        }

        if (S[i] == 'B') { // If the character is 'B'
            nb++; // Increment the nb counter
        }

        if (S[i] == 'G') { // If the character is 'G'
            ng++; // Increment the ng counter
        }
    }

    int same = 0; // Initialize a counter for the number of same-colored groups of three balls

    // ... (outer loop block)

    for (int a = 1; a < N; a++) { // Iterate through each index a from 1 to N-1
        int i = 0; // Initialize index i to 0
        int j = a; // Initialize index j to a
        int k = 2 * a; // Initialize index k to a multiplied by 2

        // ... (inner loop block)

        while (k < N) { // Iterate through each index k from a*2 to N-1
            // ... (check condition block)

            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) { // Check if the balls at indices i, j, and k have different colors
                same++; // If so, increment the same counter
            }

            // ... (update indices block)

            i++; // Increment index i
            j++; // Increment index j
            k++; // Increment index k
        }
    }

    int tot = nr * nb * ng; // Calculate the total number of balls

    // ... (comment out or remove the following lines as they are not used in the final solution)

    // int tot = 0; // Initialize a variable for the total number of balls
    // int sum = 0; // Initialize a variable for the number of distinct triples
    // int sum2 = 0; // Initialize a variable for the number of distinct triples with the same middle index

    // ... (calculate the final result)

    fprintf(output, "%d\n", tot - same); // Print the result, which is the total number of balls minus the number of same-colored groups of three balls

    return 0; // Return 0 to indicate successful execution
}

int main() {
    run(stdin, stdout); // Run the main function with standard input and output
    return 0;
}

