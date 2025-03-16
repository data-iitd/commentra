#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read an integer N from the user
    int N;
    scanf("%d", &N);
    
    // Initialize a long variable i starting from 357
    long i = 357;
    
    // Initialize a counter to keep track of valid numbers
    int c = 0;
    
    // Loop until i exceeds N
    while (i <= N) {
        // Convert the current number i to a String
        char s[20];
        sprintf(s, "%ld", i);
        
        // Check if the string contains '3', '5', and '7'
        if (strchr(s, '3') && strchr(s, '5') && strchr(s, '7')) {
            c++; // Increment the counter if all digits are present
        }
        
        // Create a new string to construct a new number
        char sb[20];
        int f = 0; // Flag to indicate if a replacement has occurred
        int len = strlen(s);
        
        // Iterate through the digits of the number in reverse order
        for (int j = 0; j < len; j++) {
            char a = s[len - 1 - j]; // Get the current digit
            
            // If a replacement has occurred, append the digit as is
            if (f) {
                sb[j] = a;
            } else {
                // Replace '3' with '5' and set the flag
                if (a == '3') {
                    sb[j] = '5';
                    f = 1;
                }
                // Replace '5' with '7' and set the flag
                else if (a == '5') {
                    sb[j] = '7';
                    f = 1;
                }
                // If it's neither, append '3'
                else {
                    sb[j] = '3';
                }
            }
        }
        
        // If no replacement occurred, append '3' to the end
        if (!f) {
            sb[len] = '3';
            len++;
        }
        
        // Reverse the constructed number
        for (int j = 0; j < len / 2; j++) {
            char temp = sb[j];
            sb[j] = sb[len - 1 - j];
            sb[len - 1 - j] = temp;
        }
        
        // Null-terminate the string
        sb[len] = '\0';
        
        // Parse the new number back to long
        i = strtol(sb, NULL, 10);
    }
    
    // Print the total count of valid numbers found
    printf("%d\n", c);
    
    return 0;
}

// <END-OF-CODE>
