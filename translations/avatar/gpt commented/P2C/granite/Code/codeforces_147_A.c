
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    char res[100] = "";
    char punctuation[] = {',', '.', '!', '?'};
    int i;
    for (i = 0; s[i]!= '\0'; i++) {
        if (i >= 1) {
            if (s[i] =='') {
                if (res[strlen(res) - 1]!='') {
                    strcat(res, " ");
                }
            } else {
                if (strchr(punctuation, s[i])) {
                    if (res[strlen(res) - 1] =='') {
                        res[strlen(res) - 1] = '\0';
                    }
                    strcat(res, s[i]);
                    strcat(res, " ");
                } else {
                    strcat(res, s[i]);
                }
            }
        } else {
            if (s[i] =='') {
                continue;
            }
            if (strchr(punctuation, s[i])) {
                continue;
            }
            strcat(res, s[i]);
        }
    }
    printf("%s\n", res);

    return 0;
}
