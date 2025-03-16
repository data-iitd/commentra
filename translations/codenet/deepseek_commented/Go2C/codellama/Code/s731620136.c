
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I/O
// The Scanner struct is defined to read input efficiently.
typedef struct Scanner {
    char* str;
    int pos;
} Scanner;

// NewScanner initializes a new Scanner instance with appropriate buffer sizes and word-based scanning.
Scanner* NewScanner() {
    Scanner* sc = (Scanner*)malloc(sizeof(Scanner));
    sc->str = (char*)malloc(10240 * sizeof(char));
    sc->pos = 0;
    return sc;
}

// Reads the next word from the input and returns it as a string.
char* nextStr(Scanner* sc) {
    char* word = (char*)malloc(1024 * sizeof(char));
    int i = 0;
    while (sc->str[sc->pos] != ' ' && sc->str[sc->pos] != '\0') {
        word[i] = sc->str[sc->pos];
        sc->pos++;
        i++;
    }
    word[i] = '\0';
    sc->pos++;
    return word;
}

// Reads the next word, converts it to an integer, and returns it.
int nextInt(Scanner* sc) {
    char* word = nextStr(sc);
    int i = atoi(word);
    free(word);
    return i;
}

// Reads the next word, converts it to a float64, and returns it.
float nextFloat(Scanner* sc) {
    char* word = nextStr(sc);
    float f = atof(word);
    free(word);
    return f;
}

// Reads the next word and returns it as a byte slice.
char* nextRuneSlice(Scanner* sc) {
    return nextStr(sc);
}

// Reads `n` integers from the input and returns them as a slice.
int* nextIntSlice(Scanner* sc, int n) {
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(sc);
    }
    return res;
}

// Reads `n` floats from the input and returns them as a slice.
float* nextFloatSlice(Scanner* sc, int n) {
    float* res = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        res[i] = nextFloat(sc);
    }
    return res;
}

// The run function reads the input, processes it, and prints the result.
int run(FILE* input, FILE* output) {
    Scanner* sc = NewScanner();
    // Reads the number of elements N and the string S.
    int N = nextInt(sc);
    char* S = nextStr(sc);

    if (N == 0) {
    }

    if (N < 4) {
        fprintf(output, "0\n");
        return 0;
    }

    // Counts the number of 'R', 'B', and 'G' characters in S.
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

    // Calculates the number of triplets where the characters are all different.
    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) {
            break;
        }
        for (; k < N; k++) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
            i++;
            j++;
            k++;
        }
    }

    // Calculates the total number of possible triplets.
    int tot = nr * nb * ng;

    // Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
    fprintf(output, "%d\n", tot - same);

    return 0;
}

// The main function calls the run function with standard input and output, and exits with the return value of run.
int main() {
    run(stdin, stdout);
    return 0;
}

