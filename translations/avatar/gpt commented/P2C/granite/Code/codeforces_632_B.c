
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;
    char player;
} Piece;

int main() {
    // Read input (the first input is ignored)
    int n;
    scanf("%d", &n);

    // Read the second line of input, split it into integers and corresponding characters,
    // and create a tuple of pieces where each piece is a tuple of (score, character)
    Piece *pieces = (Piece *)malloc(n * sizeof(Piece));
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &pieces[i].score, &pieces[i].player);
    }

    // Call the function to calculate Bob's maximum strength and return the result
    int result = Bob_sMaxStrength(pieces, n);

    // Free the memory allocated for the pieces array
    free(pieces);

    // Return the result
    return result;
}

int Bob_sMaxStrength(Piece *pieces, int n) {
    // Initialize scores for player A and player B, and their maximum scores
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for (int i = 0; i < n; i++) {
        if (pieces[i].player == 'B') {
            sScore += pieces[i].score;
        }
    }

    // Calculate maximum score for player A by iterating through pieces from the start
    for (int i = 0; i < n; i++) {
        if (pieces[i].player == 'A') {
            pScore += pieces[i].score;
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= pieces[i].score;
        }
    }

    // Calculate maximum score for player B by iterating through pieces from the end
    for (int i = n - 1; i >= 0; i--) {
        if (pieces[i].player == 'A') {
            sScore += pieces[i].score;
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= pieces[i].score;
        }
    }

    // Return the maximum score between player A and player B
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}

