#include <stdio.h>                                                                                                                              
#include <string.h>                                                                                                                            
#include <stdbool.h>                                                                                                                          

// Main function starts here
int main() {
    char str[100]; // Declare a character array to store the input string

    // Read the input string from the standard input
    scanf("%s", str);

    int max = 0, cnt = 0; // Initialize two integer variables 'max' and 'cnt' with zero values
    int length = strlen(str); // Get the length of the input string

    // Iterate through each character in the input string using a for loop
    for (int i = 0; i < length; i++) {
        char sc = str[i]; // Get the current character

        // Check if the current character is a valid nucleotide (A, C, G or T)
        if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
            cnt++; // Increment the count if the character is a valid nucleotide
        } else { // Otherwise, reset the count to zero
            cnt = 0;
        }

        // Update the maximum count if the current count is greater than the previous maximum
        if (cnt > max) {
            max = cnt;
        }
    }

    // Print the maximum count of valid nucleotides found in the input string
    printf("%d\n", max);

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
