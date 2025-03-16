#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to trim leading and trailing spaces
char* trim(char* str) {
    char* end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';

    return str;
}

int main() {
    // Initialize an empty string variable 's'
    char s[1000]; // Assuming a maximum length of 999 characters + 1 for null terminator

    // Read a string input from the user
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Remove the newline character

    // Replace all occurrences of "dream" with "D"
    char* pos;
    while ((pos = strstr(s, "dream")) != NULL) {
        memmove(pos + 1, pos + 5, strlen(pos + 5) + 1); // Shift the rest of the string
        *pos = 'D'; // Replace with 'D'
    }

    // Replace all occurrences of "erase" with "E"
    while ((pos = strstr(s, "erase")) != NULL) {
        memmove(pos + 1, pos + 5, strlen(pos + 5) + 1); // Shift the rest of the string
        *pos = 'E'; // Replace with 'E'
    }

    // Remove "Der"
    while ((pos = strstr(s, "Der")) != NULL) {
        memmove(pos, pos + 3, strlen(pos + 3) + 1); // Shift the rest of the string
    }

    // Remove "Er"
    while ((pos = strstr(s, "Er")) != NULL) {
        memmove(pos, pos + 2, strlen(pos + 2) + 1); // Shift the rest of the string
    }

    // Trim leading and trailing spaces
    char* trimmed = trim(s);

    // Check if the string 's' is empty or not
    if (strlen(trimmed) == 0) {
        // Print "YES" if the string 's' is empty
        printf("YES\n");
    } else {
        // Print "NO" if the string 's' is not empty
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
