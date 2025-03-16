
#include <stdio.h>
#include <string.h>

int main() {
    // Declare three string variables to hold user input
    char s1[100], s2[100], s3[100];
    
    // Read three strings from standard input
    scanf("%s %s %s", s1, s2, s3);

    // Split each string into a slice of individual characters
    char *s1s = s1;
    char *s2s = s2;
    char *s3s = s3;

    // Convert the first character of each string to uppercase and concatenate them
    char result[100];
    sprintf(result, "%c%c%c", toupper(*s1s), toupper(*s2s), toupper(*s3s));
    
    // Print the concatenated result
    printf("%s\n", result);
    
    return 0;
}
