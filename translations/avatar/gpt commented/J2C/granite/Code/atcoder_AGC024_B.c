
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int N; 
    scanf("%d", &N); // Read the number of elements
    
    // Initialize an array to store the elements, adjusting for zero-based indexing
    int P[N]; 
    for (int i = 0; i < N; ++i) { 
        scanf("%d", &P[i]); // Store input values after decrementing by 1
        P[i]--; 
    }
    
    // Create a map to store the index of each element for quick lookup
    int map[N]; 
    memset(map, -1, sizeof(map)); 
    for (int i = 0; i < N; ++i) 
        map[P[i]] = i; // Map each value to its index
    
    // List to store indices where the order is not increasing
    int nglist[N]; 
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
    int ans = nglist[0] + 1; 
    for (int i = 1; i < nglist_size; ++i) 
        // Update ans with the minimum moves needed between consecutive indices in nglist
        ans = nglist[i] + 1 < ans? nglist[i] + 1 : ans; 
    ans = N - nglist[nglist_size - 1] < ans? N - nglist[nglist_size - 1] : ans; 
    
    // Print the result which is the minimum number of moves
    printf("%d\n", ans); 
    
    return 0; 
}
