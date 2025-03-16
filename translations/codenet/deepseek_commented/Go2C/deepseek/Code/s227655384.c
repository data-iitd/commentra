#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read multiple lines of input from stdin.
char** readLongLines(int times) {
    char** result = (char**)malloc(times * sizeof(char*));
    for (int i = 0; i < times; i++) {
        result[i] = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
        if (fgets(result[i], MAX_LINE_LENGTH, stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
    }
    return result;
}

// Function to print a list of integers separated by spaces.
void printList(int* list, int size) {
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
    // Create a map to store unique elements.
    int m[200000] = {0};
    int mSize = 0;

    // Read the lines of input.
    char** lines = readLongLines(4);

    // Split the second line into individual elements and add them to the map.
    char* secondLine = lines[1];
    char* token = strtok(secondLine, " ");
    while (token != NULL) {
        int n = atoi(token);
        int found = 0;
        for (int i = 0; i < mSize; i++) {
            if (m[i] == n) {
                found = 1;
                break;
            }
        }
        if (!found) {
            m[mSize++] = n;
        }
        token = strtok(NULL, " ");
    }

    // Process the fourth line to toggle the presence of elements in the map.
    char* fourthLine = lines[3];
    token = strtok(fourthLine, " ");
    while (token != NULL) {
        int n = atoi(token);
        int found = 0;
        for (int i = 0; i < mSize; i++) {
            if (m[i] == n) {
                found = 1;
                m[i] = 0; // Mark as removed
                break;
            }
        }
        if (!found) {
            m[mSize++] = n;
        }
        token = strtok(NULL, " ");
    }

    // Sort the unique elements.
    for (int i = 0; i < mSize - 1; i++) {
        for (int j = i + 1; j < mSize; j++) {
            if (m[i] > m[j]) {
                int temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }

    // Print the sorted list of unique elements.
    for (int i = 0; i < mSize; i++) {
        if (m[i] != 0) {
            printf("%d\n", m[i]);
        }
    }

    // Free allocated memory.
    for (int i = 0; i < 4; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
