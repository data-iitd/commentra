#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000];
    char res[1000];
    char punctuation[] = {',', '.', '!', '?'};
    int i, j = 0;

    fgets(s, sizeof(s), stdin);

    for (i = 0; i < strlen(s); i++) {
        if (i > 0) {
            if (s[i] == ' ') {
                if (res[j - 1] != ' ') {
                    res[j++] = s[i];
                }
            } else {
                if (strchr(punctuation, s[i]) != NULL) {
                    if (res[j - 1] == ' ') {
                        j--;
                    }
                    res[j++] = s[i];
                    res[j++] = ' ';
                } else {
                    res[j++] = s[i];
                }
            }
        } else {
            if (s[i] == ' ') {
                continue;
            }
            if (strchr(punctuation, s[i]) != NULL) {
                continue;
            } else {
                res[j++] = s[i];
            }
        }
    }

    if (j > 0 && res[j - 1] == ' ') {
        j--;
    }

    res[j] = '\0';
    printf("%s\n", res);

    return 0;
}
