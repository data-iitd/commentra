#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100005];
    long cnt = 0;
    long tmp = 0;

    // Read the input string
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = 0;

    // Replace all occurrences of "BC" with "D"
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'B') {
            for (int j = i + 1; j < strlen(s); j++) {
                if (s[j] == 'C') {
                    s[j] = 'D';
                    i = j;
                    break;
                }
            }
        }
    }

    // Count the number of occurrences of "AD"
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            tmp++;
        } else if (s[i] == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
    }

    // Print the final count
    printf("%ld\n", cnt);

    return 0;
}
