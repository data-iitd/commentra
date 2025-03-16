#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a sorted list
int binary_search(int key, int *arr, int size) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = size;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (arr[mid] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

int main() {
    // Read the number of elements in the list
    int N;
    scanf("%d", &N);

    // Initialize an empty list to store the elements
    int *ans = (int *)malloc(N * sizeof(int));
    int ans_size = 0;

    // Read each element and perform binary search to find its position in the list
    for (int i = 0; i < N; i++) {
        // Read an element
        int A;
        scanf("%d", &A);

        // Perform binary search to find the index of the element
        int idx = binary_search(A, ans, ans_size);

        // If the element is not already in the list, append it to the list
        if (idx == ans_size) {
            ans[ans_size++] = A;
        }
    }

    // Print the number of unique elements in the list
    printf("%d\n", ans_size);

    // Free the allocated memory
    free(ans);

    return 0;
}
