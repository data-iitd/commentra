#include <stdio.h>

int main() {
    // Declare a string variable to hold the input
    char str[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    // Read input string from the user
    scanf("%s", str);
    
    // Initialize variables to track the maximum length of valid characters and the current count
    int max = 0, cnt = 0;
    
    // Iterate through each character in the input string
    for (int i = 0; str[i] != '\0'; i++) {
        char sc = str[i];
        // Check if the character is one of the valid DNA bases
        if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
            // Increment the count for consecutive valid characters
            cnt++;
        } else {
            // Reset the count if an invalid character is encountered
            cnt = 0;
        }
        // Update the maximum length if the current count exceeds the previous maximum
        if (cnt > max) {
            max = cnt;
        }
    }
    
    // Output the maximum length of consecutive valid characters found
    printf("%d\n", max);
    
    return 0;
}

// <END-OF-CODE>
