
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    char res[1000];
    int j = 0;

    char punctuation[] = ",.!?";
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] =='') {
            if (res[j - 1]!= '\0') {
                res[j++] ='';
            }
        } else if (strchr(punctuation, s[i])) {
            if (res[j - 1] == '\0') {
                j -= 2;
            }
            res[j++] = s[i];
            res[j++] = '\0';
        } else {
            res[j++] = s[i];
        }
    }

    printf("%s\n", res);

    return 0;
}
