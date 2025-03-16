#include <stdio.h>   // Including standard input-output library
#include <stdlib.h>  // Including standard library for dynamic memory allocation
#include <string.h>  // Including string library for string manipulation
#include <stdbool.h> // Including library for boolean type
#include <limits.h>  // Including limits library for INT_MAX

#define MAX_STRINGS 100 // Defining a maximum number of strings

int main() {
    // Initializing variables for reading input
    int n, m;
    scanf("%d %d", &n, &m); // Reading the first two integers from the input

    // Creating an array of strings to store input strings
    char arrs[MAX_STRINGS][100]; // Assuming each string can be up to 99 characters long
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]); // Reading a string from the input
    }

    // Initializing an array to store the length of substrings between "G" and "S"
    int length[MAX_STRINGS];
    int index = 0; // Index for storing the current index in the length array
    int returnDex = -1; // Index for storing the index of the string with "G" before "S"

    // Iterating through each string in the array and finding the length of substrings between "G" and "S"
    for (int i = 0; i < n; i++) {
        char *tmp = arrs[i];
        char *dexG = strchr(tmp, 'G'); // Finding the pointer to "G" in the current string
        char *dexS = strchr(tmp, 'S'); // Finding the pointer to "S" in the current string

        // Checking if "G" comes before "S" in the current string
        if (dexG != NULL && dexS != NULL && dexG < dexS) {
            length[index++] = dexS - dexG; // Storing the length of the substring between "G" and "S"
        } else if (dexG != NULL && dexS != NULL) {
            returnDex = i; // Storing the index of the string with "G" before "S"
            break; // Exiting the loop as we have found the required string
        }
    }

    // Creating an array to store unique lengths
    bool uniqueLengths[MAX_STRINGS] = {false}; // Boolean array to track unique lengths
    int uniqueCount = 0; // Counter for unique lengths

    // Iterating through the length array and counting unique lengths
    for (int i = 0; i < index; i++) {
        if (length[i] >= 0 && length[i] < MAX_STRINGS && !uniqueLengths[length[i]]) {
            uniqueLengths[length[i]] = true; // Marking this length as seen
            uniqueCount++; // Incrementing the count of unique lengths
        }
    }

    // Checking if there is a string with "G" before "S"
    if (returnDex == -1) {
        // Printing the result if there is no such string
        printf("%d\n", returnDex);
    } else {
        // Printing the count of unique lengths if there is a string with "G" before "S"
        printf("%d\n", uniqueCount);
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
