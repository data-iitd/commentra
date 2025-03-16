#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Declare empty strings s1, s2, and s3 for user input
    char s1[100], s2[100], s3[100];

    // Read user input for strings s1, s2, and s3
    scanf("%s %s %s", s1, s2, s3);

    // Print the concatenated uppercase first character of each string
    printf("%c%c%c\n", toupper(s1[0]), toupper(s2[0]), toupper(s3[0]));

    return 0;
}

// <END-OF-CODE>
