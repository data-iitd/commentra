
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    char color[2];
} Piece;

int main() {
    int n;
    scanf("%d", &n);
    Piece *pieces = (Piece *)malloc(n * sizeof(Piece));
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &pieces[i].value, pieces[i].color);
    }
    int pScore = sScore = pMaxScore = sMaxScore = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(pieces[i].color, "B") == 0) {
            pScore += pieces[i].value;
        } else {
            sScore += pieces[i].value;
        }
    }
    int pTempScore = pScore;
    for (int i = n - 1; i >= 0; i--) {
        if (strcmp(pieces[i].color, "A") == 0) {
            pTempScore += pieces[i].value;
            if (pTempScore > pMaxScore) {
                pMaxScore = pTempScore;
            }
        } else {
            pTempScore -= pieces[i].value;
        }
    }
    int sTempScore = sScore;
    for (int i = n - 1; i >= 0; i--) {
        if (strcmp(pieces[i].color, "A") == 0) {
            sTempScore += pieces[i].value;
            if (sTempScore > sMaxScore) {
                sMaxScore = sTempScore;
            }
        } else {
            sTempScore -= pieces[i].value;
        }
    }
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    } else {
        return sMaxScore;
    }
}

