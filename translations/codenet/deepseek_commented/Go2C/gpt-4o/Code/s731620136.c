#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from input
int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a string from input
void nextStr(char *str) {
    scanf("%s", str);
}

// The run function reads the input, processes it, and prints the result.
int run() {
    int N = nextInt();
<<<<<<< HEAD
    char S[1000001]; // Assuming maximum length of S is 1,000,000
=======
    char S[100000]; // Assuming a maximum length for the string
>>>>>>> 98c87cb78a (data updated)
    nextStr(S);

    if (N < 4) {
        printf("0\n");
        return 0;
    }

    // Counts the number of 'R', 'B', and 'G' characters in S.
    int nr = 0, nb = 0, ng = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            nr++;
        } else if (S[i] == 'B') {
            nb++;
        } else if (S[i] == 'G') {
            ng++;
        }
    }

    // Calculates the number of triplets where the characters are all different.
    int same = 0;
    for (int a = 1; a < N; a++) {
        for (int i = 0, j = a, k = 2 * a; k < N; i++, j++, k++) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
        }
    }

    // Calculates the total number of possible triplets.
    int tot = nr * nb * ng;

    // Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
    printf("%d\n", tot - same);

    return 0;
}

// The main function calls the run function and returns the exit status.
int main() {
    return run();
}

// <END-OF-CODE>
