#include <stdio.h>
#include <stdlib.h>

int Bob_sMaxStrength(int* values, char* types, int n) {
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;

    // Calculate the score from the front (left to right)
    for (int i = 0; i < n; i++) {
        if (types[i] == 'B') {
            pScore += values[i];
        } else {
            pScore -= values[i];
        }
        if (pScore > pMaxScore) {
            pMaxScore = pScore;
        }
    }

    // Calculate the score from the back (right to left)
    for (int i = n - 1; i >= 0; i--) {
        if (types[i] == 'B') {
            sScore += values[i];
        } else {
            sScore -= values[i];
        }
        if (sScore > sMaxScore) {
            sMaxScore = sScore;
        }
    }

    // Return the maximum score between the two ends
    return pMaxScore > sMaxScore ? pMaxScore : sMaxScore;
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of pieces
    int* values = (int*)malloc(n * sizeof(int));
    char* types = (char*)malloc(n * sizeof(char));

    // Read the values and types of the pieces
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    scanf("%s", types); // Read the types as a string

    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    int result = Bob_sMaxStrength(values, types, n);
    printf("%d\n", result);

    // Free allocated memory
    free(values);
    free(types);

    return 0;
}
