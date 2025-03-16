
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a sorted list
int binary_search(int key) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = ans_size;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (ans[mid][ans[mid].size - 1] < key) {
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

// Read the number of elements in the list
int N;
scanf("%d", &N);

// Initialize an empty list to store the elements
int **ans;
int ans_size = 0;

// Read each element and perform binary search to find its position in the list
for (int i = 0; i < N; i++) {
    // Read an element
    int A;
    scanf("%d", &A);

    // Perform binary search to find the index of the element
    int idx = binary_search(A);

    // If the element is not already in the list, append it to the list
    if (idx == ans_size) {
        ans = (int **)realloc(ans, sizeof(int *) * (ans_size + 1));
        ans[ans_size] = (int *)malloc(sizeof(int));
        ans[ans_size][0] = A;
        ans[ans_size][1] = 1;
        ans_size++;
    } else {
        // If the element is already in the list, append it to the existing list
        ans[idx][1]++;
    }
}

// Print the number of unique elements in the list
printf("%d\n", ans_size);

// Free the memory allocated for the list
for (int i = 0; i < ans_size; i++) {
    free(ans[i]);
}
free(ans);

// End of code
