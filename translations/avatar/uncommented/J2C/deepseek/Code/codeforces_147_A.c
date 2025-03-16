#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isLatinLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    int n = strlen(s);
    if (s[n - 1] == '\n') {
        s[n - 1] = '\0';
        n--;
    }
    char sb[2000] = {0};
    int sb_index = 0;
    sb[sb_index++] = s[0];
    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                sb[sb_index++] = ' ';
            }
            sb[sb_index++] = c;
        } else if (isPunctuation(c)) {
            sb[sb_index++] = c;
        }
    }
    sb[sb_index] = '\0';
    printf("%s\n", sb);
    return 0;
}

