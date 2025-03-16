#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Define a maximum size for the list

// Function to perform binary search on a sorted list of arrays
int binary_search(int key, int ans[][MAX_SIZE], int size) {
    int bad = -1, good = size;

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the last element of the middle array is less than the key
        if (ans[mid][0] < key) {
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
    int N;
    scanf("%d", &N); // Read the number of elements in the list

    int ans[MAX_SIZE][MAX_SIZE]; // Initialize an array to store the elements
    int sizes[MAX_SIZE] = {0}; // Array to keep track of sizes of each subarray
    int unique_count = 0; // Count of unique elements

    // Read each element and perform binary search to find its position in the list
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A); // Read an element

        // Perform binary search to find the index of the element
        int idx = binary_search(A, ans, unique_count);

        // If the element is not already in the list, append it to the list
        if (idx == unique_count) {
            ans[unique_count][0] = A; // Store the new element
            sizes[unique_count] = 1; // Initialize the size of this subarray
            unique_count++; // Increment the count of unique elements
        } else {
            // If the element is already in the list, append it to the existing list
            ans[idx][sizes[idx]] = A; // Append the element to the existing subarray
            sizes[idx]++; // Increment the size of this subarray
        }
    }

    // Print the number of unique elements in the list
    printf("%d\n", unique_count);

    return 0;
}

// <END-OF-CODE>
