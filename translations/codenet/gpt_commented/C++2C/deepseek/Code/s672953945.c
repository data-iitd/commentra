#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

// Function to compare two strings for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, L;
    char **v;

    // Read the number of strings (N) and the length of strings (L)
    scanf("%d %d", &N, &L);

    // Allocate memory for the vector of strings
    v = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        v[i] = (char *)malloc((L + 1) * sizeof(char));
    }

    // Input N strings from the user and store them in the vector
    for (int i = 0; i < N; i++) {
        scanf("%s", v[i]);
    }

    // Sort the vector of strings in lexicographical order
    qsort(v, N, sizeof(char *), compare);

    // Output the sorted strings
    for (int i = 0; i < N; i++) {
        printf("%s", v[i]);
        if (i < N - 1) {
            printf(""); // Print a space between strings
        }
    }
    printf("\n"); // Print a newline at the end

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}
