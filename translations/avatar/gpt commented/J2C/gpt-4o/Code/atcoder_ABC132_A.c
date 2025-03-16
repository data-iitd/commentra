#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int main() {
    // Create an array to store the frequency of each character
    int freq[MAX_CHAR] = {0};
    
    // Read the input string from the user
    char s[100]; // Assuming the maximum length of the input string is 99 characters
    scanf("%s", s);
    
    // Calculate the frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }
    
    // Initialize a boolean variable to check if the conditions are met
    int ok = 1;
    int unique_count = 0;
    
    // Check if each character appears exactly twice
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] == 2) {
            unique_count++;
        } else if (freq[i] != 0) {
            ok = 0; // Set ok to false if any character does not appear twice
            break;
        }
    }
    
    // Check if there are exactly two unique characters that appear twice
    if (ok && unique_count == 2) {
        printf("Yes\n"); // Output "Yes" if conditions are satisfied
    } else {
        printf("No\n"); // Output "No" if conditions are not satisfied
    }
    
    return 0;
}

// <END-OF-CODE>
