#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(char* s) {
    char d[100001];
    int len = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '0') {
            d[len++] = '0';
        } else if (s[i] == '1') {
            d[len++] = '1';
        } else if (s[i] == 'B' && len > 0) {
            len--;
        }
    }
    d[len] = '\0';
    printf("%s\n", d);
}

int main() {
    char s[100001];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline character
    solve(s);
    return 0;
}

