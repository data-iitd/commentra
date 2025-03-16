#include <stdio.h>

int main() {
    const char *LUCKY = "abcd";
    int n;
    scanf("%d", &n);
    char s[n + 1]; // +1 for the null terminator
    s[n] = '\0'; // Null-terminate the string

    for (int i = 0; i < n; i++) {
        s[i] = LUCKY[i % 4];
    }

    printf("%s\n", s);
    return 0;
}

// <END-OF-CODE>
