#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1000];
    int even[2] = {0}, odd[2] = {0};

    // Take a string input from the user and store it in the variable `s`
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';

    // Count the occurrences of characters at even indices in the string `s`
    for (int i = 0; i < strlen(s); i += 2) {
        even[s[i] - '0']++;
    }

    // Count the occurrences of characters at odd indices in the string `s`
    for (int i = 1; i < strlen(s); i += 2) {
        odd[s[i] - '0']++;
    }

    // Print the minimum of two possible outcomes:
    // 1. The number of characters that need to be flipped to make all even characters '0' and the number of characters that need to be flipped to make all even characters '1', or vice versa.
    printf("%d\n", (int)fmin(strlen(s) - (even[0] + odd[1]), strlen(s) - (even[1] + odd[0])));

    return 0;
}
