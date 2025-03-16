#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 4
#define MAX_INTS 200000
#define BUFFER_SIZE 1024

// Function to read long lines from standard input
int ReadLongLines(char lines[MAX_LINES][BUFFER_SIZE], int times) {
    for (int i = 0; i < times; i++) {
        if (fgets(lines[i], BUFFER_SIZE, stdin) == NULL) {
            return i; // Return the number of lines read
        }
        // Remove newline character if present
        lines[i][strcspn(lines[i], "\n")] = 0;
    }
    return times; // Return the total number of lines read
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
    char lines[MAX_LINES][BUFFER_SIZE]; // Array to hold the lines read
    int uniqueInts[MAX_INTS]; // Array to hold unique integers
    int uniqueCount = 0; // Count of unique integers
    int tempInt;

    // Read 4 lines from input
    ReadLongLines(lines, MAX_LINES);

    // Process the second line
    char *token = strtok(lines[1], " ");
    while (token != NULL) {
        tempInt = atoi(token); // Convert string to integer
        // Add to unique integers if not already present
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueInts[j] == tempInt) {
                found = 1;
                break;
            }
        }
        if (!found) {
            uniqueInts[uniqueCount++] = tempInt; // Add to the array
        }
        token = strtok(NULL, " ");
    }

    // Process the fourth line
    token = strtok(lines[3], " ");
    while (token != NULL) {
        tempInt = atoi(token); // Convert string to integer
        // Check if it exists in the unique integers
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueInts[j] == tempInt) {
                found = 1;
                // Remove it from the unique integers
                uniqueInts[j] = uniqueInts[--uniqueCount]; // Replace with last element
                break;
            }
        }
        if (!found) {
            // Add to unique integers if not found
            uniqueInts[uniqueCount++] = tempInt;
        }
        token = strtok(NULL, " ");
    }

    // Sort the unique integers
    qsort(uniqueInts, uniqueCount, sizeof(int), (int (*)(const void *, const void *))compare);

    // Print the sorted result
    PrintList(uniqueInts, uniqueCount);

    return 0;
}

// Comparison function for qsort
int compare(const int *a, const int *b) {
    return (*a - *b);
}
