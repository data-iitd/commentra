
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int score = 0;
    for (int i = 0; i < strlen(s); i++) {
        char my = i % 2 == 0? 'g' : 'p';
        char his = s[i];
        if (my!= his) {
            score += my == 'p'? 1 : -1;
        }
    }
    printf("%d\n", score);
    return 0;
}
// END-OF-CODE