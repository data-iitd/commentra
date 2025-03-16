#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int n, m; 
    scanf("%d %d", &n, &m); 
    
    // Read the number of strings (n) and the number of queries (m)
    char arrs[n][100]; 
    
    // Read n strings from the input
    for (int i = 0; i < n; i++) { 
        scanf("%s", arrs[i]); 
    } 
    
    // Initialize an array to store the lengths of segments between 'G' and 'S'
    int length[n]; 
    int index = 0; 
    int returnDex = 0; 
    
    // Iterate through each string to find the indices of 'G' and 'S'
    for (int i = 0; i < n; i++) { 
        int dexG = strchr(arrs[i], 'G') - arrs[i]; // Find the index of 'G'
        int dexS = strchr(arrs[i], 'S') - arrs[i]; // Find the index of 'S'
        
        // If 'G' appears after 'S', set returnDex to -1
        if (dexG > dexS) { 
            returnDex = -1; 
        } 
        
        // Calculate the length between 'G' and 'S' and store it in the length array
        length[index++] = dexS - dexG; 
    } 
    
    // Use a HashSet to store unique lengths
    int set[n]; 
    int setIndex = 0; 
    
    // Add each length to the HashSet to ensure uniqueness
    for (int i = 0; i < n; i++) { 
        set[setIndex++] = length[i]; 
    } 
    
    // Check if returnDex was set to -1 and print the appropriate result
    if (returnDex == -1) { 
        printf("%d\n", returnDex); // Print -1 if 'G' is after 'S' in any string
    } else { 
        printf("%d\n", setIndex); // Print the number of unique lengths
    } 
    
    return 0; 
} 
