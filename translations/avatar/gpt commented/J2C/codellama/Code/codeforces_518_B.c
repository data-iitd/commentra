#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h> 

int main() { 
    // Create a Scanner object to read input from the console
    char *s = malloc(1000000 * sizeof(char)); 
    char *t = malloc(1000000 * sizeof(char)); 
    scanf("%s", s); 
    scanf("%s", t); 
    
    // Read the first string and initialize a StringBuilder with it
    char *s1 = malloc(1000000 * sizeof(char)); 
    strcpy(s1, s); 
    
    // Initialize counters for unique characters replaced (ura) and reversed characters (opa)
    int ura = 0; 
    int opa = 0; 
    
    // Create a map to count occurrences of each character in string t
    char *tmap = malloc(1000000 * sizeof(char)); 
    
    // Populate the character frequency map for string t
    for (int i = 0; i < strlen(t); i++) { 
        char ch = t[i]; 
        // If the character is not already in the map, add it with a count of 1
        if (tmap[ch] == 0) 
            tmap[ch] = 1; 
        else 
            // If it exists, increment its count
            tmap[ch]++; 
    } 
    
    // Get the length of the StringBuilder for iteration
    int length = strlen(s1); 
    
    // First pass: Replace characters in s with 'Я' and update the frequency map
    for (int i = 0; i < length; i++) { 
        char ch = s1[i]; 
        int num = tmap[ch]; 
        // If the character is not in the map, skip it
        if (num == 0) continue; 
        int inum = num; 
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (inum == 1) 
            tmap[ch] = 0; 
        else 
            tmap[ch]--; 
        // Replace the character in the StringBuilder with 'Я'
        s1[i] = 'Я'; 
        // Increment the unique character replacement counter
        ura++; 
    } 
    
    // Second pass: Check for reversed characters and update the frequency map
    for (int i = 0; i < length; i++) { 
        char ch = s1[i]; 
        // Get the reversed character (lowercase to uppercase or vice versa)
        char rch = reverse(ch); 
        int num = tmap[rch]; 
        // If the reversed character is not in the map, skip it
        if (num == 0) continue; 
        int inum = num; 
        // If the count is 1, remove it from the map; otherwise, decrement the count
        if (inum == 1) 
            tmap[rch] = 0; 
        else 
            tmap[rch]--; 
        // Increment the reversed character counter
        opa++; 
    } 
    
    // Output the counts of unique character replacements and reversed characters
    printf("%d %d\n", ura, opa); 
    return 0; 
} 

// Method to reverse the case of a character
char reverse(char ch) { 
    // If the character is lowercase, convert it to uppercase
    if (islower(ch)) { 
        return toupper(ch); 
    } else 
        // If it's uppercase, convert it to lowercase
        return tolower(ch); 
} 

