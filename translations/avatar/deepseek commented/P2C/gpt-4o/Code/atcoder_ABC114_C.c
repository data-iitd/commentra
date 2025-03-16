#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;  // Global variable to hold the value of N

// Define a function named `aaa` that takes an argument `n`
int aaa(int n) {
    // Check if the integer value of `n` is greater than N. If it is, return 0
    if (n > N) {
        return 0;
    }

    // Convert n to a string to check its digits
    char str_n[12]; // Enough to hold an integer up to 10 digits and null terminator
    sprintf(str_n, "%d", n);
    
    // Check if the digits of `n` are '7', '5', and '3'
    int ans = (strlen(str_n) == 3 && 
               strchr(str_n, '7') && 
               strchr(str_n, '5') && 
               strchr(str_n, '3') && 
               strlen(str_n) == 3) ? 1 : 0;

    // Iterate over the string "753" and recursively call the function `aaa` with `n` incremented by each digit
    for (char *i = "753"; *i != '\0'; i++) {
        ans += aaa(n + (*i - '0')); // Convert char to int by subtracting '0'
    }

    // Return the value of `ans`
    return ans;
}

int main() {
    // Take an integer input N
    scanf("%d", &N);
    
    // Call the function `aaa` with the initial argument 0 and print the result
    printf("%d\n", aaa(0));

    return 0;
}

// <END-OF-CODE>
