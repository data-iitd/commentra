#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <stdint.h> 

// Structure to store a character and its frequency
typedef struct { 
    char c; 
    int freq; 
} CharFreq; 

// Function to check if the characters in s2 are all present in s1
bool isValid(char *s1, char *s2) { 
    int n1 = strlen(s1); 
    int n2 = strlen(s2); 
    // Create a HashMap to store characters from the first string
    CharFreq map[n1]; 
    
    // Add all characters from the first string to the map
    for (int i = 0; i < n1; i++) { 
        map[i].c = s1[i]; 
        map[i].freq = 1; 
    } 
    
    // Check if all characters in the second string are present in the first string
    for (int i = 0; i < n2; i++) { 
        bool found = false; 
        for (int j = 0; j < n1; j++) { 
            if (map[j].c == s2[i]) { 
                found = true; 
                break; 
            } 
        } 
        if (!found) return false; 
    } 
    return true; // All characters are valid
} 

// Function to calculate the minimum frequency of each character present in both strings
int minFreq(char *s1, char *s2) { 
    int n1 = strlen(s1); 
    int n2 = strlen(s2); 
    // Create a HashMap to store characters from the first string
    CharFreq map[n1]; 
    
    // Add all characters from the first string to the map
    for (int i = 0; i < n1; i++) { 
        map[i].c = s1[i]; 
        map[i].freq = 1; 
    } 
    
    // Initialize a variable to hold the result
    int ans = 0; 
    // Create a HashSet to track unique characters from the second string
    char hs[n2]; 
    int hs_size = 0; 
    
    // Calculate the minimum frequency of each character present in both strings
    for (int i = 0; i < n2; i++) { 
        bool found = false; 
        for (int j = 0; j < n1; j++) { 
            if (map[j].c == s2[i]) { 
                found = true; 
                break; 
            } 
        } 
        if (!found) continue; 
        for (int j = 0; j < hs_size; j++) { 
            if (hs[j] == s2[i]) { 
                found = false; 
                break; 
            } 
        } 
        if (!found) { 
            hs[hs_size++] = s2[i]; 
            int x1 = map[i].freq; // Frequency in the first string
            int x2 = 1; // Frequency in the second string
            x1 = x1 < x2 ? x1 : x2; // Take the minimum frequency
            ans += x1; // Add to the result
        } 
    } 
    return ans; // Return the final result
} 

int main() { 
    // Create a Scanner object to read input from the console
    char s1[1000], s2[1000]; 
    scanf("%s %s", s1, s2); 
    
    // Validate the input strings; if invalid, print -1 and exit
    if (isValid(s1, s2) == false) { 
        printf("%d\n", -1); 
    } else { 
        // Calculate the minimum frequency of each character present in both strings
        int ans = minFreq(s1, s2); 
        // Print the final result
        printf("%d\n", ans); 
    } 
    return 0; 
} 

