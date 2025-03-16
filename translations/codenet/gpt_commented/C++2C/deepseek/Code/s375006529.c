#include <stdio.h>
#include <string.h>

int main() {
    // Declare a character array to hold the input
    char s[100];
    
    // Read the input string from the user
    scanf("%s", s);
    
    // Get the size of the input string
    int n = strlen(s);
    
    // Initialize an array to count occurrences of each character (a-z)
    int v[26] = {};
    
    // Count the frequency of each character in the string
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++; // Increment the count for the corresponding character
    }
    
    // Assume the answer is "Yes" initially
    char ans[4] = "Yes";
    
    // Check if each character's count is even
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 != 0) { // If any character has an odd count
            strcpy(ans, "No"); // Set answer to "No"
            break; // Exit the loop early as we found an odd count
        }
    }
    
    // Output the result
    printf("%s\n", ans);
}
