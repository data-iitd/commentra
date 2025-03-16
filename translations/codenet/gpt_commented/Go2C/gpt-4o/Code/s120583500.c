#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Declare a variable to hold the input string
    char s[1000]; // Assuming a maximum length of 999 characters + 1 for null terminator
    // Read input from the user
    scanf("%s", s);

    // Initialize a counter for consecutive valid characters and a dynamic array to hold counts
    int count = 0;
    int *counter = malloc(sizeof(int)); // Start with a dynamic array
    int counterSize = 0;

    // If the input string is empty, exit the function
    if (s[0] == '\0') {
        free(counter);
        return 0;
    }

    // Iterate over each character in the string
    for (int i = 0; i < strlen(s); i++) {
        // Check if the character is one of the valid DNA bases
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            // Increment the count for consecutive valid characters
            count++;
        } else {
            // If an invalid character is encountered, store the current count
            counter = realloc(counter, (counterSize + 1) * sizeof(int));
            counter[counterSize] = count;
            counterSize++;
            // Reset the count for the next sequence
            count = 0;
        }
    }

    // Append the count of the last sequence of valid characters
    counter = realloc(counter, (counterSize + 1) * sizeof(int));
    counter[counterSize] = count;
    counterSize++;

    // Sort the counts to find the maximum consecutive valid characters
    qsort(counter, counterSize, sizeof(int), compare);
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    // Print the maximum count of consecutive valid characters
    printf("%d\n", counter[counterSize - 1]);

    // Free the allocated memory
    free(counter);
    return 0;
}
<<<<<<< HEAD

// <END-OF-CODE>
=======
>>>>>>> 98c87cb78a (data updated)
