#include <stdio.h>

int main() {
    char s[1000];
    int d = 'a' - 'A';
    int i = 0;

    // Reading the first line from standard input and storing it in the string 's'
    while ((s[i] = getchar()) != '\n') {
        i++;
    }
    s[i] = '\0'; // Null-terminate the string

    // Iterating through each character in the string 's'
    for (i = 0; s[i] != '\0'; i++) {
        char r = s[i];
        char rr = r;

        // Checking if the current character 'r' is an uppercase letter
        if ('A' <= r && r <= 'Z') {
            // If yes, adding the value of 'd' to 'r' and storing it in 'rr'
            rr = r + d;
        } else if ('a' <= r && r <= 'z') {
            // If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
            rr = r - d;
        }

        // Printing the transformed character 'rr' to the standard output
        putchar(rr);
    }

    // Printing a newline character after the transformation is complete
    putchar('\n');

    return 0;
}

