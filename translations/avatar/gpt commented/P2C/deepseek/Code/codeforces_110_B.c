#include <stdio.h>
#include <string.h>

#define LUCKY "abcd"

int main() {
    int n;
    char s[1000]; // Assuming the maximum length of the output string is 1000
    int i;

    // Read an integer input from the user
    scanf("%d", &n);

    // Initialize the string to store the result
    memset(s, 0, sizeof(s)); // Clear the string

    // Loop through a range of 'n' to build the output string
    for (i = 0; i < n; i++) {
        // Append the character from LUCKY based on the current index modulo 4
        s[i] = LUCKY[i % 4];
    }

    // Print the final constructed string
    printf("%s\n", s);

    return 0;
}
