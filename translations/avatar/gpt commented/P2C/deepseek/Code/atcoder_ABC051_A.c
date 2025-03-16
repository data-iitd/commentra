#include <stdio.h>
#include <string.h>

int main() {
    char user_input[100];
    char modified_input[200];

    // Read the input string from the user
    fgets(user_input, sizeof(user_input), stdin);

    // Remove the newline character if present
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    // Replace all commas in the input string with spaces
    for (int i = 0; i < strlen(user_input); i++) {
        if (user_input[i] == ',') {
            modified_input[i] = ' ';
        } else {
            modified_input[i] = user_input[i];
        }
    }
    modified_input[strlen(user_input)] = '\0';

    // Print the modified input string
    printf("%s\n", modified_input);

    return 0;
}
