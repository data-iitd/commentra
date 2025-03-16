#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline character if present

    for (char i = 'a'; i <= 'z'; i++) {
        int a = 0;
        for (int j = 0; j < strlen(s); j++) {
            if (i == s[j]) {
                a++;
            }
        }
        if (a == 0) {
            printf("%c\n", i);
            break;
        }
        if (i == 'z') {
            printf("None\n");
            break;
        }
    }
    return 0;
}
