#include <stdio.h>
#include <string.h>

int main() {
    // Read a string S from the standard input
    char S[1000];
    scanf("%s", S);

    // Get the length of the string
    int len = strlen(S);

    // Iterate over the string in steps of 2, starting from index 2 up to the length of the string
    for (int i = 2; i <= len; i = i + 2) {
        // Check if the substring from the start to the middle of the remaining part of the string
        // is equal to the substring from the middle of the remaining part of the string to the end
        if (strncmp(S, S + (len - i) / 2, (len - i) / 2) == 0) {
            // If a match is found, print the length of the string minus the current step size and break out of the loop
            printf("%d\n", len - i);
            break;
        }
    }

    return 0;
}
