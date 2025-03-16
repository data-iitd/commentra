

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100];
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        if (strchr(s + i + 1, s[i])) {
            printf("no\n");
            exit(0);
        }
    }

    printf("yes\n");

    return 0;
}
