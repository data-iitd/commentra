#include <stdio.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    fgets(s, sizeof(s), stdin); // Read a line of input

    for (int i = 0; s[i] != '\0'; i++) {
        char rr = s[i];
        if ('A' <= s[i] && s[i] <= 'Z') {
            rr = s[i] + ('a' - 'A'); // Convert to lowercase
        } else if ('a' <= s[i] && s[i] <= 'z') {
            rr = s[i] - ('a' - 'A'); // Convert to uppercase
        }
        printf("%c", rr);
    }
    printf("\n");
    return 0;
}

// <END-OF-CODE>
