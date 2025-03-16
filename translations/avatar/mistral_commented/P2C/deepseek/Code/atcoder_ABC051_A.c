#include <stdio.h>
#include <string.h>

int main() {
    char input_string[1000];
    // Read a line from input using fgets
    fgets(input_string, sizeof(input_string), stdin);

    // Remove the newline character if it exists
    size_t len = strlen(input_string);
    if (len > 0 && input_string[len - 1] == '\n') {
        input_string[len - 1] = '\0';
    }

    // Replace all commas with spaces in the input string
    for (int i = 0; i < len; i++) {
        if (input_string[i] == ',') {
            input_string[i] = ' ';
        }
    }

    // Print the modified string to the console
    printf("%s\n", input_string);

    return 0;
}
