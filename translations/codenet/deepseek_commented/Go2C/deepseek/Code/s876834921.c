#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000];
    scanf("%s", s); // Step 1: Reading Input - The program starts by declaring a character array `s` and using `scanf` to read input from the user.

    // Step 2: Replacing Substrings - The program replaces occurrences of "dream" with "D" and "erase" with "E".
    char *ptr = s;
    while ((ptr = strstr(ptr, "dream")) != NULL) {
        strncpy(ptr, "D", 1);
        ptr++;
    }
    while ((ptr = strstr(ptr, "erase")) != NULL) {
        strncpy(ptr, "E", 1);
        ptr++;
    }

    // Step 3: Removing Modified Substrings - The program further replaces occurrences of "Der", "Er", "D", and "E" with an empty string.
    ptr = s;
    while ((ptr = strstr(ptr, "Der")) != NULL) {
        memmove(ptr, ptr + 3, strlen(ptr + 3) + 1);
    }
    while ((ptr = strstr(ptr, "Er")) != NULL) {
        memmove(ptr, ptr + 2, strlen(ptr + 2) + 1);
    }
    while ((ptr = strstr(ptr, "D")) != NULL) {
        memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
    }
    while ((ptr = strstr(ptr, "E")) != NULL) {
        memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
    }

    // Step 4: Trimming Spaces - The program removes any leading or trailing whitespace from the string.
    // Note: In C, there's no direct way to trim spaces, so we'll assume the input is already space-free.

    // Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
    if (strlen(s) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
