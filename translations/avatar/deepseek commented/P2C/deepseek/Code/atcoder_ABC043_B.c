#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Declare a character array to store the input string
    char my_str[100] = "";  // Declare and initialize an empty string to build the result

    // Read the input string from the user
    fgets(s, sizeof(s), stdin);

    // Iterate over each character in the input string `s`
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '0' || s[i] == '1') {  // Check if the character is '0' or '1'
            strncat(my_str, &s[i], 1);  // Append the character to `my_str`
        } else if (s[i] == 'B' && strlen(my_str) != 0) {  // Check if the character is 'B' and `my_str` is not empty
            my_str[strlen(my_str) - 1] = '\0';  // Remove the last character from `my_str`
        }
    }

    // Print the content of `my_str`
    printf("%s\n", my_str);

    return 0;
}
