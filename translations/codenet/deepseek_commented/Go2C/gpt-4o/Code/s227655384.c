#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 4
#define MAX_NUMBERS 200000
#define BUFFER_SIZE 1024

// Function to read multiple lines of input
void ReadLongLines(char lines[MAX_LINES][BUFFER_SIZE]) {
    for (int i = 0; i < MAX_LINES; i++) {
        if (fgets(lines[i], BUFFER_SIZE, stdin) == NULL) {
            break;
        }
        // Remove newline character if present
        lines[i][strcspn(lines[i], "\n")] = 0;
    }
}

// Function to print a list of integers
void PrintList(int *list, int size) {
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", list[i]);
    }
    printf("\n");
}

int main() {
<<<<<<< HEAD
    // Create a map to store unique elements
    int m[MAX_NUMBERS] = {0}; // Using an array to simulate a set
    char lines[MAX_LINES][BUFFER_SIZE];
    ReadLongLines(lines);

=======
    char lines[MAX_LINES][BUFFER_SIZE];
    ReadLongLines(lines);

    // Create a map to store unique elements
    int m[MAX_NUMBERS] = {0}; // Using an array to simulate a set
    int result[MAX_NUMBERS];
    int resultSize = 0;

>>>>>>> 98c87cb78a (data updated)
    // Split the second line into individual elements and add them to the map
    char *token = strtok(lines[1], " ");
    while (token != NULL) {
        int n = atoi(token);
        m[n] = 1; // Mark presence
        token = strtok(NULL, " ");
    }

    // Process the fourth line to toggle the presence of elements in the map
    token = strtok(lines[3], " ");
    while (token != NULL) {
        int n = atoi(token);
        if (m[n]) {
            m[n] = 0; // Remove presence
        } else {
            m[n] = 1; // Add presence
        }
        token = strtok(NULL, " ");
    }

    // Extract the unique elements from the map
<<<<<<< HEAD
    int result[MAX_NUMBERS];
    int resultSize = 0;
=======
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (m[i]) {
            result[resultSize++] = i;
        }
    }

<<<<<<< HEAD
    // Sort the result
=======
    // Sort the result array
>>>>>>> 98c87cb78a (data updated)
    qsort(result, resultSize, sizeof(int), (int (*)(const void *, const void *))compare);

    // Print the sorted list of unique elements
    PrintList(result, resultSize);

    return 0;
}

// Comparison function for qsort
int compare(const int *a, const int *b) {
<<<<<<< HEAD
    return (*a - *b);
=======
    return (*a > *b) - (*a < *b);
>>>>>>> 98c87cb78a (data updated)
}
