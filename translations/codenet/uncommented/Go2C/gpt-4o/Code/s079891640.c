#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100]; // Assuming the maximum length of the string is 99 characters
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                printf("no\n");
                exit(0);
            }
        }
    }

    printf("yes\n");
    return 0;
}

// <END-OF-CODE>
