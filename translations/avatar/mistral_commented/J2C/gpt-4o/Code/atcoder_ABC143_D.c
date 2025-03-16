#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int find(int *arr, int size, int from, int target) {
    int low = from;
    int upp = size - 1;

    if (upp < low) {
        return 0;
    } else if (arr[from] >= target) {
        return 0;
    } else if (arr[upp] < target) {
        return upp - low + 1;
    }

    while (upp - low > 1) {
        int mid = (low + upp) / 2;
        if (arr[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
    }

    return low - from + 1;
}

int main() {
    int N;
    scanf("%d", &N); // Read the first integer N

    int *L = (int *)malloc(N * sizeof(int)); // Create an array of integers

    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]); // Read N integers into the array
    }

    qsort(L, N, sizeof(int), compare); // Sort the array using qsort

    int count = 0; // Initialize a counter variable to 0

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = L[i]; // Get the first integer of the pair
            int b = L[j]; // Get the second integer of the pair
            int res = find(L, N, j + 1, a + b); // Call the find() function
            count += res; // Add the result to the counter
        }
    }

    printf("%d\n", count); // Print the final count

    free(L); // Free the allocated memory
    return 0; // Return success
}

// <END-OF-CODE>
