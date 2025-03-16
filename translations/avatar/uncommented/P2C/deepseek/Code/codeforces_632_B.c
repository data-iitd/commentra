#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *strengths = (int *)malloc(n * sizeof(int));
    char *types = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &strengths[i], &types[i]);
    }
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for (int i = 0; i < n; i++) {
        if (types[i] == 'B') {
            pScore += strengths[i];
            sScore += strengths[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (types[i] == 'A') {
            pScore += strengths[i];
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
            if (pScore < 0) {
                pScore = 0;
            }
        } else {
            pScore -= strengths[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (types[i] == 'A') {
            sScore += strengths[i];
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
            if (sScore < 0) {
                sScore = 0;
            }
        } else {
            sScore -= strengths[i];
        }
    }
    if (pMaxScore > sMaxScore) {
        printf("%d\n", pMaxScore);
    } else {
        printf("%d\n", sMaxScore);
    }
    free(strengths);
    free(types);
    return 0;
}
