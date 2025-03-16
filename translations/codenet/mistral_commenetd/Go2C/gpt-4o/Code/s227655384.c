#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 4
#define MAX_INTEGERS 200000

// Function to read long lines from standard input
int ReadLongLines(char lines[MAX_LINES][1000], int times) {
    for (int i = 0; i < times; i++) {
        if (fgets(lines[i], 1000, stdin) == NULL) {
            return i; // Return the number of lines read
        }
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
    // Initialize an array to store lines
    char lines[MAX_LINES][1000];
    // Read long lines from standard input
    int linesRead = ReadLongLines(lines, MAX_LINES);

    // Initialize a map to store unique integers
    int m[1000000] = {0}; // Assuming integers are in the range 0 to 999999
    int uniqueCount = 0;

    // Split the second line into integers
    char *token = strtok(lines[1], " \n");
    while (token != NULL) {
        int n = atoi(token);
        if (m[n] == 0) {
            m[n] = 1; // Mark as present
            uniqueCount++;
        }
        token = strtok(NULL, " \n");
    }

    // Read integers from the fourth line
    token = strtok(lines[3], " \n");
    while (token != NULL) {
        int n = atoi(token);
        if (m[n] == 0) {
            m[n] = 1; // Mark as present
            uniqueCount++;
        }
        token = strtok(NULL, " \n");
    }

    // Extract unique integers into a result array
    int result[MAX_INTEGERS];
    int resultIndex = 0;
    for (int i = 0; i < 1000000; i++) {
        if (m[i] == 1) {
            result[resultIndex++] = i;
        }
    }

    // Sort the result array
    for (int i = 0; i < resultIndex - 1; i++) {
        for (int j = i + 1; j < resultIndex; j++) {
            if (result[i] > result[j]) {
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    // Print the sorted unique integers
    PrintList(result, resultIndex);

    return 0;
}

// <END-OF-CODE>
