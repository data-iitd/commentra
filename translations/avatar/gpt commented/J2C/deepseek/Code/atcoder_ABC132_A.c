#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare a character array to store the input string
    char s[100];
    
    // Read the input string from the user
    scanf("%s", s);
    
    // Get the length of the input string
    int len = strlen(s);
    
    // Declare a 2D array to store the frequency of each character
    int map[256] = {0};
    
    // Loop through each character in the input string
    for (int i = 0; i < len; i++) {
        // Increment the frequency of the character
        map[(unsigned char)s[i]]++;
    }
    
    // Declare a boolean variable to check if the conditions are met
    int ok = 1;
    
    // Check if each character appears exactly twice
    for (int i = 0; i < 256; i++) {
        if (map[i] != 2) {
            ok = 0; // Set ok to false if any character does not appear twice
            break;
        }
    }
    
    // Check if there are exactly two unique characters that appear twice
    if (ok && len == 2) {
        printf("Yes\n"); // Output "Yes" if conditions are satisfied
    } else {
        printf("No\n"); // Output "No" if conditions are not satisfied
    }
    
    return 0;
}
