#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a character array to store the input string
    char s[100]; 
    
    // Read the input string from the user
    printf("Enter a string: "); 
    scanf("%s", s); 
    
    // Convert the input string to a character array
    char targ[strlen(s)]; 
    strcpy(targ, s); 
    
    // Initialize a hash map to store the frequency of each character
    int map[256]; 
    memset(map, 0, sizeof(map)); 
    
    // Loop through each character in the array
    for (int i = 0; i < strlen(targ); i++) { 
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
        if (map[i] != 2) { 
            ok = 0; // Set ok to false if any character does not appear twice
            break; 
        } 
    } 
    
    // Check if there are exactly two unique characters that appear twice
    if (ok && map[256] == 2) { 
        printf("Yes\n"); // Output "Yes" if conditions are satisfied
    } else { 
        printf("No\n"); // Output "No" if conditions are not satisfied
    } 
    
    return 0; 
}

