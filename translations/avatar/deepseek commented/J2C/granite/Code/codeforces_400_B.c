

#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library for memory allocation
#include <string.h> // Include string library for string manipulation

int main() {
    int n, m; // Declare and initialize variables for number of strings and possibly not used variable
    scanf("%d %d", &n, &m); // Read the first and second integer inputs

    char** arrs = (char**)malloc(n * sizeof(char*)); // Allocate memory for array of strings
    for (int i = 0; i < n; i++) {
        arrs[i] = (char*)malloc(m * sizeof(char)); // Allocate memory for each string in the array
        scanf("%s", arrs[i]); // Read each string and store it in the array
    }

    int* length = (int*)malloc(n * sizeof(int)); // Allocate memory for array to store differences
    int index = 0; // Initialize index for the length array
    int returnDex = 0; // Initialize returnDex to store the result

    for (int i = 0; i < n; i++) { // Loop through each string in the array
        char* tmp = arrs[i]; // Store the current string in a temporary variable
        char* g = strchr(tmp, 'G'); // Find the index of 'G' in the string
        char* s = strchr(tmp, 'S'); // Find the index of 'S' in the string
        if (g > s) { // Check if 'G' comes after 'S'
            returnDex = -1; // Set returnDex to -1 if 'G' is after 'S'
        }
        length[index++] = s - g; // Calculate and store the difference in length array
    }

    int* set = (int*)malloc(n * sizeof(int)); // Allocate memory for array to store unique differences
    int setSize = 0; // Initialize setSize to store the size of the HashSet
    for (int i = 0; i < n; i++) { // Loop through each difference in the length array
        int found = 0; // Initialize found to 0 to check if the difference is already in the set
        for (int j = 0; j < setSize; j++) { // Loop through each element in the set
            if (length[i] == set[j]) { // Check if the difference is already in the set
                found = 1; // Set found to 1 if the difference is already in the set
                break; // Exit the loop if the difference is already in the set
            }
        }
        if (!found) { // Check if the difference is not already in the set
            set[setSize++] = length[i]; // Add the difference to the set if it is not already in the set
        }
    }

    if (returnDex == -1) { // Check if returnDex is -1
        printf("%d\n", returnDex); // Print -1 if 'G' comes after 'S'
    } else {
        printf("%d\n", setSize); // Print the size of the set if 'G' does not come after 'S'
    }

    for (int i = 0; i < n; i++) { // Loop through each string in the array
        free(arrs[i]); // Free the memory allocated for each string in the array
    }
    free(arrs); // Free the memory allocated for the array of strings
    free(length); // Free the memory allocated for the length array
    free(set); // Free the memory allocated for the set

    return 0; // Return 0 to indicate successful execution
}

