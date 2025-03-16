#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);  // Read the integer input `n`
    
    char s[n + 1];  // Declare a character array for `s` with size `n + 1` for null terminator
    char t[n + 1];  // Declare a character array for `t` with size `n + 1` for null terminator
    
    scanf("%s", s);  // Read the string `s`
    scanf("%s", t);  // Read the string `t`
    
    // Check if the strings `s` and `t` are equal
    if (strcmp(s, t) == 0) {
        printf("%d\n", n);  // If they are equal, print `n`
    } else {
        int cnt = 0;  // Initialize the counter `cnt` to 0
        // Compare elements of `s` and `t` starting from each index `i` of `s`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                // If a mismatch is found, break out of the inner loop
                if (s[i + j] != t[j]) {
                    break;
                }
                // If the end of the inner list is reached without breaking, set `cnt`
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }
        // Print `2 * n - cnt`
        printf("%d\n", 2 * n - cnt);
    }
    
    return 0;
}

// <END-OF-CODE>
