

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    char type;
} Piece;

int main() {
    // Take input from the user
    int n;
    scanf("%d", &n);
    // Process the input to get an array of Piece structs
    Piece* pieces = (Piece*)malloc(n * sizeof(Piece));
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &pieces[i].value, &pieces[i].type);
    }
    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    int result = Bob_sMaxStrength(pieces, n);
    // Free the memory allocated for the pieces array
    free(pieces);
    // Return the result
    return result;
}

int Bob_sMaxStrength(Piece* pieces, int n) {
    // Initialize scores for both ends and their maximum scores
    int pScore = sScore = pMaxScore = sMaxScore = 0;
    for (int i = 0; i < n; i++) {
        if (pieces[i].type == 'B') {
            pScore += pieces[i].value;
            sScore += pieces[i].value;
        }
    }
    
    // Calculate the score from the front (left to right)
    for (int i = 0; i < n; i++) {
        if (pieces[i].type == 'A') {
            pScore += pieces[i].value;
        } else {
            pScore -= pieces[i].value;
        }
        if (pScore > pMaxScore) {
            pMaxScore = pScore;
        }
    }
    
    // Calculate the score from the back (right to left)
    for (int i = n - 1; i >= 0; i--) {
        if (pieces[i].type == 'A') {
            sScore += pieces[i].value;
        } else {
            sScore -= pieces[i].value;
        }
        if (sScore > sMaxScore) {
            sMaxScore = sScore;
        }
    }
    
    // Return the maximum score between the two ends
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}

