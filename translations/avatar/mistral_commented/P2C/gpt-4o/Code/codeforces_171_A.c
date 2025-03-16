#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Declaring variables to hold the input strings
    char a[100], b[100];
    
    // Reading the input strings
    scanf("%s %s", a, b);
    
    // Finding the maximum length between 'a' and 'b'
    int x = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    
    // Padding 'a' with leading zeros and 'b' with trailing zeros
    char padded_a[100], padded_b[100];
    memset(padded_a, '0', x);
    memset(padded_b, '0', x);
    padded_a[x] = '\0';
    padded_b[x] = '\0';
    
    // Copying the original strings into the padded ones
    strcpy(padded_a + (x - strlen(a)), a);
    strcpy(padded_b, b);
    
    // Initializing an empty string for the result and a counter for carrying
    char s[100] = {0};
    int c = 0;
    int s_index = 0;

    // Iterating through each index
    for (int i = 0; i < x; i++) {
        // Adding the current digits of 'a' and 'b' at the corresponding positions
        int d = (padded_b[i] - '0') + (padded_a[x - i - 1] - '0') + c;

        // If the sum is greater than 9, handle the carry
        if (d > 9) {
            s[s_index++] = (d % 10) + '0'; // Store the last digit
            c = 1; // Set carry
        } else {
            s[s_index++] = d + '0'; // Store the sum
            c = 0; // Reset carry
        }
    }

    // If there is still a carry left, add it to the result string
    if (c == 1) {
        s[s_index++] = '1';
    }

    // Reverse the result string to get the correct order
    for (int i = 0; i < s_index / 2; i++) {
        char temp = s[i];
        s[i] = s[s_index - i - 1];
        s[s_index - i - 1] = temp;
    }
    
    // Null-terminate the result string
    s[s_index] = '\0';

    // Printing the final result after converting to an integer to remove leading zeros
    printf("%d\n", atoi(s));

    return 0;
}

// <END-OF-CODE>
