#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    char s[1000000], x[1000000];
    int n, i, j, a, b, ans = 0;
    
    // Read the main string from user input
    scanf("%s", s);
    
    // Read the number of subsequent strings to process
    scanf("%d", &n);
    
    // Loop through each of the n strings provided by the user
    for (i = 0; i < n; i++) {
        // Read the current string
        scanf("%s", x);
        
        // Initialize counters for characters matching the first and second characters of x
        a = 0;
        b = 0;
        
        // Loop through each character in the main string s
        for (j = 0; j < strlen(s); j++) {
            // If the character matches the first character of x, increment counter a
            if (s[j] == x[0]) {
                a++;
            }
            // If the character matches the second character of x, increment counter b
            else if (s[j] == x[1]) {
                b++;
            }
            else {
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

