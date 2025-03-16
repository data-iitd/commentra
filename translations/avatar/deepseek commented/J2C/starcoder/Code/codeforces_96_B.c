#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read a long integer input from the user
    long number;
    scanf("%ld", &number);
    
    // Initialize two variables, ans and value, to -1 and 0, respectively
    long ans = -1, value = 0;
    
    // Set a mask variable to 2
    int mask = 2;
    
    // The code enters a while loop that continues as long as value is less than the input number
    while (value < number) {
        // Convert the mask value to a binary string, remove the first character, and store the result in the s variable
        char *s = (char *) malloc(sizeof(char) * 32);
        sprintf(s, "%d", mask++);
        s++;
        
        // Count the number of zeros in the binary string and store it in the zeros variable
        int zeros = 0;
        while (*s!= '\0') {
            if (*s == '0') {
                zeros++;
            }
            s++;
        }
        
        // If the number of zeros is not equal to the number of ones, skip the rest of the loop and increment the mask
        if (zeros!= strlen(s) - zeros) {
            continue;
        }
        
        // Replace all zeros with 4 and all ones with 7 in the binary string and convert it back to a long integer
        s = (char *) malloc(sizeof(char) * strlen(s));
        strcpy(s, "00000000000000000000000000000000");
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') {
                s[i] = '4';
            } else {
                s[i] = '7';
            }
        }
        value = atol(s);
    }
    
    // Print the value variable
    printf("%ld\n", value);
    
    // Return from main
    return 0;
}

