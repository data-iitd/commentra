#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100 // Define a maximum number of strings
#define MAX_LENGTH 100  // Define a maximum length for each string

int main() {
    int n, m; // Declare variables for number of strings and possibly unused variable
    scanf("%d %d", &n, &m); // Read the first two integer inputs

    char arrs[MAX_STRINGS][MAX_LENGTH]; // Declare a 2D array to store strings
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]); // Read each string and store it in the array
    }

    int length[MAX_STRINGS]; // Declare an array to store differences
    int index = 0; // Initialize index for the length array
    int returnDex = 0; // Initialize returnDex to store the result

    for (int i = 0; i < n; i++) { // Loop through each string in the array
        char *tmp = arrs[i]; // Get the current string
        char *dexG = strchr(tmp, 'G'); // Find the pointer to 'G' in the string
        char *dexS = strchr(tmp, 'S'); // Find the pointer to 'S' in the string

        if (dexG && dexS) { // Check if both 'G' and 'S' are found
            if (dexG > dexS) { // Check if 'G' comes after 'S'
                returnDex = -1; // Set returnDex to -1 if 'G' is after 'S'
            }
            length[index++] = (dexS - tmp) - (dexG - tmp); // Calculate and store the difference
        } else {
            length[index++] = 0; // If either 'G' or 'S' is not found, store 0
        }
    }

    int uniqueDifferences[MAX_STRINGS] = {0}; // Array to store unique differences
    int uniqueCount = 0; // Count of unique differences

    for (int i = 0; i < index; i++) { // Loop through each difference in the length array
        int found = 0; // Flag to check if the difference is already counted
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueDifferences[j] == length[i]) {
                found = 1; // Mark as found if the difference is already in the unique array
                break;
            }
        }
        if (!found) {
            uniqueDifferences[uniqueCount++] = length[i]; // Add to unique differences if not found
        }
    }

    if (returnDex == -1) { // Check if returnDex is -1
        printf("%d\n", returnDex); // Print -1 if 'G' comes after 'S'
    } else {
        printf("%d\n", uniqueCount); // Print the count of unique differences if 'G' does not come after 'S'
    }

    return 0; // Return success
}

// <END-OF-CODE>
