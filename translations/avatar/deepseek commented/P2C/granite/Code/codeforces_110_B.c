

#include <stdio.h>

int main() {
    char LUCKY[] = "abcd";
    // Define a string LUCKY containing the characters "abcd"

    int n;
    scanf("%d", &n);
    // Take an integer input n from the user

    char s[n];
    // Initialize an array s of size n to store the result

    for (int i = 0; i < n; i++) {
        // Loop n times to construct the string s
        s[i] = LUCKY[i % 4];
        // Assign a character from LUCKY to s[i] based on the index i modulo 4
    }

    printf("%s\n", s);
    // Print the final string s

    return 0;
}
// Print the final string s



Translate the above Python code to Java and end with comment "