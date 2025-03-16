#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

int main() { 
    // Create a Scanner object for input and PrintWriter for output
    int n; 
    scanf("%d", &n); 
    int ara[n]; 
    int i; 
    for (i = 0; i < n; i++) { 
        scanf("%d", &ara[i]); 
    } 
    
    // Initialize an array to store the elements
    int map[n]; 
    
    // Create a map to count the frequency of each element
    int max = 0; 
    for (i = 0; i < n; i++) { 
        if (map[ara[i]] == 0) { 
            map[ara[i]] = 1; 
        } else { 
            map[ara[i]]++; 
        } 
        max = max > map[ara[i]] ? max : map[ara[i]]; 
    } 
    
    // Find the maximum frequency among the elements
    int mm[n]; 
    
    // Iterate through the original array to find the first element with maximum frequency
    for (i = 0; i < n; i++) { 
        if (mm[ara[i]] == 0) { 
            mm[ara[i]] = 1; 
            if (mm[ara[i]] == max) { 
                printf("%d\n", ara[i]); 
                break; 
            } 
        } else { 
            mm[ara[i]]++; 
            if (mm[ara[i]] == max) { 
                printf("%d\n", ara[i]); 
                break; 
            } 
        } 
    } 
    
    return 0; 
} 

