#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    char type;
} Piece;

int Bob_sMaxStrength(Piece* pieces, int size) {
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;

    // Calculate initial score for 'B' pieces
    for (int i = 0; i < size; i++) {
        if (pieces[i].type == 'B') {
            pScore += pieces[i].value;
        }
    }
    pMaxScore = pScore;

    // Calculate the score from the front (left to right)
    for (int i = 0; i < size; i++) {
        if (pieces[i].type == 'A') {
            pScore += pieces[i].value;
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= pieces[i].value;
        }
    }

    // Calculate the score from the back (right to left)
    for (int i = size - 1; i >= 0; i--) {
        if (pieces[i].type == 'A') {
            sScore += pieces[i].value;
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= pieces[i].value;
        }
    }

    // Return the maximum score between the two ends
    return (pMaxScore > sMaxScore) ? pMaxScore : sMaxScore;
}

int main() {
    int n;
    // Take input for the number of pieces
    scanf("%d", &n);
    
    Piece* pieces = (Piece*)malloc(n * sizeof(Piece));
    
    // Process the input to get a tuple of (value, type) pairs for each piece
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &pieces[i].value, &pieces[i].type);
    }

    // Call the Bob_sMaxStrength function with the processed pieces and print its result
    printf("%d\n", Bob_sMaxStrength(pieces, n));

    // Free allocated memory
    free(pieces);
    
    return 0;
}

// <END-OF-CODE>
