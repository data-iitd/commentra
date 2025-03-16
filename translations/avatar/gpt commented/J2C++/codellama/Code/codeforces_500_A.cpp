
#include <iostream> 
#include <vector> 

using namespace std; 

// Depth-first search (DFS) method to determine if the target can be reached
bool dfs(int currpos, vector<int> arr, int target) { 
    // Base case: if the current position equals the target, return true
    if (currpos == target) 
        return true; 
    
    // Base case: if the current position exceeds the bounds of the array, return false
    if (currpos == arr.size() + 1) 
        return false; 
    
    // Recursive case: attempt to teleport to the next position based on the current array value
    bool teleport = dfs(currpos + arr[currpos - 1], arr, target); 
    
    // If teleporting leads to the target, return true
    if (teleport) 
        return true; 
    
    // If no valid path found, return false
    return false; 
} 

int main() { 
    // Read the number of positions (n) and the target position (goal)
    int n, goal; 
    cin >> n >> goal; 
    
    // Initialize a vector to hold the teleportation values
    vector<int> arr(n - 1); 
    
    // Populate the vector with teleportation values from input
    for (int i = 0; i < n - 1; i++) 
        cin >> arr[i]; 
    
    // Call the DFS function starting from position 1 to check if the goal can be reached
    bool isFound = dfs(1, arr, goal); 
    
    // Output the result based on whether the goal was found
    if (isFound) 
        cout << "YES" << endl; 
    else 
        cout << "NO" << endl; 
    
    return 0; 
} 

