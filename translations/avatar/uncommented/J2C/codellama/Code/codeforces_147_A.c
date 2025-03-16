
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isPunctuation(char c) {
    if (c == '.') return true;
    if (c == ',') return true;
    if (c == '!') return true;
    if (c == '?') return true;
    return false;
}

int main() {
    char s[100];
    scanf("%s", s);
    int n = strlen(s);
    char sb[100];
    sb[0] = s[0];
    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                sb[i] = ' ';
            }
            sb[i] = c;
        } else if (isPunctuation(c)) {
            sb[i] = c;
        }
    }
    printf("%s\n", sb);
    return 0;
}

