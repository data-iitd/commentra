#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable to hold user input
    char s[100];
    
    // Read input from the user
    scanf("%s", s);
    
    // Replace occurrences of "dream" with "D"
    char *p = strstr(s, "dream");
    while (p != NULL) {
        *p = 'D';
        p = strstr(p + 1, "dream");
    }
    
    // Replace occurrences of "erase" with "E"
    p = strstr(s, "erase");
    while (p != NULL) {
        *p = 'E';
        p = strstr(p + 1, "erase");
    }
    
    // Remove occurrences of "Der" from the string
    p = strstr(s, "Der");
    while (p != NULL) {
        memmove(p, p + 2, strlen(p + 2) + 1);
        p = strstr(p, "Der");
    }
    
    // Remove occurrences of "Er" from the string
    p = strstr(s, "Er");
    while (p != NULL) {
        memmove(p, p + 1, strlen(p + 1) + 1);
        p = strstr(p, "Er");
    }
    
    // Remove occurrences of "D" from the string
    p = strstr(s, "D");
    while (p != NULL) {
        memmove(p, p + 1, strlen(p + 1) + 1);
        p = strstr(p, "D");
    }
    
    // Remove occurrences of "E" from the string
    p = strstr(s, "E");
    while (p != NULL) {
        memmove(p, p + 1, strlen(p + 1) + 1);
        p = strstr(p, "E");
    }
    
    // Trim any leading or trailing whitespace from the string
    p = s;
    while (*p == ' ') {
        p++;
    }
    memmove(s, p, strlen(p) + 1);
    p = s + strlen(s) - 1;
    while (*p == ' ') {
        *p = '\0';
        p--;
    }
    
    // Check if the resulting string is empty
    if (strlen(s) == 0) {
        // If the string is empty, print "YES"
        printf("YES\n");
    } else {
        // If the string is not empty, print "NO"
        printf("NO\n");
    }
    
    return 0;
}

