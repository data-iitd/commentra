
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the given string is a palindrome
bool isPalindrome(char *x) {
    // Creating a stack
    char stack[strlen(x)];
    int top = -1;

    // Iterating through each character in the string
    for (int i = 0; i < strlen(x); i++) {
        // Pushing the character onto the stack
        stack[++top] = x[i];

        // Popping two characters from the stack and checking for a pair
        while (top > 0) {
            char p = stack[top--];
            char q = stack[top--];

            // If the popped characters form a pair, return true and continue
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                return true;
            }

            // If the characters don't form a pair, push them back onto the stack and break
            stack[++top] = q;
            stack[++top] = p;
            break;
        }
    }

    // Returning false if the string is not a palindrome
    return false;
}

// Driver function
int main() {
    char x[100000]; // String to store the input string
    int c; // Counter to store the number of pairs

    scanf("%s", x); // Reading the input string
    c = 0; // Initializing the counter to zero

    // Iterating through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        // If the string is a palindrome, increment the counter and continue
        if (isPalindrome(x)) {
            c++;
            continue;
        }

        // If the string is not a palindrome, reverse the string and increment the counter
        for (int j = 0; j < strlen(x) / 2; j++) {
            char temp = x[j];
            x[j] = x[strlen(x) - j - 1];
            x[strlen(x) - j - 1] = temp;
        }
        c++;
    }

    // Printing the output
    printf("%d\n", c * 2);

    return 0;
}

