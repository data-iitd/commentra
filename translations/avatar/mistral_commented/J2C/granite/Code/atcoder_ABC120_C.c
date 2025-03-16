

#include <stdio.h> // Standard input/output library
#include <string.h> // String manipulation library
#include <math.h> // Mathematical functions library
#include <stdlib.h> // Memory allocation and deallocation library

int main() {
    char x[100001]; // Character array to store the input string
    int s[100001]; // Integer array to store the stack
    int c = 0; // Counter to store the number of pairs
    int i, j; // Loop variables

    scanf("%s", x); // Reading the input string

    j = 0; // Initializing the stack pointer to zero

    // Iterating through each character in the input string
    for (i = 0; x[i]!= '\0'; i++) {
        s[j++] = x[i]; // Pushing the character onto the stack

        // Popping two characters from the stack and checking for a pair
        while (j > 1) {
            int p = s[--j]; // Popping the top character
            int q = s[--j]; // Popping the second top character

            // If the popped characters form a pair, increment the counter and continue
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            }

            // If the characters don't form a pair, push them back onto the stack and break
            s[j++] = q;
            s[j++] = p;
            break;
        }
    }

    printf("%d\n", c * 2); // Writing the output to the console

    return 0; // Returning 0 to indicate successful execution
}

