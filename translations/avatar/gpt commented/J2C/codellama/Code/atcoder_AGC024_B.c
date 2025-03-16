#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int N; 
    scanf("%d", &N); 
    
    // Initialize an array to store the elements, adjusting for zero-based indexing
    int* P = (int*)malloc(N * sizeof(int)); 
    for (int i = 0; i < N; ++i) 
        scanf("%d", &P[i]); // Store input values after decrementing by 1
    
    // Create a map to store the index of each element for quick lookup
    int* map = (int*)malloc(N * sizeof(int)); 
    for (int i = 0; i < N; ++i) 
        map[i] = i; // Map each value to its index
    
    // List to store indices where the order is not increasing
    int* nglist = (int*)malloc(N * sizeof(int)); 
    int nglist_size = 0; 
    for (int i = 0; i < N - 1; ++i) 
        // Check if the current index is greater than the next index in the map
        if (map[i] > map[i + 1]) 
            nglist[nglist_size++] = i; // Add the index to the nglist if the order is violated
    
    // If there are no indices in nglist, print 0 and exit
    if (nglist_size == 0) { 
        printf("0\n"); 
        return 0; 
    } 
    
    // Calculate the minimum number of moves required to fix the order
    int ans = nglist[0] + 1 + N - nglist[nglist_size - 1] - 1; 
    for (int i = 0; i < nglist_size - 1; ++i) 
        // Update ans with the minimum moves needed between consecutive indices in nglist
        ans = min(ans, nglist[i] + 1 + N - nglist[i + 1] - 1); 
    
    // Print the result which is the minimum number of moves
    printf("%d\n", ans); 
    return 0; 
} 

