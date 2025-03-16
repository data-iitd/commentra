#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable to hold the input
<<<<<<< HEAD
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
=======
    char s[100]; // Assuming the maximum length of the input string is 99 characters + 1 for null terminator
>>>>>>> 98c87cb78a (data updated)
    
    // Read the input string from the user
    scanf("%s", s);
    
    // Get the size of the input string
    int n = strlen(s);
    
    // Initialize an array to count occurrences of each character (a-z)
    int v[26] = {0};
    
    // Count the frequency of each character in the string
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++; // Increment the count for the corresponding character
    }
    
    // Assume the answer is "Yes" initially
    char *ans = "Yes";
    
    // Check if each character's count is even
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 != 0) { // If any character has an odd count
            ans = "No"; // Set answer to "No"
            break; // Exit the loop early as we found an odd count
        }
    }
    
    // Output the result
    printf("%s\n", ans);
    
    return 0;
}

// <END-OF-CODE>
