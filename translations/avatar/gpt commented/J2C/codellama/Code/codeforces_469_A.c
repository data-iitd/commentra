#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int n, levels, level2, level3, count, j; 
    int sum = 0, sum2 = 0, sum3 = 0; 
    int *arr, *arr2, *arr3; 
    scanf("%d %d", &n, &levels); 
    
    // Read the number of players (n) and the number of levels (levels)
    arr = (int *)malloc(levels * sizeof(int)); 
    for (int i = 0; i < levels; i++) { 
        scanf("%d", &arr[i]); 
    } 
    
    // Read the number of additional levels completed by the second player
    scanf("%d", &level2); 
    
    // Calculate the total number of levels completed by both players
    level3 = levels + level2; 
    
    // Create a new array to store levels completed by both players
    arr2 = (int *)malloc(level3 * sizeof(int)); 
    
    // Copy levels from the first player's array to the new array
    for (int i = 0; i < levels; i++) { 
        arr2[i] = arr[i]; 
    } 
    
    // Read the levels completed by the second player and add them to the new array
    for (int i = levels; i < level3; i++) { 
        scanf("%d", &arr2[i]); 
    } 
    
    // Create an array to represent all levels (1 to n)
    arr3 = (int *)malloc(n * sizeof(int)); 
    j = 0; 
    
    // Fill arr3 with level numbers from 1 to n
    for (int i = 0; i < n; i++) { 
        arr3[i] = ++j; 
    } 
    
    // Check how many levels from arr3 are completed by either player
    for (int i = 0; i < n; i++) { 
        for (int x = 0; x < level3; x++) { 
            // If a level is found in arr2, increment the count and break
            if (arr3[i] == arr2[x]) { 
                count++; 
                break; 
            } 
        } 
    } 
    
    // Determine if all levels have been completed by at least one player
    if (count == n) { 
        printf("I become the guy.\n"); 
    } else { 
        printf("Oh, my keyboard!\n"); 
    } 
    return 0; 
}
