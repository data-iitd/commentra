#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main() {
    // Read the number of strings (n) and the number of queries (m)
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Initialize an array to store the strings
    char arrs[MAX_STRINGS][MAX_LENGTH];
    
    // Read n strings from the input
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }
    
    // Initialize an array to store the lengths of segments between 'G' and 'S'
    int length[MAX_STRINGS];
    int index = 0;
    int returnDex = 0;
    
    // Iterate through each string to find the indices of 'G' and 'S'
    for (int i = 0; i < n; i++) {
        char *tmp = arrs[i];
        char *dexG = strchr(tmp, 'G'); // Find the pointer to 'G'
        char *dexS = strchr(tmp, 'S'); // Find the pointer to 'S'
        
        // If 'G' or 'S' is not found, set lengths accordingly
        if (dexG == NULL || dexS == NULL) {
            length[index++] = -1; // Indicate that one of them is missing
            continue;
        }
        
        // If 'G' appears after 'S', set returnDex to -1
        if (dexG > dexS) {
            returnDex = -1;
        }
        
        // Calculate the length between 'G' and 'S' and store it in the length array
        length[index++] = dexS - dexG;
    }
    
    // Use a dynamic array to store unique lengths
    int *set = (int *)malloc(n * sizeof(int));
    int setSize = 0;
    
    // Add each length to the array to ensure uniqueness
    for (int i = 0; i < index; i++) {
        int len = length[i];
        int isUnique = 1;
        
        // Check if the length is already in the set
        for (int j = 0; j < setSize; j++) {
            if (set[j] == len) {
                isUnique = 0;
                break;
            }
        }
        
        // If it's unique, add it to the set
        if (isUnique) {
            set[setSize++] = len;
        }
    }
    
    // Check if returnDex was set to -1 and print the appropriate result
    if (returnDex == -1) {
        printf("%d\n", returnDex); // Print -1 if 'G' is after 'S' in any string
    } else {
        printf("%d\n", setSize); // Print the number of unique lengths
    }
    
    // Free the allocated memory
    free(set);
    
    return 0;
}
