#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN 100000

int main() {
    char s[MAX_LEN + 1];
    int k;

    // Read input string and number of occurrences of '1' required
    scanf("%s", s);
    scanf("%d", &k);

    // Find the length of the substring consisting only of '1's
    int l = 0;
    while (s[l] == '1') {
        l++;
    }

    // If the length of the substring is greater than or equal to the required number of occurrences, return 1
    if (l >= k) {
        printf("1\n");
        return 0;
    }

    // Return the character after the substring
    printf("%c\n", s[l]);
    return 0;
}

