
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[100], s2[100], s3[100];
    char s1s[100], s2s[100], s3s[100];
    int i, j, k;

    // Read user input for strings s1, s2, and s3
    scanf("%s %s %s", s1, s2, s3);

    // Store individual characters of strings s1, s2, and s3 in slices s1s, s2s, and s3s respectively
    for (i = 0; i < strlen(s1); i++) {
        s1s[i] = s1[i];
    }
    for (j = 0; j < strlen(s2); j++) {
        s2s[j] = s2[j];
    }
    for (k = 0; k < strlen(s3); k++) {
        s3s[k] = s3[k];
    }

    // Print the concatenated uppercase first character of each string
    printf("%c%c%c\n", toupper(s1s[0]), toupper(s2s[0]), toupper(s3s[0]));

    return 0;
}

