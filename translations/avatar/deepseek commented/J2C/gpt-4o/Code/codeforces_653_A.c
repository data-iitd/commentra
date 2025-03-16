#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of integers

    int *a = (int *)malloc(n * sizeof(int)); // Create an array to store the integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read each integer value
    }

    // Remove duplicates
    int *unique = (int *)malloc(n * sizeof(int));
    int unique_count = 0;

    for (int i = 0; i < n; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < unique_count; j++) {
            if (a[i] == unique[j]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            unique[unique_count++] = a[i]; // Add the value to the unique list
        }
    }

    // Sort the unique array
    qsort(unique, unique_count, sizeof(int), compare);

    // Check for three consecutive integers
    int found = 0; // Initialize a flag to check for consecutive integers
    for (int i = 0; i < unique_count - 2; i++) {
        if (unique[i] + 1 == unique[i + 1] && unique[i + 1] + 1 == unique[i + 2]) {
            found = 1; // Set the flag if three consecutive integers are found
            break;
        }
    }

    printf(found ? "YES\n" : "NO\n"); // Print "YES" if consecutive integers are found, otherwise print "NO"

    free(a); // Free the allocated memory
    free(unique); // Free the allocated memory
    return 0;
}
