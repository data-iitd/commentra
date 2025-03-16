#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        for (int j = i + 1; j < strlen(s); j++) {
            if (s[i] == s[j]) {
                printf("no\n");
                return 0;
            }
        }
    }

    printf("yes\n");
    return 0;
}

