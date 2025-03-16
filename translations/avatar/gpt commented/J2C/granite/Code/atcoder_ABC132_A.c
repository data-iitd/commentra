
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Create a character array to store the input string
    char targ[100];
    
    // Read the input string from the user
    scanf("%s", targ);
    
    // Initialize a hash table to store the frequency of each character
    int map[256] = {0};
    
    // Loop through each character in the array
    for (int i = 0; targ[i]!= '\0'; i++) {
        // If the character is not already in the map, add it with a count of 1
        if (map[targ[i]] == 0) {
            map[targ[i]] = 1;
        } else {
            // If the character is already in the map, increment its count
            map[targ[i]]++;
        }
    }
    
    // Initialize a boolean variable to check if the conditions are met
    int ok = 1;
    
    // Check if each character appears exactly twice
    for (int i = 0; i < 256; i++) {
        if (map[i]!= 2) {
            ok = 0; // Set ok to 0 if any character does not appear twice
            break;
        }
    }
    
    // Check if there are exactly two unique characters that appear twice
    if (ok && sizeof(map) / sizeof(map[0]) == 2) {
        printf("Yes\n"); // Output "Yes" if conditions are satisfied
    } else {
        printf("No\n"); // Output "No" if conditions are not satisfied
    }
    
    return 0;
}
