#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char my_str[100] = "";
    int i;

    // Read input from the user and convert it to a string
    fgets(s, sizeof(s), stdin);

    // Iterate through each character in the input string
    for (i = 0; i < strlen(s); i++) {
        // Check if the character is '0' or '1'
        if (s[i] == '0' || s[i] == '1') {
            // If it is, append it to the result string
            strncat(my_str, &s[i], 1);
        }
        // Check if the character is 'B' and the result string is not empty
        else if (s[i] == 'B' && strlen(my_str) != 0) {
            // If it is, remove the last character from the result string
            my_str[strlen(my_str) - 1] = '\0';
        }
    }

    // Print the final result string
    printf("%s\n", my_str);

    return 0;
}
