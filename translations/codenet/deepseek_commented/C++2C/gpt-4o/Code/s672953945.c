#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1000
#define MAX_LENGTH 100

// Function to compare two strings for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Main function to execute the program
int main() {
    // Array to store strings and variables to store N and L
    char v[MAX_STRINGS][MAX_LENGTH];
    int N, L;

    // Read the number of strings N and the length L from the standard input
    scanf("%d %d", &N, &L);

    // Read N strings from the standard input and store them in the array v
    for (int i = 0; i < N; i++) {
        scanf("%s", v[i]);
    }

    // Sort the array v in lexicographical order
    qsort(v, N, sizeof(v[0]), compare);

    // Concatenate and print the sorted strings without spaces
    for (int i = 0; i < N; i++) {
        printf("%s", v[i]);
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
