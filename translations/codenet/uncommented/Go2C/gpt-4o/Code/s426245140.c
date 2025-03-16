#include <stdio.h>
#include <string.h>

int main() {
    char s[5]; // Declare a string with enough space for 4 characters and a null terminator
    scanf("%4s", s); // Read a string of up to 4 characters

    // Check the conditions for the characters
    if ((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3])) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
// <END-OF-CODE>
