#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char *s) {
    int length = strlen(s);
    // Loop through the first half of the string
    for (int i = 0; i < length / 2; i++) {
        // Compare characters from the start and end of the string
        if (s[i] != s[length - 1 - i]) {
            // If any characters do not match, return false
            return false;
        }
    }
    // If all characters match, return true
    return true;
}

int main() {
    // Declare a string variable to store user input
<<<<<<< HEAD
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    // Read the input string from the user
    scanf("%s", s);
=======
    char s[100]; // Assuming a maximum length of 99 characters + null terminator
    // Read the input string from the user
    scanf("%s", s);
    
>>>>>>> 98c87cb78a (data updated)
    // Check if the entire string and its first half are palindromes
    if (isPalindrome(s) && isPalindrome(strndup(s, strlen(s) / 2))) {
        // Print "Yes" if both conditions are true
        printf("Yes\n");
    } else {
        // Print "No" if either condition is false
        printf("No\n");
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
