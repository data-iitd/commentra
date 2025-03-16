
#include <stdio.h>
#include <string.h>

// Initialize an empty string variable 's'
char s[100];

// Read a string input from the user using 'scanf' function
scanf("%s", s);

// Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively using 'strstr' function
char *p = strstr(s, "dream");
while (p != NULL) {
    strcpy(p, "D");
    p = strstr(p + 1, "dream");
}
p = strstr(s, "erase");
while (p != NULL) {
    strcpy(p, "E");
    p = strstr(p + 1, "erase");
}

// Remove the substrings "Der" and "Er" from the string 's' using 'strstr' function
p = strstr(s, "Der");
while (p != NULL) {
    strcpy(p, "");
    p = strstr(p + 1, "Der");
}
p = strstr(s, "Er");
while (p != NULL) {
    strcpy(p, "");
    p = strstr(p + 1, "Er");
}

// Remove leading and trailing spaces from the string 's' using 'strtrim' function
s = strtrim(s);

// Check if the string 's' is empty or not
if (strcmp(s, "") == 0) {
    // Print "YES" if the string 's' is empty
    printf("YES\n");
} else {
    // Print "NO" if the string 's' is not empty
    printf("NO\n");
}

// End of the code