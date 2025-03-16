#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 200000
#define MAX_LINE_LENGTH 10000

// Function to read long lines
void ReadLongLines(int times, char lines[][MAX_LINE_LENGTH]) {
    for (int i = 0; i < times; i++) {
        fgets(lines[i], MAX_LINE_LENGTH, stdin);
        // Remove newline character if present
        lines[i][strcspn(lines[i], "\n")] = 0;
    }
}

// Function to print a list of integers
void PrintList(int *list, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%d", list[i]);
        } else {
            printf(" %d", list[i]);
        }
    }
    printf("\n");
}

int main() {
    char lines[4][MAX_LINE_LENGTH];
    ReadLongLines(4, lines);

    // Read the second line into a set
    int m[MAX_NUMBERS] = {0};
    char *token = strtok(lines[1], " ");
    while (token != NULL) {
        int n = atoi(token);
        m[n] = 1; // Mark the number as present
        token = strtok(NULL, " ");
    }

    // Process the fourth line
    int result[MAX_NUMBERS];
    int result_count = 0;
    token = strtok(lines[3], " ");
    while (token != NULL) {
        int n = atoi(token);
        if (m[n]) {
            m[n] = 0; // Remove from set
        } else {
            m[n] = 1; // Add to set
        }
        token = strtok(NULL, " ");
    }

    // Collect remaining numbers in the set
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (m[i]) {
            result[result_count++] = i;
        }
    }

    // Sort the result
    qsort(result, result_count, sizeof(int), (int (*)(const void *, const void *))compare);

    // Print the result
    PrintList(result, result_count);

    return 0;
}

// Comparison function for qsort
int compare(const int *a, const int *b) {
    return (*a - *b);
}

// Note: The above code assumes that the input numbers are within the range of 0 to MAX_NUMBERS-1
// and that the input format is correct as per the original Go code logic.
