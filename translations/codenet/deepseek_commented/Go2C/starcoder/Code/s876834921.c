#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s); // Step 1: Reading Input - The program starts by declaring a string variable `s` and using `scanf` to read input from the user.

    str_replace(s, "dream", "D", -1); // Step 2: Replacing Substrings - The program replaces occurrences of "dream" with "D" and "erase" with "E".
    str_replace(s, "erase", "E", -1);

    str_replace(s, "Der", "", -1); // Step 3: Removing Modified Substrings - The program further replaces occurrences of "Der", "Er", "D", and "E" with an empty string.
    str_replace(s, "Er", "", -1);
    str_replace(s, "D", "", -1);
    str_replace(s, "E", "", -1);

    str_trim(s); // Step 4: Trimming Spaces - The program removes any leading or trailing whitespace from the string.

    if (strlen(s) == 0) { // Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
        printf("YES");
    } else {
        printf("NO");
    }
}

void str_replace(char *s, char *old, char *new, int n) {
    char *p = strstr(s, old);
    while (p!= NULL) {
        int len = strlen(new);
        int old_len = strlen(old);
        memmove(p + len, p + old_len, strlen(p + old_len) + 1);
        memcpy(p, new, len);
        p += len;
        p = strstr(p, old);
    }
}

void str_trim(char *s) {
    char *p = s;
    while (*p =='') {
        p++;
    }
    strcpy(s, p);
    p = s + strlen(s) - 1;
    while (*p =='') {
        *p = '\0';
        p--;
    }
}

