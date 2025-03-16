
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // Read the input string
    char x[100001];
    fgets(x, 100001, stdin);
    // Remove the newline character at the end of the input string
    x[strlen(x) - 1] = '\0';

    // Create a stack to store the characters
    char s[100001];
    int top = -1;
    int c = 0; // Counter for pairs of '0' and '1'

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        // Push the current character onto the stack
        s[++top] = x[i];

        // Process the stack while there are at least two characters
        while (top > 0) {
            // Pop the top character
            char p = s[top--];
            // Pop the next character
            char q = s[top];

            // Check if the characters form a pair of '0' and '1'
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++; // Increment the counter for valid pairs
                continue; // Continue to check for more pairs
            } else {
                // If not a valid pair, push the characters back onto the stack
                s[++top] = q;
                s[++top] = p;
                break; // Exit the while loop
            }
        }
    }

    // Output the result, which is twice the count of pairs found
    printf("%d\n", c * 2);

    return 0;
}
// END-OF-CODE