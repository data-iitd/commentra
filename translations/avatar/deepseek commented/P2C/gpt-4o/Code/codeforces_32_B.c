#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Declare a string to hold the input
    char result[200] = "";  // Initialize an empty string to store the result
    int i = 0;  // Initialize the index to 0

    // Take an input string from the user
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;  // Remove the newline character from the input

    // Start a while loop that will run as long as the index i is less than the length of the input string s
    while (i < strlen(s)) {
        if (s[i] == '.') {  // Check if the current character is a period
            strcat(result, "0");  // Append '0' to the result if the current character is a period
        } else {
            i++;  // Increment the index i by 1
            if (i < strlen(s) && s[i] == '.') {  // Check the next character in the string
                strcat(result, "1");  // Append '1' to the result if the next character is a period
            } else {
                strcat(result, "2");  // Append '2' to the result if the next character is not a period
            }
        }
        i++;  // Increment the index i by 1 to move to the next character in the string
    }

    printf("%s\n", result);  // Print the final result
    return 0;
}  // <END-OF-CODE>
