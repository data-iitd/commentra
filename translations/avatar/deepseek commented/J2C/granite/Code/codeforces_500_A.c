
#include <stdio.h> // Include necessary header files
#include <stdbool.h>

bool dfs(int currpos, int arr[], int target, int n) {
    // Depth-first search method to find if the target position can be reached
    if (currpos == target) return true; // If current position is the target, return true
    if (currpos == n + 1) return false; // If current position exceeds array length, return false

    bool teleport = dfs(currpos + arr[currpos - 1], arr, target, n); // Recursive call with teleported position
    if (teleport) return true; // If teleportation leads to the target, return true
    return false; // Otherwise, return false
}

int main() {
    // Main method where the program execution begins
    int n, goal; // Declaring variables for number of elements, target position, and array
    scanf("%d %d", &n, &goal); // Reading the number of elements and target position from input

    int arr[n - 1]; // Initializing the array with n-1 elements
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]); // Reading the array elements from input
    }

    bool isFound = dfs(1, arr, goal, n); // Calling the dfs method with initial position 1
    if (isFound) printf("YES\n"); // If the target position is found, print "YES"
    else printf("NO\n"); // Otherwise, print "NO"

    return 0; // Returning 0 to indicate successful program execution
}

