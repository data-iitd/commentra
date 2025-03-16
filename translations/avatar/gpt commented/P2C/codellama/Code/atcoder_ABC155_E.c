#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int main() {
    char *s = NULL;
    int pp = 0, na = 0, i, cc, len;

    // Read input string
    scanf("%ms", &s);
    len = strlen(s);

    // Process the string in reverse order
    for (i = len - 1; i >= 0; i--) {
        cc = na + s[i] - '0';
        na = 0;

        // Determine how to update the total score based on the current value
        if (cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            if (i == len - 1) {
                pp += 1;
            }
            pp += 10 - cc;
        }
    }

    printf("%d\n", pp);
    return 0;
}

