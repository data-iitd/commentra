#include <stdio.h>
#include <string.h>

int main() {
    // Read the main string from user input
    char s[1000];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Remove newline character

    // Read the number of subsequent strings to process
    int n;
    scanf("%d\n", &n); // Read integer and consume newline

    // Initialize the answer variable to accumulate results
    int ans = 0;

    // Loop through each of the n strings provided by the user
    for (int i = 0; i < n; i++) {
        // Read the current string
        char x[3]; // Assuming x has exactly 2 characters plus null terminator
        fgets(x, sizeof(x), stdin);
        x[strcspn(x, "\n")] = 0; // Remove newline character

        // Initialize counters for characters matching the first and second characters of x
        int a = 0, b = 0;

        // Loop through each character in the main string s
        for (int j = 0; j < strlen(s); j++) {
            // If the character matches the first character of x, increment counter a
            if (s[j] == x[0]) {
                a++;
            }
            // If the character matches the second character of x, increment counter b
            else if (s[j] == x[1]) {
                b++;
            } else {
                // If a character does not match either, add the minimum of a and b to ans
                ans += (a < b) ? a : b;
                // Reset counters a and b for the next segment
                a = 0;
                b = 0;
            }
        }

        // After finishing the loop, add the minimum of a and b to ans for the last segment
        ans += (a < b) ? a : b;
    }

    // Print the final accumulated answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
