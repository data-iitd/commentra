
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare a variable to hold the input string
    char s[100];
    // Read input from the user
    scanf("%s", s);

    // Initialize a counter for consecutive valid characters and a slice to hold counts
    int count = 0;
    int *counter = (int *)malloc(sizeof(int));

    // If the input string is empty, exit the function
    if (strlen(s) == 0) {
        return 0;
    }

    // Start the counter with an initial value of 0
    counter[0] = 0;
    // Split the input string into a slice of individual characters
    char *li = (char *)malloc(strlen(s) * sizeof(char));
    strcpy(li, s);

    // Iterate over each character in the slice
    for (int i = 0; i < strlen(li); i++) {
        // Check if the character is one of the valid DNA bases
        if (li[i] == 'A' || li[i] == 'C' || li[i] == 'G' || li[i] == 'T') {
            // Increment the count for consecutive valid characters
            count++;
        } else {
            // If an invalid character is encountered, store the current count
            counter = (int *)realloc(counter, (count + 1) * sizeof(int));
            counter[count] = count;
            // Reset the count for the next sequence
            count = 0;
        }
    }

    // Append the count of the last sequence of valid characters
    counter = (int *)realloc(counter, (count + 1) * sizeof(int));
    counter[count] = count;
    // Sort the counts to find the maximum consecutive valid characters
    qsort(counter, count + 1, sizeof(int), compare);
    // Print the maximum count of consecutive valid characters
    printf("%d\n", counter[count]);

    // Free the allocated memory
    free(counter);
    free(li);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

