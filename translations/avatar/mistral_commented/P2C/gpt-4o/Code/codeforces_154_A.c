#include <stdio.h>
#include <string.h>

int main() {
    // Take the input string 's' and an integer 'n' from the user
    char s[100]; // Assuming the maximum length of s is 100
    scanf("%s", s);
    int n;
    scanf("%d", &n);

    // Initialize the answer variable 'ans' to 0
    int ans = 0;

    // Iterate through the given range 'n' times
    for (int i = 0; i < n; i++) {
        // Take the next string 'x' as input
        char x[3]; // Assuming x has exactly 2 characters plus a null terminator
        scanf("%s", x);

        // Initialize variables 'a' and 'b' to 0
        int a = 0, b = 0;

        // Iterate through each character 'j' in the string 's'
        for (int j = 0; j < strlen(s); j++) {
            char current_char = s[j];

            // If the character 'j' matches the first character of the string 'x', increment 'a'
            if (current_char == x[0]) {
                a++;
            }
            // If the character 'j' matches the second character of the string 'x', increment 'b'
            else if (current_char == x[1]) {
                b++;
            }
            // If the current character 'j' does not match any character in the string 'x',
            // add the minimum of 'a' and 'b' to the answer variable 'ans' and reset 'a' and 'b' to 0
            else {
                ans += (a < b) ? a : b; // Add the minimum of a and b to ans
                a = 0; // Reset a
                b = 0; // Reset b
            }
        }

        // Add the minimum of 'a' and 'b' to the answer variable 'ans' after the inner loop completes
        ans += (a < b) ? a : b; // Add the minimum of a and b to ans
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
