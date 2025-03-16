
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Reading a string from input
    char s[100001];
    scanf("%s", s);
    // Reading an integer k from input
    int k;
    scanf("%d", &k);
    int l = 0;  // Initialize a counter for leading '1's

    // Count the number of leading '1's in the string
    for (int i = 0; s[i]!= '\0'; i++) {
        if (s[i]!= '1') {
            break;
        }
        l++;
    }

    // If the count of leading '1's is greater than or equal to k, return 1
    if (l >= k) {
        printf("1\n");
        return 0;
    }

    // Otherwise, return the character at position l in the string
    printf("%c\n", s[l]);

    return 0;
}
// END-OF-CODE