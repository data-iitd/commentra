
#include <stdio.h>
#include <string.h>

#define LUCKY "abcd"
// Define a string LUCKY containing the characters "abcd"

int main() {
    int n;
    // Declare an integer variable n to store the input

    char s[1000];
    // Declare a character array s to store the result

    scanf("%d", &n);
    // Take an integer input n from the user

    for (int i = 0; i < n; i++) {
        // Loop n times to construct the string s
        s[i] = LUCKY[i % 4];
        // Append a character from LUCKY to s based on the index i modulo 4
    }

    printf("%s\n", s);
    // Print the final string s

    return 0;
}

