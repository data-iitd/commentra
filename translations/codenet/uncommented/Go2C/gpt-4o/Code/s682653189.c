#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        printf("x");
    }
    printf("\n");
    return 0;
}

// <END-OF-CODE>
