#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR(i,b,e) for(int i=(b);i<(e);++i)

int main() {
    // Initialize variables for number of students and classes
    int n, m;

    // Read input from the standard input stream
    scanf("%d %d", &n, &m);

    // Initialize arrays 's' and 'c' for storing student numbers and classes respectively
    int s[m], c[m];

    // Read student numbers and classes from the standard input stream
    FOR(i, 0, m) {
        scanf("%d %d", &s[i], &c[i]);
        // Decrement student numbers by 1 as they are 1-indexed
        s[i]--;
    }

    // Check all strings of length 'n' for a valid combination of student numbers and classes
    FOR(i, 0, 1000) {
        // Convert the current number to a string
        char st[4]; // 3 digits + 1 for null terminator
        sprintf(st, "%d", i);

        // Check if the length of the string is equal to 'n'
        if (strlen(st) != n) {
            continue;
        }

        // Initialize a flag 'f' to check if the current combination is valid
        int f = 1;

        // Check each combination of student number and class
        FOR(j, 0, m) {
            // Check if the current character in the string matches the expected class
            if (st[s[j]] == c[j] + '0') {
                // If yes, continue to the next check
            } else {
                // If no, set the flag 'f' to 0 and break the loop
                f = 0;
                break;
            }
        }

        // If all checks passed, print the current number and exit the program
        if (f) {
            printf("%d\n", i);
            return 0;
        }
    }

    // If no valid combination was found, print -1
    printf("-1\n");
    return 0;
}

// <END-OF-CODE>
