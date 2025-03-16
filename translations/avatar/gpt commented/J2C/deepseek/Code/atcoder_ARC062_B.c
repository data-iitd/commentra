#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[100001];
    int score = 0;
    scanf("%s", S);
    int len = strlen(S);
    for (int i = 0; i < len; i++) {
        char my = (i % 2 == 0) ? 'g' : 'p';
        char his = S[i];
        if (my != his) {
            score += (my == 'p') ? 1 : -1;
        }
    }
    printf("%d\n", score);
    return 0;
}

