#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Initialize variables for input
    int n; 
    int a[100000]; 
    int b[100000]; 
    int num[100000]; 
    
    // Read the number of elements
    scanf("%d", &n); 
    
    // Read values into array a
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]); 
    
    // Read values into array b
    for (int i = 0; i < n; i++) 
        scanf("%d", &b[i]); 
    
    // Count occurrences of each value in array b
    for (int i = 0; i < n; i++) 
        num[b[i]]++; 
    
    // Initialize variables for tracking the longest sequence and its representation
    char ss[100000]; 
    int ans = 0; 
    bool st[100000]; 
    
    // Iterate through each element to find the longest valid sequence
    for (int i = 0; i < n; i++) { 
        // Check if the current element in a is 1
        if (a[i] == 1) { 
            st[i] = true; // Mark this index as visited
            char sb[100000]; 
            int x = b[i]; // Start with the corresponding value in b
            char sss[100000]; 
            sprintf(sss, "%d", i); // Append the current index
            strcat(sb, sss); // Append to the sequence
            
            int s = 1; // Initialize the length of the current sequence
            
            // Continue to build the sequence while conditions are met
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) { 
                sss[0] = '\0'; 
                sprintf(sss, "%d", x); // Append the next index
                strcat(sb, sss); // Append to the sequence
                st[x] = true; // Mark this index as visited
                x = b[x]; // Move to the next index in b
                s++; // Increment the sequence length
            } 
            
            // Update the longest sequence found if the current one is longer
            if (s > ans) { 
                ans = s; 
                strcpy(ss, sb); // Store the longest sequence
            } 
        } 
    } 
    
    // Output the length of the longest sequence and the sequence itself
    printf("%d\n", ans); 
    printf("%s\n", ss); 
    
    return 0; 
} 
