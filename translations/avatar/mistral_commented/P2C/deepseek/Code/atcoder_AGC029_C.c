#include <stdio.h>
#include <stdlib.h>

// Helper function to find the index of the last occurrence of an element
// in a list, and the index and value of the previous occurrence
int* cut(int* array, int index, int* size) {
    // Base case: if index is less than 1, return an empty list
    if (index < 1) {
        return NULL;
    }

    // Base case: if index is less than or equal to the first element in the array
    if (index <= array[0]) {
        return array;
    }

    // Iterating through the array from the end to the beginning
    for (int i = *size - 1; i > 0; i--) {
        // If the previous element is smaller than the index, return the sublist up to that index
        if (array[i - 1] < index) {
            int* new_array = (int*)malloc((i + 1) * sizeof(int));
            for (int j = 0; j < i; j++) {
                new_array[j] = array[j];
            }
            new_array[i] = index;
            *size = i + 1;
            return new_array;
        }
    }
    return NULL;
}

// Helper function to check if it's possible to add a certain number of elements
// to the list while maintaining the condition that the previous element is smaller than the current one
int is_possible(int* A, int N, int K) {
    // Initializing an empty list to store the indices and values of the elements in the list
    int* dp = (int*)malloc(sizeof(int));
    dp[0] = A[0];
    int size = 1;

    // Iterating through the list starting from the second element
    for (int i = 1; i < N; i++) {
        // If the current element is smaller than the last element in the dp list,
        // we need to cut the list at the previous index and add the current element
        if (A[i] <= dp[size - 1]) {
            int* new_dp = cut(dp, A[i], &size);
            free(dp);
            dp = new_dp;
        }

        // Adding the current element to the dp list
        int* new_dp = (int*)malloc((size + 1) * sizeof(int));
        for (int j = 0; j < size; j++) {
            new_dp[j] = dp[j];
        }
        new_dp[size] = A[i];
        size++;
        free(dp);
        dp = new_dp;

        // Initializing a flag to check if we need to add an element to the dp list
        int is_added = 0;

        // Iterating through the dp list from the end to the beginning
        for (int j = size - 1; j >= 0; j--) {
            // If the previous element has a smaller value and enough space to add the current element,
            // we need to cut the list at the previous index and add the current element
            if (dp[j] < K - 1) {
                int* new_dp = cut(dp, dp[j] - 1, &size);
                free(dp);
                dp = new_dp;
                dp = (int*)realloc(dp, (size + 1) * sizeof(int));
                dp[size - 1] = dp[j];
                dp[j] = dp[size - 1] - 1;
                size++;
                is_added = 1;
                break;
            }
        }

        // If we didn't add an element to the dp list, the current number can't be added
        if (!is_added) {
            free(dp);
            return 0;
        }
    }
    free(dp);
    return 1;
}

// Helper function to find the binary index of a number in the list
int bis(int x, int y, int* A, int N) {
    // Base case: if y is one more than x, return y
    if (y == x + 1) {
        return y;
    }

    // Recursively finding the binary index of x and y using the is_possible function
    if (is_possible(A, N, (x + y) / 2)) {
        return bis(x, (x + y) / 2, A, N);
    } else {
        return bis((x + y) / 2, y, A, N);
    }
}

int main() {
    // Reading input from user and converting it into a list of integers
    int N;
    scanf("%d", &N);
    int* A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Printing the result of the binary index function
    printf("%d\n", bis(0, N, A, N));

    free(A);
    return 0;
}
