
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Declare a character array to store the input string
    printf("Enter a string: ");  // Prompt the user to enter a string
    scanf("%s", s);  // Read the input string from the user and store it in the character array s
    int len = strlen(s);  // Calculate the length of the input string
    char result[100];  // Declare a character array to store the result
    int i = 0;  // Initialize the index i to 0

    // Start a while loop that will run as long as the index i is less than the length of the input string s
    while (i < len) {
        if (s[i] == '.') {  // Check if the current character is a period
            result[i] = '0';  // Assign '0' to the current position in the result array
        } else {
            i++;  // Increment the index i by 1
            if (s[i] == '.') {  // Check the next character in the string
                result[i] = '1';  // Assign '1' to the current position in the result array
            } else {
                result[i] = '2';  // Assign '2' to the current position in the result array
            }
        }
        i++;  // Increment the index i by 1 to move to the next character in the string
    }

    result[i] = '\0';  // Null-terminate the result array
    printf("Result: %s\n", result);  // Print the final result

    return 0;  // Return 0 to indicate successful execution of the program
}
