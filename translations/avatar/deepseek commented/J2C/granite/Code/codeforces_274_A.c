
#include <stdio.h> // Step 1: Include necessary headers
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, k; // Step 2: Declare variables
    scanf("%d %d", &n, &k); // Step 3: Read input values
    int *arr = (int*)malloc(n * sizeof(int)); // Step 3: Read input values
    bool *visited = (bool*)malloc(n * sizeof(bool)); // Step 3: Read input values

    for (int i = 0; i < n; i++) { // Step 4: Read array elements
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare); // Step 5: Sort the array

    int count = 0; // Step 6: Initialize count variable

    for (int i = 0; i < n; i++) { // Step 7: Iterate through the array
        if (arr[i] % k!= 0) { // Check if the element is not divisible by k
            count++; // Increment the count
            visited[i] = true; // Mark the element as visited
        } else if (!visited[i / k]) { // Check if the quotient is not visited
            count++; // Increment the count
            visited[i] = true; // Mark the element as visited
        }
    }

    printf("%d\n", count); // Step 8: Print the result

    free(arr); // Step 9: Free memory
    free(visited); // Step 9: Free memory

    return 0;
}

int compare(const void *a, const void *b) { // Step 10: Define comparison function
    return (*(int*)a - *(int*)b);
}

