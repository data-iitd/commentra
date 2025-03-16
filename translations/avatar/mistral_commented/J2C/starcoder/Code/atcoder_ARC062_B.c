
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[100000];
    int score = 0;
    scanf("%s", S);
    for (int i = 0; i < strlen(S); i++) {
        char my;
        char his;
        my = i % 2 == 0? 'g' : 'p';
        his = S[i];
        if (my!= his) {
            score += my == 'p'? 1 : -1;
        }
    }
    printf("%d\n", score);
    return 0;
}

