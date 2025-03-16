#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100000

int main() {
    // Initialize variables
    int n;
    scanf("%d", &n);
    
    int a[MAX_N + 1];
    int b[MAX_N + 1];
    int num[MAX_N + 1] = {0}; // Initialize counts to 0
    bool st[MAX_N + 1] = {false}; // Initialize visited array to false
    
    // Read values into array a
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Read values into array b
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    
    // Count occurrences of each value in array b
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }
    
    // Initialize variables for tracking the longest sequence and its representation
    char ss[MAX_N * 2] = ""; // To store the longest sequence
    int ans = 0; // Length of the longest sequence
    
    // Iterate through each element to find the longest valid sequence
    for (int i = 1; i <= n; i++) {
        // Check if the current element in a is 1
        if (a[i] == 1) {
            st[i] = true; // Mark this index as visited
            char sb[MAX_N * 2] = ""; // String to build the current sequence
            int x = b[i]; // Start with the corresponding value in b
            char sss[20]; // Buffer to hold the current index as string
            sprintf(sss, "%d", i);
            strcat(sb, sss); // Append the current index
            
            // Continue to build the sequence while conditions are met
            int s = 1; // Initialize the length of the current sequence
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                sprintf(sss, "%d", x);
                strcat(sb, " "); // Add space before the next index
                strcat(sb, sss); // Append the next index
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
