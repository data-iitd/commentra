#include <stdio.h>
#include <string.h>

int main() {
    // Declare a character array to hold the input
    char str[1000];
    // Read input string from the user
    scanf("%s", str);
    
    // Initialize variables to track the maximum length of valid characters and the current count
    int max = 0, cnt = 0;
    
    // Iterate through each character in the input string
    for (int i = 0; i < strlen(str); i++) {
        // Check if the character is one of the valid DNA bases
        if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T') {
            // Increment the count for consecutive valid characters
            cnt++;
        } else {
            // Reset the count if an invalid character is encountered
            cnt = 0;
        }
        // Update the maximum length if the current count exceeds the previous maximum
        max = max > cnt ? max : cnt;
    }
    
    // Output the maximum length of consecutive valid characters found
    printf("%d\n", max);
}
