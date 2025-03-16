#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the input string from the user
    char input[100];
    scanf("%s", input);

    // Split the input string using '.' as delimiter
    char *s = strtok(input, ".");
    char *p = strtok(NULL, ".");

    // Get the length of the string 's'
    int len_s = strlen(s);
    
    // Get the last character of the string 's'
    char last_char = s[len_s - 1];

    // Check if the last character of the string 's' is '9'
    if (last_char == '9') {
        // If yes, print the message "GOTO Vasilisa."
        printf("GOTO Vasilisa.\n");
    }
    // Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
    else if (last_char != '9' && (p[0] - '0') < 5) {
        // Print the string 's'
        printf("%s\n", s);
    }
    // Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
    else {
        // Increment the last character of the string 's' by 1
        s[len_s - 1] = (last_char - '0' + 1) + '0';
        // Print the updated string 's'
        printf("%s\n", s);
    }

    return 0;
}

// <END-OF-CODE>
