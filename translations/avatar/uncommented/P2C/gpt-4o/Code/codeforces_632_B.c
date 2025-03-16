#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;
    char type;
} Piece;

int Bob_sMaxStrength(Piece* pieces, int n) {
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;

    // Calculate initial pScore and pMaxScore
    for (int i = 0; i < n; i++) {
        if (pieces[i].type == 'B') {
            pScore += pieces[i].score;
        }
    }
    pMaxScore = pScore;

    // Calculate pMaxScore
    for (int i = 0; i < n; i++) {
        if (pieces[i].type == 'A') {
            pScore += pieces[i].score;
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= pieces[i].score;
        }
    }

    // Calculate sMaxScore
    for (int i = n - 1; i >= 0; i--) {
        if (pieces[i].type == 'A') {
            sScore += pieces[i].score;
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= pieces[i].score;
        }
    }

    return (pMaxScore > sMaxScore) ? pMaxScore : sMaxScore;
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of pieces
    Piece* pieces = (Piece*)malloc(n * sizeof(Piece));

    for (int i = 0; i < n; i++) {
        scanf("%d %c", &pieces[i].score, &pieces[i].type);
    }

    int result = Bob_sMaxStrength(pieces, n);
    printf("%d\n", result);

    free(pieces);
    return 0;
}

// <END-OF-CODE>
