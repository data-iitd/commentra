#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000

int main() {
    int n, ans, sumL, L;
    char s[MAX_SENTENCE_LENGTH];

    scanf("%d", &n);

    ans = 1;
    sumL = 0;

    while (fgets(s, MAX_SENTENCE_LENGTH, stdin)) {
        L = strlen(s);

        if (L > 1) {
            if (L > n) {
                printf("Impossible\n");
                return 0;
            }

            if (sumL + L + (sumL > 0) > n) {
                ans++;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

