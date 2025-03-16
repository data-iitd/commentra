

#include <stdio.h>

int main() {
    // Read a line from input using the fgets function
    char input_string[100];
    fgets(input_string, 100, stdin);

    // Replace all commas with spaces in the input string
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == ',') {
            input_string[i] ='';
        }
    }

    // Print the modified string to the console
    printf("%s", input_string);

    return 0;
}

Translate the above C code to Java and end with comment "