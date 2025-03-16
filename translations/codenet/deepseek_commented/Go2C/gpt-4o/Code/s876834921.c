#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

<<<<<<< HEAD
void replace(char *str, const char *old, const char *new) {
=======
void replaceSubstring(char *str, const char *old, const char *new) {
>>>>>>> 98c87cb78a (data updated)
    char *pos, temp[1000];
    int index = 0;
    int oldLen = strlen(old);
    int newLen = strlen(new);

    while ((pos = strstr(str, old)) != NULL) {
        // Copy characters from the original string to the temp string
        strncpy(temp, str, pos - str);
        temp[pos - str] = '\0';
<<<<<<< HEAD
        // Append the new string
        strcat(temp, new);
        // Append the remaining part of the original string
        strcat(temp, pos + oldLen);
        // Copy back to the original string
=======
        // Append the new substring
        strcat(temp, new);
        // Append the remaining part of the original string
        strcat(temp, pos + oldLen);
        // Copy the temp string back to the original string
>>>>>>> 98c87cb78a (data updated)
        strcpy(str, temp);
    }
}

<<<<<<< HEAD
void trim(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
=======
void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
>>>>>>> 98c87cb78a (data updated)

    // Null terminate after the last non-space character
    *(end + 1) = '\0';
}

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin); // Step 1: Reading Input

<<<<<<< HEAD
    // Step 2: Replacing Substrings
    replace(s, "dream", "D");
    replace(s, "erase", "E");

    // Step 3: Removing Modified Substrings
    replace(s, "Der", "");
    replace(s, "Er", "");
    replace(s, "D", "");
    replace(s, "E", "");

    // Step 4: Trimming Spaces
    trim(s);
=======
    replaceSubstring(s, "dream", "D"); // Step 2: Replacing Substrings
    replaceSubstring(s, "erase", "E");

    replaceSubstring(s, "Der", ""); // Step 3: Removing Modified Substrings
    replaceSubstring(s, "Er", "");
    replaceSubstring(s, "D", "");
    replaceSubstring(s, "E", "");

    trimWhitespace(s); // Step 4: Trimming Spaces
>>>>>>> 98c87cb78a (data updated)

    // Step 5: Checking for Emptiness
    if (strlen(s) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
