#include <stdio.h>
#include <stdbool.h>

// Depth-first search (DFS) method to determine if the target can be reached
bool dfs(int currpos, int arr[], int target, int n) {
    // Base case: if the current position equals the target, return true
    if (currpos == target) 
        return true; 
    
    // Base case: if the current position exceeds the bounds of the array, return false
    if (currpos > n) 
        return false; 
    
    // Recursive case: attempt to teleport to the next position based on the current array value
    bool teleport = dfs(currpos + arr[currpos - 1], arr, target, n); 
    
    // If teleporting leads to the target, return true
    if (teleport) 
        return true; 
    
    // If no valid path found, return false
    return false; 
}

int main() {
    // Read the number of positions (n) and the target position (goal)
    int n, goal;
    scanf("%d %d", &n, &goal);
    
    // Initialize an array to hold the teleportation values
    int arr[n - 1];
    
    // Populate the array with teleportation values from input
    for (int i = 0; i < n - 1; i++) 
        scanf("%d", &arr[i]);
    
    // Call the DFS function starting from position 1 to check if the goal can be reached
    bool isFound = dfs(1, arr, goal, n);
    
    // Output the result based on whether the goal was found
    if (isFound) 
        printf("YES\n"); 
    else 
        printf("NO\n"); 
    
    return 0;
}

// <END-OF-CODE>
