#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Declare three string variables to hold the input values
    char s1[100], s2[100], s3[100];
    
    // Read input values for s1, s2, and s3 from the standard input
    scanf("%s %s %s", s1, s2, s3);

    // Print the uppercase version of the first character of each input string
    printf("%c%c%c\n", toupper(s1[0]), toupper(s2[0]), toupper(s3[0]));

    return 0;
}

// <END-OF-CODE>
