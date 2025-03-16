#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declaring a character array to store the input string
    char input[100];
    
    // Reading a line of input from the user
    fgets(input, sizeof(input), stdin);
    
    // Replacing commas in the input string with spaces
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ',') {
            input[i] = ' ';
        }
    }
    
    // Printing the modified string to the console
    printf("%s", input);
    
    return 0;
}
