
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s); // Step 1: Reading Input - The program starts by declaring a character array `s` and using `scanf` to read input from the user.

    char *ptr = s;
    while (*ptr!= '\0') { // Step 2: Replacing Substrings - The program iterates through each character in the string `s` and replaces occurrences of "dream" with "D" and "erase" with "E".
        if (strcmp(ptr, "dream") == 0) {
            strcpy(ptr, "D");
        } else if (strcmp(ptr, "erase") == 0) {
            strcpy(ptr, "E");
        }
        ptr++;
    }

    ptr = s;
    while (*ptr!= '\0') { // Step 3: Removing Modified Substrings - The program iterates through each character in the string `s` and removes occurrences of "Der", "Er", "D", and "E".
        if (strcmp(ptr, "Der") == 0) {
            memmove(ptr, ptr + 3, strlen(ptr + 3) + 1);
        } else if (strcmp(ptr, "Er") == 0) {
            memmove(ptr, ptr + 2, strlen(ptr + 2) + 1);
        } else if (strcmp(ptr, "D") == 0) {
            memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
        } else if (strcmp(ptr, "E") == 0) {
            memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
        }
        ptr++;
    }

    ptr = s;
    while (*ptr!= '\0') { // Step 4: Trimming Spaces - The program iterates through each character in the string `s` and removes any leading or trailing whitespace.
        if (*ptr =='' || *ptr == '\n' || *ptr == '\t') {
            memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
        } else {
            ptr++;
        }
    }

    if (strlen(s) == 0) { // Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
