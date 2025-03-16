#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(char* s, char* d) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '0':
                d[j++] = '0';
                break;
            case '1':
                d[j++] = '1';
                break;
            case 'B':
                if (j > 0) {
                    j--;
                }
                break;
        }
    }
    d[j] = '\0';
}

int main() {
    char s[100001];
    char d[100001];

    if (fgets(s, sizeof(s), stdin) != NULL) {
        solve(s, d);
        printf("%s\n", d);
    }

    return 0;
}

