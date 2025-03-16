#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char s[MAX_LEN];
    scanf("%s", s);

    char c = 'a';

    for (int j = 0; j < 26; j++) {
        int found = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%c\n", c);
            return 0;
        }
        c++;
    }

    printf("None\n");
    return 0;
}

// <END-OF-CODE>
