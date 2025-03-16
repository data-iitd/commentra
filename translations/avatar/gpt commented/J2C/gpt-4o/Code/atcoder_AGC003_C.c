#include <stdio.h>
#include <stdlib.h>

#define NUM (int)(1e5 + 2)

// Structure for a priority queue node
typedef struct {
    int value;
    int index;
} Node;

// Comparator function for the priority queue
int compare(const void *a, const void *b) {
    return ((Node *)a)->value - ((Node *)b)->value;
}

int main() {
    // Create an array to store the numbers and their indices
    Node nums[NUM];
    int N;

    // Read the number of elements
    scanf("%d", &N);

    // Read N numbers from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i].value); // Read the next number
        nums[i].index = i; // Store the index of the number
    }

    // Sort the array of numbers based on their values
    qsort(nums, N, sizeof(Node), compare);

    // Initialize variables to track the binary state and the difference count
    int bin = 0;
    int diff = 0;

    // Process the numbers in sorted order
    for (int i = 0; i < N; i++) {
        int idx = nums[i].index; // Get the original index of the number

        // Check if the parity of the current index and the binary state differ
        if ((bin % 2) != (idx % 2)) {
            diff++; // Increment the difference count if they differ
        }

        // Update the binary state
        bin++;
        bin %= 2; // Toggle between 0 and 1
    }

    // Calculate the final answer as half of the difference count
    int ans = (diff / 2);

    // Output the result
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
