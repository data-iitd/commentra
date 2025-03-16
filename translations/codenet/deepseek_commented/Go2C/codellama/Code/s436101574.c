#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    char ans[MAX_LEN];
    int i, j, k, l, m, n;
    int f;

    scanf("%s", s);
    scanf("%s", t);

    for (i = 0; i < strlen(s) - strlen(t) + 1; i++) {
        f = 1;
        for (j = 0; j < strlen(t); j++) {
            if (s[i+j] != t[j] && s[i+j] != '?') {
                f = 0;
                break;
            } else {
                s[i+j] = t[j];
            }
        }
        if (f) {
            strcpy(ans, s);
            for (k = 0; k < strlen(ans); k++) {
                if (ans[k] == '?') {
                    ans[k] = 'a';
                }
            }
            printf("%s\n", ans);
        }
    }

    return 0;
}

