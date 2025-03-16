#include <stdio.h>
#include <stdbool.h>

bool dfs(int currpos, int arr[], int target) {
    // Depth-first search method to find if the target position can be reached
    if (currpos == target) return true; // If current position is the target, return true
    if (currpos == sizeof(arr) + 1) return false; // If current position exceeds array length, return false

    bool teleport = dfs(currpos + arr[currpos - 1], arr, target); // Recursive call with teleported position
    if (teleport) return true; // If teleportation leads to the target, return true
    return false; // Otherwise, return false
}

int main() {
    // Main method where the program execution begins
    int n, goal; // Declaring variables for the number of elements in the array and the target position
    scanf("%d %d", &n, &goal); // Reading the number of elements in the array and the target position
    int arr[n - 1]; // Initializing the array with n-1 elements

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]); // Reading the array elements
    }

    bool isFound = dfs(1, arr, goal); // Calling the dfs method with initial position 1
    if (isFound) printf("YES\n"); // If the target position is found, print "YES"
    else printf("NO\n"); // Otherwise, print "NO"

    return 0;
}

