#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b;
}

int main() {
    // Initialize an empty string variable 's' to store the input DNA sequence
    char s[1000]; // Assuming a maximum length of 999 characters + 1 for null terminator

    // Read the input DNA sequence from the standard input
    scanf("%s", s);

    // Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T)
    int count = 0;
    int *counter = malloc(sizeof(int)); // Dynamic array to store counts
    int counterSize = 0;

    // Check if the input DNA sequence is empty or not
    if (s[0] == '\0') {
        // If the input DNA sequence is empty, return without doing anything
        free(counter);
        return 0;
    }

    // Iterate through each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the current character is a valid nucleotide (A, C, G, T)
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            // If valid, increment the count
            count++;
        } else {
            // If not valid, append the current count to the counter array
            counter = realloc(counter, (counterSize + 1) * sizeof(int));
            counter[counterSize++] = count;
            count = 0; // Reset count
        }
    }

    // Append the final count of nucleotides in the last sub-sequence to the counter array
    counter = realloc(counter, (counterSize + 1) * sizeof(int));
    counter[counterSize++] = count;

    // Sort the counter array in ascending order
    qsort(counter, counterSize, sizeof(int), compare);

    // Print the last element of the sorted counter array, which represents the maximum count
    printf("%d\n", counter[counterSize - 1]);

    // Free the allocated memory
    free(counter);

    return 0;
}

// <END-OF-CODE>
