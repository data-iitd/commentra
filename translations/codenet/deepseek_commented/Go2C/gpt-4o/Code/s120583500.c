#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    char s[100]; // Step 1: The program starts by taking a string input from the user.
    scanf("%s", s);

    int count = 0; // Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
<<<<<<< HEAD
    int *counter = malloc(sizeof(int) * (strlen(s) + 1)); // Dynamic array to store counts
=======
    int *counter = malloc(sizeof(int) * (strlen(s) + 1)); // Allocate memory for counter
>>>>>>> 98c87cb78a (data updated)
    int index = 0;

    if (s[0] == '\0') { // Step 3: It checks if the input string is empty and returns immediately if it is.
        free(counter);
        return 0;
    }

    for (int i = 0; i < strlen(s); i++) { // Step 5: It iterates through each character in the string.
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            count++;
        } else {
            counter[index++] = count; // Store the count in the counter array
            count = 0; // Reset count for invalid characters
        }
    }

<<<<<<< HEAD
    counter[index++] = count; // Step 6: Append the final count to the counter array.

    // Sort the counter array
    qsort(counter, index, sizeof(int), compare);

    // Step 7: Finally, it prints the maximum value in the sorted counter array.
    printf("%d\n", counter[index - 1]);

    free(counter); // Free the allocated memory
=======
    counter[index++] = count; // Append the final count to the counter array

    qsort(counter, index, sizeof(int), compare); // Step 6: Sort the counter array

    printf("%d\n", counter[index - 1]); // Step 7: Print the maximum value in the sorted counter array

    free(counter); // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
    return 0;
}
