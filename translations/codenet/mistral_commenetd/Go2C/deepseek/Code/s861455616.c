#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Declare a character array to store the input string

    // Use the "scanf" function to read a string input from the standard input
    scanf("%s", s);

    // Check if the length of the string "s" is greater than or equal to 4
    // and if its first four characters are "YAKI"
    if (strlen(s) >= 4 && strncmp(s, "YAKI", 4) == 0) {
        // If the condition is true, print the word "Yes" to the standard output
        printf("Yes\n");
    } else {
        // If the condition is false, print the word "No" to the standard output
        printf("No\n");
    }

    return 0;
}

