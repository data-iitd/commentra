#include <stdio.h>
#include <string.h>

void replace(char *str, char oldChar, char newChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    // Declare a string variable to hold user input
    char a[100]; // Assuming the input will not exceed 99 characters

    // Read input from the user and store it in `a`
    scanf("%s", a);

    // Replace all occurrences of "1" with "0" in the string `a`
    replace(a, '1', '0');

    // Replace all occurrences of "9" with "1" in the string `a`
    replace(a, '9', '1');

    // Replace all occurrences of "0" with "9" in the string `a`
    replace(a, '0', '9');

    // Print the final result to the console
    printf("%s\n", a);

    return 0;
}

// <END-OF-CODE>
