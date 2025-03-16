#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Declare a character array to store the input string
    char result[100] = "";  // Declare a character array to store the result
    int i = 0;  // Initialize the index to 0

    // Take an input string from the user
    fgets(s, sizeof(s), stdin);

    // Remove the newline character if present
    s[strcspn(s, "\n")] = 0;

    // Start a while loop that will run as long as the index i is less than the length of the input string s
    while (i < strlen(s)) {
        if (s[i] == '.') {  // Check if the current character is a period
            strcat(result, "0");  // Append '0' to the result if the current character is a period
        } else {
            i++;  // Increment the index i by 1
            if (s[i] == '.') {  // Check the next character in the string
                strcat(result, "1");  // Append '1' to the result if the next character is a period
            } else {
                strcat(result, "2");  // Append '2' to the result if the next character is not a period
            }
        }
        i++;  // Increment the index i by 1 to move to the next character in the string
    }

    // Print the final result
    printf("%s\n", result);

    return 0;
}
