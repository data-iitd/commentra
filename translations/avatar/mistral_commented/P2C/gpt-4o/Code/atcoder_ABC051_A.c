#include <stdio.h>
#include <string.h>

int main() {
    char input_string[1000]; // Buffer to hold the input string

    // Read a line from input
    fgets(input_string, sizeof(input_string), stdin);

    // Replace all commas with spaces
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == ',') {
            input_string[i] = ' ';
        }
    }

    // Print the modified string to the console
    printf("%s", input_string);

    return 0;
}

// <END-OF-CODE>
