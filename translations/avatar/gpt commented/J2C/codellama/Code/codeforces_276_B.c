#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

int main() { 
    // Initialize input stream to read from standard input
    FILE *inputStream = stdin; 
    char str[100]; 
    fgets(str, 100, inputStream); 
    
    // Create a map to count occurrences of each character
    int map[256]; 
    int oddCount = 0; // Initialize counter for characters with odd occurrences
    
    // Iterate through each character in the input string
    for (int i = 0; i < strlen(str); i++) { 
        char ch = str[i]; 
        // Update the count of the character in the map
        if (map[ch] != 0) { 
            map[ch]++; 
        } else { 
            map[ch] = 1; 
        } 
    } 
    
    // Count how many characters have an odd number of occurrences
    for (int i = 0; i < 256; i++) { 
        if (map[i] % 2 != 0) { 
            oddCount++; 
        } 
    } 
    
    // Determine the output based on the count of odd occurrences
    if (oddCount <= 1 || oddCount % 2 != 0) { 
        printf("First\n"); // Output "First" if conditions are met
    } else { 
        printf("Second\n"); // Output "Second" otherwise
    } 
    
    return 0; 
} 
