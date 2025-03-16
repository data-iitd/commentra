#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char my_str[100] = "";
    int i;

    // Ask the user for a string input
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';

    // Iterate through each character in the user input string
    for (i = 0; i < strlen(s); i++) {
        // If the character is '0' or '1', append it to the binary string
        if (s[i] == '0' || s[i] == '1') {
            strncat(my_str, &s[i], 1);
        }
        // If the character is 'B', remove the last character from the binary string before 'B' was encountered
        else if (s[i] == 'B' && strlen(my_str) != 0) {
            my_str[strlen(my_str) - 1] = '\0';
        }
    }

    // Print the final binary string
    printf("Final binary string: %s\n", my_str);

    return 0;
}
