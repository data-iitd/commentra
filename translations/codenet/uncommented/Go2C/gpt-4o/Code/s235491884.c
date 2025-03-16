#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);

    int n = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'o') {
            n++;
        }
    }

    printf("%d\n", 700 + n * 100);
    return 0;
}

// <END-OF-CODE>
