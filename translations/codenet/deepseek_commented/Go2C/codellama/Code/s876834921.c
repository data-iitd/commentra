#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s); // Step 1: Reading Input - The program starts by declaring a string variable `s` and using `scanf` to read input from the user.

    int i = 0;
    while (s[i] != '\0') { // Step 2: Replacing Substrings - The program replaces occurrences of "dream" with "D" and "erase" with "E".
        if (s[i] == 'd') {
            s[i] = 'D';
        } else if (s[i] == 'e') {
            s[i] = 'E';
        }
        i++;
    }

    i = 0;
    while (s[i] != '\0') { // Step 3: Removing Modified Substrings - The program further replaces occurrences of "Der", "Er", "D", and "E" with an empty string.
        if (s[i] == 'D' || s[i] == 'E' || s[i] == 'r') {
            s[i] = '\0';
        }
        i++;
    }

    i = 0;
    while (s[i] != '\0') { // Step 4: Trimming Spaces - The program removes any leading or trailing whitespace from the string.
        if (s[i] == ' ') {
            s[i] = '\0';
        }
        i++;
    }

    if (s[0] == '\0') { // Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
