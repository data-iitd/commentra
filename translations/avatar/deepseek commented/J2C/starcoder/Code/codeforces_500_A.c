#include <stdio.h>
#include <stdlib.h>

int dfs(int currpos, int *arr, int target) {
    // Depth-first search method to find if the target position can be reached
    if (currpos == target) return 1; // If current position is the target, return true
    if (currpos == arr[0] + 1) return 0; // If current position exceeds array length, return false

    int teleport = dfs(currpos + arr[currpos - 1], arr, target); // Recursive call with teleported position
    if (teleport) return 1; // If teleportation leads to the target, return true
    return 0; // Otherwise, return false
}

int main() {
    // Main method where the program execution begins
    int n, goal;
    scanf("%d %d", &n, &goal); // Reading the number of elements in the array and the target position
    int *arr = (int *) malloc(sizeof(int) * (n - 1)); // Initializing the array with n-1 elements

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]); // Reading the array elements
    }

    int isFound = dfs(1, arr, goal); // Calling the dfs method with initial position 1
    if (isFound) printf("YES"); // If the target position is found, print "YES"
    else printf("NO"); // Otherwise, print "NO"

    return 0;
}

