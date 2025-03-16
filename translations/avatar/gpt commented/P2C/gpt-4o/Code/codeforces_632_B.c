#include <stdio.h>

typedef struct {
    int score;
    char character;
} Piece;

int Bob_sMaxStrength(Piece pieces[], int n) {
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;

    // Calculate initial score for player B
    for (int i = 0; i < n; i++) {
        if (pieces[i].character == 'B') {
            pScore += pieces[i].score;
        }
    }
    pMaxScore = pScore;

    // Calculate maximum score for player A
    for (int i = 0; i < n; i++) {
        if (pieces[i].character == 'A') {
            pScore += pieces[i].score;
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= pieces[i].score;
        }
    }

    // Calculate maximum score for player B
    for (int i = n - 1; i >= 0; i--) {
        if (pieces[i].character == 'A') {
            sScore += pieces[i].score;
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= pieces[i].score;
        }
    }

    // Return the maximum score between player A and player B
    return (pMaxScore > sMaxScore) ? pMaxScore : sMaxScore;
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of pieces (first input is ignored)

    Piece pieces[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &pieces[i].score, &pieces[i].character);
    }

    // Call the function to calculate Bob's maximum strength and print the result
    printf("%d\n", Bob_sMaxStrength(pieces, n));

    return 0;
}

// <END-OF-CODE>
