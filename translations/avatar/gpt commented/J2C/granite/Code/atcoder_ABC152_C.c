
#include <stdio.h>
#include <stdlib.h>
#include <queue>

int main() {
    // Call the solve method and print the result
    printf("%d\n", solve());
    return 0;
}

int solve() {
    // Initialize an array to hold the input values
    int arr[N];

    // Populate the array with user input
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize a variable to keep track of the count of elements
    int sum = 0;

    // Create a priority queue to manage the elements
    std::priority_queue<int> q;

    // Iterate through the array to process each element
    for (int i = 0; i < N; i++) {
        // Add the current element to the priority queue
        q.push(arr[i]);

        // Check if the current element is less than or equal to the smallest element in the queue
        if (arr[i] <= q.top()) {
            // Increment the count if the condition is met
            sum++;
        }
    }

    // Return the final count of elements that met the condition
    return sum;
}

