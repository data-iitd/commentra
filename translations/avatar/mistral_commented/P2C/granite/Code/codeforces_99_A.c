
#include <stdio.h>
#include <string.h>

int main() {
    char l[100];
    char s[100];
    char p[100];
    char last_char;

    // Get the input string from the user
    scanf("%s", l);

    // Split the input string using '.' as delimiter and store the list in 'l'
    sscanf(l, "%[^.]", s);
    sscanf(l + strlen(s) + 1, "%s", p);

    // Get the last character of the string's' and store it in a variable 'last_char'
    last_char = s[strlen(s) - 1];

    // Check if the last character of the string's' is '9'
    if (last_char == '9') {
        // If yes, print the message "GOTO Vasilisa."
        printf("GOTO Vasilisa.");
    }

    // Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
    else if (last_char!= '9' && atoi(p) < 5) {
        // Concatenate all the characters of's' to form a string
        printf("%s", s);
    }

    // Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
    else {
        // Concatenate all the characters of's' to form a string
        printf("%s", s);
        // Increment the last character of the string's' by 1
        s[strlen(s) - 1]++;
        // Print the updated string's'
        printf("%s", s);
    }

    return 0;
}
