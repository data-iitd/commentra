#include <stdio.h>
#include <string.h>

int N; // Global variable to store the user input

int aaa(char *n) { // Function definition for function `aaa` that takes a string argument `n`
    int num = atoi(n); // Convert string `n` to integer
    if (num > N) { // Check if the input integer `n` is greater than `N`
        return 0; // If it is, return 0
    }

    // Check if the set of digits in `n` is exactly {'7', '5', '3'}
    int ans = (num == 753 || num == 735 || num == 573 || num == 537 || num == 375 || num == 357) ? 1 : 0;

    // Iterate through each character in the string "753"
    for (char *i = "753"; *i; i++) {
        char next[10]; // Buffer to hold the next number as a string
        sprintf(next, "%s%c", n, *i); // Create the next number by appending the character
        ans += aaa(next); // Call the function recursively with the argument `next` and add the result to `ans`
    }

    return ans; // Return the value of `ans`
}

int main() {
    scanf("%d", &N); // User inputs an integer value `N`
    printf("%d\n", aaa("0")); // Call the function with argument "0" and print the result
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
