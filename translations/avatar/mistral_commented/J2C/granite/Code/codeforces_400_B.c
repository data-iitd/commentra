

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initializing variables for reading input
    int n, m;
    scanf("%d %d", &n, &m);

    // Creating an array of strings to store input strings
    char** arrs = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        arrs[i] = (char*)malloc(m * sizeof(char));
        scanf("%s", arrs[i]);
    }

    // Initializing an integer array to store the length of substrings between "G" and "S"
    int* length = (int*)malloc(n * sizeof(int));
    int index = 0; // Index for storing the current index in the length array
    int returnDex = -1; // Index for storing the index of the string with "G" before "S"

    // Iterating through each string in the array and finding the length of substrings between "G" and "S"
    for (int i = 0; i < n; i++) {
        char* tmp = arrs[i];
        char* dexG = strstr(tmp, "G"); // Finding the index of "G" in the current string
        char* dexS = strstr(tmp, "S"); // Finding the index of "S" in the current string

        // Checking if "G" comes before "S" in the current string
        if (dexG && dexS && dexG < dexS) {
            returnDex = i; // Storing the index of the string with "G" before "S"
            break; // Exiting the loop as we have found the required string
        }

        // Storing the length of the substring between "G" and "S" in the length array
        length[index++] = (int)(dexS - dexG);
    }

    // Creating a HashSet to store the unique lengths of substrings
    int* set = (int*)malloc(n * sizeof(int));
    int setSize = 0;

    // Iterating through the length array and adding each unique length to the HashSet
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < setSize; j++) {
            if (set[j] == length[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            set[setSize++] = length[i];
        }
    }

    // Checking if there is a string with "G" before "S"
    if (returnDex == -1) {
        // Printing the result if there is no such string
        printf("%d\n", returnDex);
    } else {
        // Printing the size of the HashSet if there is a string with "G" before "S"
        printf("%d\n", setSize);
    }

    // Freeing memory allocated for arrays and HashSet
    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);
    free(length);
    free(set);

    return 0;
}
