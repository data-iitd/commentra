#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a string token
char* n() {
    char *line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

// Function to read an integer
int ni() {
    char *line = n();
    int result = atoi(line);
    free(line);
    return result;
}

// Main method to start the program
int main() {
    // Read input: number of elements n and the number of summands k
    int n = ni();
    int k = ni();

    // Read input array a of size n
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        a[i] = ni(); // Read next element of array a
    }

    // Sort the array a using qsort()
    qsort(a, n, sizeof(int), (int (*)(const void*, const void*))compare);

    // Calculate the answer: sum of first k elements of sorted array a
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }

    // Write the answer to the output stream
    printf("%d\n", ans);

    // Free allocated memory
    free(a);

    return 0;
}

// Comparison function for qsort()
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
