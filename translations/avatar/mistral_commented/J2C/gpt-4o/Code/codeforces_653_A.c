#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements in the list

    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read the next input value
    }

    // Sort the array
    qsort(a, n, sizeof(int), compare);

    // Remove duplicates
    int *unique = (int *)malloc(n * sizeof(int));
    int unique_count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) { // Check for uniqueness
            unique[unique_count++] = a[i];
        }
    }

    // Check for three consecutive elements with a difference of 1
    bool found = false;
    for (int i = 0; i < unique_count - 2; i++) {
        if (unique[i] + 1 == unique[i + 1] && unique[i + 1] + 1 == unique[i + 2]) {
            found = true; // Set the found flag if a sequence is found
            break; // Exit the loop if a sequence is found
        }
    }

    // Write the output to the console
    printf(found ? "YES\n" : "NO\n");

    // Free allocated memory
    free(a);
    free(unique);

    return 0;
}
