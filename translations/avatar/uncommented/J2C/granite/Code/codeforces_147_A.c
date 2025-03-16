
#include <stdio.h>
#include <stdbool.h>

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
    char s[1000];
    fgets(s, 1000, stdin);
    int n = strlen(s);
    char sb[1000];
    sb[0] = s[0];
    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                sb[0] ='';
            }
            sb[0] = c;
        } else if (isPunctuation(c)) {
            sb[0] = c;
        }
    }
    printf("%s\n", sb);
    return 0;
}
