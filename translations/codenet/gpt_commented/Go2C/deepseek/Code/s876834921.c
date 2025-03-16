#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Declare a character array to hold user input
    char s[100];
    
    // Read input from the user
    scanf("%s", s);
    
    // Replace occurrences of "dream" with "D"
    char *pos = strstr(s, "dream");
    while (pos != NULL) {
        for (int i = 0; i < strlen(pos); i++) {
            pos[i] = 'D';
        }
        pos = strstr(pos + 1, "dream");
    }
    
    // Replace occurrences of "erase" with "E"
    pos = strstr(s, "erase");
    while (pos != NULL) {
        for (int i = 0; i < strlen(pos); i++) {
            pos[i] = 'E';
        }
        pos = strstr(pos + 1, "erase");
    }
    
    // Remove occurrences of "Der" from the string
    pos = strstr(s, "Der");
    while (pos != NULL) {
        memmove(pos, pos + 3, strlen(pos + 3) + 1);
        pos = strstr(s, "Der");
    }
    
    // Remove occurrences of "Er" from the string
    pos = strstr(s, "Er");
    while (pos != NULL) {
        memmove(pos, pos + 2, strlen(pos + 2) + 1);
        pos = strstr(s, "Er");
    }
    
    // Remove occurrences of "D" from the string
    pos = strstr(s, "D");
    while (pos != NULL) {
        memmove(pos, pos + 1, strlen(pos + 1) + 1);
        pos = strstr(s, "D");
    }
    
    // Remove occurrences of "E" from the string
    pos = strstr(s, "E");
    while (pos != NULL) {
        memmove(pos, pos + 1, strlen(pos + 1) + 1);
        pos = strstr(s, "E");
    }
    
    // Trim any leading or trailing whitespace from the string
    // Assuming whitespace is only spaces for simplicity
    while (isspace((unsigned char)*s)) {
        memmove(s, s + 1, strlen(s) + 1);
    }
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (isspace((unsigned char)s[i])) {
            s[i] = '\0';
        } else {
            break;
        }
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
