#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

int main() {
    // Read input (the first input is ignored)
    char input[MAX_INPUT_LENGTH];
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Read the second line of input, split it into integers and corresponding characters,
    // and create a tuple of pieces where each piece is a tuple of (score, character)
    int pieces[MAX_INPUT_LENGTH][2];
    int pieceCount = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        pieces[pieceCount][0] = atoi(token);
        token = strtok(NULL, " ");
        pieces[pieceCount][1] = *token;
        token = strtok(NULL, " ");
        pieceCount++;
    }

    // Call the function to calculate Bob's maximum strength and return the result
    int result = Bob_sMaxStrength(pieces, pieceCount);
    printf("%d\n", result);

    return 0;
}

int Bob_sMaxStrength(int pieces[][2], int pieceCount) {
    // Initialize scores for player A and player B, and their maximum scores
    int pScore = sScore = pMaxScore = sMaxScore = 0;
    for (int i = 0; i < pieceCount; i++) {
        if (pieces[i][1] == 'B') {
            pMaxScore += pieces[i][0];
        }
    }

    // Calculate maximum score for player A by iterating through pieces from the start
    for (int i = 0; i < pieceCount; i++) {
        if (pieces[i][1] == 'A') {
            pScore += pieces[i][0];
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= pieces[i][0];
        }
    }

    // Calculate maximum score for player B by iterating through pieces from the end
    for (int i = pieceCount - 1; i >= 0; i--) {
        if (pieces[i][1] == 'A') {
            sScore += pieces[i][0];
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= pieces[i][0];
        }
    }

    // Return the maximum score between player A and player B
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}

