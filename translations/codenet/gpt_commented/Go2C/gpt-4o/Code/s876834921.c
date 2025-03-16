#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Declare a string variable to hold user input
    char s[1000]; // Assuming a maximum input length of 999 characters + 1 for null terminator
    
    // Read input from the user
    fgets(s, sizeof(s), stdin);
    
    // Replace occurrences of "dream" with "D"
    char *pos;
    while ((pos = strstr(s, "dream")) != NULL) {
        memmove(pos + 1, pos + 5, strlen(pos + 5) + 1); // Shift the rest of the string left
        *pos = 'D'; // Replace with 'D'
    }
    
    // Replace occurrences of "erase" with "E"
    while ((pos = strstr(s, "erase")) != NULL) {
        memmove(pos + 1, pos + 5, strlen(pos + 5) + 1); // Shift the rest of the string left
        *pos = 'E'; // Replace with 'E'
    }
    
    // Remove occurrences of "Der"
    while ((pos = strstr(s, "Der")) != NULL) {
        memmove(pos, pos + 3, strlen(pos + 3) + 1); // Shift the rest of the string left
    }
    
    // Remove occurrences of "Er"
    while ((pos = strstr(s, "Er")) != NULL) {
        memmove(pos, pos + 2, strlen(pos + 2) + 1); // Shift the rest of the string left
    }
    
    // Remove occurrences of "D"
    while ((pos = strchr(s, 'D')) != NULL) {
        memmove(pos, pos + 1, strlen(pos + 1) + 1); // Shift the rest of the string left
    }
    
    // Remove occurrences of "E"
    while ((pos = strchr(s, 'E')) != NULL) {
        memmove(pos, pos + 1, strlen(pos + 1) + 1); // Shift the rest of the string left
    }
    
    // Trim any leading or trailing whitespace from the string
    char *end;
    // Trim leading space
    while(isspace((unsigned char)*s)) s++;
    // Trim trailing space
    end = s + strlen(s) - 1;
    while(end > s && isspace((unsigned char)*end)) end--;
    end[1] = '\0'; // Null terminate the trimmed string

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
// <END-OF-CODE>
