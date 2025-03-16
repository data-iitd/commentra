#include <stdio.h>
#include <string.h>

int main() {
    char input[1000]; // Assuming the input will not exceed 999 characters
    fgets(input, sizeof(input), stdin); // Read input from the user

    // Replace commas with spaces
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ',') {
            input[i] = ' ';
        }
    }

    printf("%s", input); // Print the modified string
    return 0;
}

// <END-OF-CODE>
