#include <stdio.h> // Including standard input-output library
#include <stdbool.h> // Including library for boolean type

// Function to perform depth-first search
bool dfs(int currpos, int arr[], int target, int n) {
    if (currpos == target) { // Base case: if the current position is the target position, return true
        return true;
    }
    if (currpos > n) { // Base case: if the current position is out of the array bounds, return false
        return false;
    }
    // Recursive call: try to teleport to the next position
    bool teleport = dfs(currpos + arr[currpos - 1], arr, target, n);
    if (teleport) { // If teleportation was successful, return true
        return true;
    }
    return false; // If teleportation was not successful, return false
}

int main() {
    int n, goal; // Variables for number of positions and target position
    scanf("%d", &n); // Reading the number of positions in the array
    scanf("%d", &goal); // Reading the target position
    int arr[n - 1]; // Creating an array of size n-1 to store the positions of the teleportals
    for (int i = 0; i < n - 1; i++) { // Reading the positions of the teleportals from the standard input
        scanf("%d", &arr[i]);
    }
    // Calling the depth-first search function with the initial position and the target position
    bool isFound = dfs(1, arr, goal, n);
    if (isFound) { // If the target position was found, print "YES"
        printf("YES\n");
    } else { // If the target position was not found, print "NO"
        printf("NO\n");
    }
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
