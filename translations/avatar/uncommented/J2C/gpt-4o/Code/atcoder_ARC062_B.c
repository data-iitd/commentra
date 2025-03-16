#include <stdio.h>
#include <string.h>

void solve(int testNumber, char *S) {
    int score = 0;
    int length = strlen(S);
    for (int i = 0; i < length; i++) {
        char my = (i % 2 == 0) ? 'g' : 'p';
        char his = S[i];
        if (my != his) {
            score += (my == 'p') ? 1 : -1;
        }
    }
    printf("%d\n", score);
}

int main() {
    char S[100001]; // Assuming the maximum length of S is 100000
    scanf("%s", S);
    solve(1, S);
    return 0;
}

// <END-OF-CODE>
