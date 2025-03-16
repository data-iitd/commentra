#include <stdio.h>
#include <string.h>

int main() {
    char user_input[256]; // Buffer to hold user input
    printf("Enter a string: ");
    fgets(user_input, sizeof(user_input), stdin); // Read input string

    // Replace all commas in the input string with spaces
    for (int i = 0; i < strlen(user_input); i++) {
        if (user_input[i] == ',') {
            user_input[i] = ' ';
        }
    }

    // Print the modified input string
    printf("%s", user_input);

    return 0;
}

// <END-OF-CODE>
