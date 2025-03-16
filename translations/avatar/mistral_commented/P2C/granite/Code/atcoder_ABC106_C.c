
###
# Code
###

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // Reading input string and number of occurrences of '1' required
    char *s = argv[1];
    int k = atoi(argv[2]);

    // Finding the length of the substring consisting only of '1's
    int l = 0;
    for (int i = 0; s[i]!= '\0'; i++) {
        if (s[i]!= '1') {
            // If the length of the substring is greater than or equal to the required number of occurrences, return 1
            if (l >= k) {
                return 1;
            }
            break;
        }
        l++;
    }

    // If the length of the substring is less than the required number of occurrences, return the character after the substring
    return s[l] - '0';
}

