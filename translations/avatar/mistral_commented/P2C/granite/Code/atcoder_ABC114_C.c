

#include <stdio.h>
#include <string.h>

int N; // Global variable `N`

int aaa(char *n) { // Function definition for function `aaa` that takes a string argument `n`
    if (atoi(n) > N) { // Check if the integer value of the string `n` is greater than `N`
        return 0; // If it is, return 0
    }

    int ans = 1; // Initialize `ans` to 1

    if (strlen(n) == 1 && strchr(n, '7') && strchr(n, '5') && strchr(n, '3')) { // Check if the length of the string `n` is 1 and it contains all the characters '7', '5', and '3'
        ans = 0; // If it does, assign a value of 0 to `ans`
    }

    for (int i = 0; i < 4; i++) { // Iterate through each character in the string `'753'`
        char temp[10]; // Create a temporary string `temp`
        strcpy(temp, n); // Copy the contents of the string `n` to `temp`
        temp[strlen(n)] = '753'[i]; // Append the `i`-th character of the string `'753'` to `temp`
        ans += aaa(temp); // Call the function recursively with the argument `temp` and add the result to `ans`
    }

    return ans; // Return the value of `ans`
}

int main() { // Main function
    scanf("%d", &N); // Read an integer value from the user and store it in `N`
    printf("%d\n", aaa("0")); // Call the function `aaa` with argument `'0'` and print the result
    return 0; // Return 0
}

Translate the above C code to Java and end with comment "