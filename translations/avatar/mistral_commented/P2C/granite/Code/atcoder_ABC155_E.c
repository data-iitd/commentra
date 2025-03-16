
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input string's'
    char s[100001];
    fgets(s, 100001, stdin);

    // Initialize variables 'pp' and 'na'
    int pp = 0;
    int na = 0;

    // Iterate through each character in the input string's'
    for (int i = strlen(s) - 2; i >= 0; i--) {
        // Calculate current character value 'cc'
        int cc = na + (s[i] - '0');
        na = 0;

        // Update 'pp' based on the current character value 'cc'
        if (cc <= 4) {
            pp += cc;
        } else {
            // If current character is the last character, add 1 to 'pp'
            if (i == 0) {
                pp += 1;
            } else {
                // Otherwise, add 10 - 'cc' to 'pp'
                pp += 10 - cc;
            }
        }
    }

    // Print the result 'pp'
    printf("%d\n", pp);

    return 0;
}

