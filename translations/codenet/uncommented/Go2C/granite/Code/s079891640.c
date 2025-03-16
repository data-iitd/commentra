
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        if (strstr(s + i + 1, &s[i])) {
            printf("no\n");
            return 0;
        }
    }

    printf("yes\n");
}
