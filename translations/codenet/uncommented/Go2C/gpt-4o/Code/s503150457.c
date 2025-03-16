#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[100], s2[100], s3[100];
    
    // Read input strings
    scanf("%s %s %s", s1, s2, s3);
    
    // Convert the first character of each string to uppercase
    char result[4]; // 3 characters + 1 for null terminator
    result[0] = toupper(s1[0]);
    result[1] = toupper(s2[0]);
    result[2] = toupper(s3[0]);
    result[3] = '\0'; // Null-terminate the string
    
    // Print the result
    printf("%s\n", result);
    
    return 0;
}

// <END-OF-CODE>
