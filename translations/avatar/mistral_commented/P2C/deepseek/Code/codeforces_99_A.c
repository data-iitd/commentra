#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char l[100];
    char *s, *p;
    char last_char;

    // Get the input string from the user
    fgets(l, sizeof(l), stdin);

    // Remove newline character if present
    l[strcspn(l, "\n")] = '\0';

    // Split the input string using '.' as delimiter and store the list in 'l'
    char *token = strtok(l, ".");
    if (token != NULL) {
        s = token;
        p = strtok(NULL, ".");
    }

    // Get the last character of the string 's' and store it in a variable 'last_char'
    last_char = s[strlen(s) - 1];

    // Check if the last character of the string 's' is '9'
    if (last_char == '9') {
        // If yes, print the message "GOTO Vasilisa."
        printf("GOTO Vasilisa.\n");
    }
    // Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
    else if (last_char != '9' && p != NULL && atoi(p) < 5) {
        // Concatenate all the characters of 's' to form a string
        printf("%s\n", s);
    }
    // Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
    else {
        // Concatenate all the characters of 's' to form a string
        int num = atoi(s) + 1;
        printf("%d\n", num);
    }

    return 0;
}
