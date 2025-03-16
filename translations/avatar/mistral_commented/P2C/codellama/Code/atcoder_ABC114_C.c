
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N; // Declare an integer variable `N`

int aaa(int n) { // Function definition for function `aaa` that takes an integer argument `n`
    if (n > N) { // Check if the input integer `n` is greater than `N`
        return 0; // If it is, return 0
    }

    int ans = 1; // Declare an integer variable `ans` and assign it a value of 1

    if (strlen(itoa(n, NULL, 10)) == 3) { // Check if the length of the string representation of the integer `n` is equal to 3
        char *str = itoa(n, NULL, 10); // Declare a character pointer `str` and assign it the string representation of the integer `n`

        if (str[0] == '7' && str[1] == '5' && str[2] == '3') { // Check if the first character of `str` is equal to '7', the second character is equal to '5', and the third character is equal to '3'
            ans = 1; // If all of the above conditions are true, assign `ans` a value of 1
        } else {
            ans = 0; // Otherwise, assign `ans` a value of 0
        }
    }

    for (int i = 0; i < 3; i++) { // Iterate through each character in the string `'753'`
        ans += aaa(n + i); // Call the function recursively with the argument `n + i` and add the result to `ans`
    }

    return ans; // Return the value of `ans`
}

int main() { // Function definition for function `main`
    scanf("%d", &N); // Read an integer value `N` from the user

    printf("%d\n", aaa(0)); // Call the function with argument `0` and print the result

    return 0; // Return 0
}

