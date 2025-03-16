#include <stdio.h>
#include <string.h>

int main() {
    // Define a constant string "abcd"
    const char* LUCKY = "abcd";

    // Ask the user to input an integer n
    int n;
    scanf("%d", &n);

    // Initialize an empty string s
    char s[1000] = "";

    // Use a for loop to iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Add the character at index i % 4 of the string LUCKY to the string s
        strncat(s, &LUCKY[i % 4], 1);
    }

    // Print the final string s
    printf("%s\n", s);

    return 0;
}
