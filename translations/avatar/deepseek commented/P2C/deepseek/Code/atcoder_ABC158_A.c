#include <stdio.h>
#include <string.h>

int main() {
    char stdin[100];  // Declare a character array to store the input
    char s[100];  // Declare a character array to store the input
    char result[4];  // Declare a character array to store the result ("Yes" or "No")

    // Read input from the user and store it in stdin
    fgets(stdin, sizeof(stdin), stdin);

    // Copy the input to the variable s
    strcpy(s, stdin);

    // Check if the string s contains both "A" and "B"
    if (strstr(s, "A") != NULL && strstr(s, "B") != NULL) {
        strcpy(result, "Yes");  // If both "A" and "B" are in the string, set result to "Yes"
    } else {
        strcpy(result, "No");  // Otherwise, set result to "No"
    }

    // Print the result
    printf("%s\n", result);

    return 0;
}

