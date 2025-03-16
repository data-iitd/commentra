#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function main is the entry point of the program
int main() {
    // Initialize an empty string variable 's' to store the input string
    char s[100]; // Assuming the input string will not exceed 99 characters
    // Read the input string from the standard input using scanf
    scanf("%s", s);
    // Get the length of the input string 's'
    int l = strlen(s);
    // Initialize an answer string 'ans' with the default value "AC"
    char *ans = "AC";
    // Check if the first character of the input string is not 'A'
    if (s[0] != 'A') {
        // If it's not, set the answer string to "WA"
        ans = "WA";
    }
    // Initialize a counter 'cnt' to count the number of uppercase characters in the input string
    int cnt = 0;
    // Iterate through the input string from the second character to the last character
    for (int i = 1; i < l; i++) {
        // Check if the current character is an uppercase character
        if (isupper(s[i])) {
            // If it is, check some conditions to determine if the answer is "WA"
            if (i == 1 || i == l - 1 || s[i] != 'C') {
                ans = "WA";
            }
            // If the conditions are not met, increment the counter
            cnt++;
        }
    }
    // Check if the counter has the expected value (1)
    if (cnt != 1) {
        // If it doesn't, set the answer string to "WA"
        ans = "WA";
    }
    // Print the answer string to the standard output using printf
    printf("%s\n", ans);
    // End of the code
    return 0;
}
