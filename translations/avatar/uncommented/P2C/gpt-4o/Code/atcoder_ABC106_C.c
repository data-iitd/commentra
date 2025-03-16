#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000000

int main() {
    char s[MAX_LEN];
    int k;

    // Read the string input
    scanf("%s", s);
    // Read the integer input
    scanf("%d", &k);

    int l = 0;
    // Count the number of leading '1's
    while (s[l] == '1' && s[l] != '\0') {
        l++;
    }

    // If the count of leading '1's is greater than or equal to k, return 1
    if (l >= k) {
        printf("1\n");
    } else {
        // Otherwise, return the character at position l
        printf("%c\n", s[l]);
    }

    return 0;
}

// <END-OF-CODE>
