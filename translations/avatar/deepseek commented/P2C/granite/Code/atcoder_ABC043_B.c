

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Declare a character array to store the input string
    printf("Enter a string: ");
    scanf("%s", s);  // Read a string input from the user

    char my_str[100] = "";  // Declare a character array to store the result
    int i = 0;  // Initialize an index variable to iterate over the input string

    while (s[i]!= '\0') {  // Iterate over each character in the input string `s`
        if (s[i] == '0' || s[i] == '1') {  // Check if the character is '0' or '1'
            strcat(my_str, &s[i]);  // Append the character to `my_str`
        } else if (s[i] == 'B' && strlen(my_str)!= 0) {  // Check if the character is 'B' and `my_str` is not empty
            my_str[strlen(my_str) - 1] = '\0';  // Remove the last character from `my_str`
        }
        i++;  // Increment the index variable
    }

    printf("Result: %s\n", my_str);  // Print the content of `my_str`

    return 0;
}
