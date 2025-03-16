#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

// Function to compare two strings for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Main function to execute the program
int main() {
    // Variables to store N and L
    int N, L;

    // Read the number of strings N and the length L from the standard input
    scanf("%lld %lld", &N, &L);

    // Array to store strings
    char **v = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        v[i] = (char *)malloc((L + 1) * sizeof(char));
    }

    // Read N strings from the standard input and store them in the array v
    for (int i = 0; i < N; i++) {
        scanf("%s", v[i]);
    }

    // Sort the array v using qsort with custom comparator
    qsort(v, N, sizeof(char *), compare);

    // Concatenate and print the sorted strings without spaces
    for (int i = 0; i < N; i++) {
        printf("%s", v[i]);
        if (i < N - 1) {
            printf(""); // No space between strings
        }
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}
