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
    // Declare a variable to hold the input string
    char a[100]; // Assuming the input string will not exceed 99 characters

    // Read input from the user and store it in variable 'a'
    scanf("%s", a);

    // Replace all occurrences of '1' with '0' in the input string
    replace(a, '1', '0');

    // Replace all occurrences of '9' with '1' in the modified string
    replace(a, '9', '1');

    // Replace all occurrences of '0' with '9' in the second modified string
    replace(a, '0', '9');

    // Print the final transformed string
    printf("%s\n", a);

    return 0;
}

// <END-OF-CODE>
