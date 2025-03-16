#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char result[4]; // "Yes" or "No" with null terminator

    if (fgets(s, sizeof(s), stdin) != NULL) {
        if (strstr(s, "A") != NULL && strstr(s, "B") != NULL) {
            strcpy(result, "Yes");
        } else {
            strcpy(result, "No");
        }
    }

    printf("%s\n", result);
    return 0;
}
