#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a helper function to find the index of the last occurrence of an element
// in a list, and the index and value of the previous occurrence
int cut(int *array, int index, int *dp, int *dp_index) {
    // Base case: if index is less than 1, return an empty list
    if (index < 1) {
        return 0;
    }

    // Base case: if index is less than or equal to the first element in the array
    if (index <= array[0]) {
        dp[(*dp_index)++] = index;
        dp[(*dp_index)++] = array[0];
        return 2;
    }

    // Iterating through the array from the end to the beginning
    for (int i = 1; i < index; i++) {
        // If the previous element is smaller than the index, return the sublist up to that index
        if (array[i - 1] < index) {
            dp[(*dp_index)++] = array[i - 1];
            dp[(*dp_index)++] = array[i];
            return 2;
        }
    }

    return 0;
}

// Defining a helper function to check if it's possible to add a certain number of elements
// to the list while maintaining the condition that the previous element is smaller than the current one
int is_possible(int *array, int N, int K) {
    // Initializing an empty list to store the indices and values of the elements in the list
    int dp[N];
    int dp_index = 0;
    dp[dp_index++] = array[0];

    // Iterating through the list starting from the second element
    for (int i = 1; i < N; i++) {
        // If the current element is smaller than the last element in the dp list,
        // we need to cut the list at the previous index and add the current element
        if (array[i] <= dp[dp_index - 1]) {
            dp_index = cut(array, array[i], dp, &dp_index);
        }

        // Adding the current element to the dp list
        dp[dp_index++] = array[i];

        // Initializing a flag to check if we need to add an element to the dp list
        int is_added = 0;

        // Iterating through the dp list from the end to the beginning
        for (int j = dp_index - 1; j > 0; j--) {
            // If the previous element has a smaller value and enough space to add the current element,
            // we need to cut the list at the previous index and add the current element
            if (dp[j - 1] < K - 1) {
                dp_index = cut(array, dp[j - 1] - 1, dp, &dp_index);
                dp[dp_index++] = dp[j - 1] + 1;

                // Checking if the last element in the dp list is smaller than the current element
                if (dp[dp_index - 1] < array[i]) {
                    dp[dp_index++] = array[i];
                    is_added = 1;
                    break;
                }
            }
        }

        // If we didn't add an element to the dp list, the current number can't be added
        if (!is_added) {
            return 0;
        }
    }

    return 1;
}

// Defining a helper function to find the binary index of a number in the list
int bis(int *array, int N, int x, int y) {
    // Base case: if y is one more than x, return y
    if (y == x + 1) {
        return y;
    }

    // Recursively finding the binary index of x and y using the is_possible function
    if (is_possible(array, N, (x + y) / 2)) {
        return bis(array, N, x, (x + y) / 2);
    } else {
        return bis(array, N, (x + y) / 2, y);
    }
}

int main() {
    // Taking input from user and converting it into a list of integers
    char input[100000];
    scanf("%s", input);
    int A[100000];
    int N = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        A[N++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Adding the first element of the list to the beginning of the list
    // to make the first index 0 based instead of 1 based
    A[0] = A[0] + A[1];

    // Printing the result of the binary index function
    printf("%d\n", bis(A, N, 0, N));

    return 0;
}

