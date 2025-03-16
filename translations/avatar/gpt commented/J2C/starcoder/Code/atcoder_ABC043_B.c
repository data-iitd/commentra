#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000000];
    scanf("%s", s);
    int i, j;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == '0') {
            printf("0");
        } else if (s[i] == '1') {
            printf("1");
        } else if (s[i] == 'B') {
            if (i > 0) {
                for (j = i - 1; j < strlen(s) - 1; j++) {
                    s[j] = s[j + 1];
                }
                s[j] = '\0';
            }
        }
    }
    printf("\n");
    return 0;
}

