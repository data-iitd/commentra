#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

int main() {
    char s[MAX_CHARS];
    int dt[MAX_CHARS] = {0};
    int cnt = 0;
    int x = 1;

    // Read input and convert it to a list of characters
    fgets(s, sizeof(s), stdin);

    // Count the occurrences of each character in the input list
    for (int i = 0; i < strlen(s); i++) {
        dt[(int)s[i]]++;
    }

    // Check the counts of each character to determine the number of odd occurrences
    for (int i = 0; i < MAX_CHARS; i++) {
        if (dt[i] % 2 != 0) {
            if (cnt < 1) {
                cnt++;  // Count the first odd occurrence
            } else {
                x = 0;  // More than one odd occurrence found, set flag to False
                break;
            }
        }
    }

    // Determine the output based on the number of odd occurrences and the length of the input
    if (x) {
        printf("First\n");  // If there are no more than one odd occurrences, print "First"
    } else if (!x && strlen(s) % 2 == 0) {
        printf("Second\n");  // If there are more than one odd occurrences and the length is even, print "Second"
    } else if (!x && strlen(s) % 2 != 0) {
        printf("First\n");  // If there are more than one odd occurrences and the length is odd, print "First"
    }

    return 0;
}
