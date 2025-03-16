
#include <stdio.h> // Including stdio.h for input/output operations
#include <stdlib.h> // Including stdlib.h for memory allocation and deallocation
#include <limits.h> // Including limits.h for INT_MAX

int main() {
    // Initialize variables
    int N; // Number of elements in the array
    int *arr; // Pointer to an integer array
    int sum = 0; // Variable to store the sum of elements smaller than or equal to the current element
    int i; // Loop variable

    // Read the number of elements in the array
    scanf("%d", &N);

    // Allocate memory for the array
    arr = (int*)malloc(N * sizeof(int));

    // Read and store elements in the array
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Use a priority queue to store the elements
    int *q = (int*)malloc(N * sizeof(int));
    int front = 0; // Variable to keep track of the front of the queue
    int rear = -1; // Variable to keep track of the rear of the queue

    // Iterate through the array
    for (i = 0; i < N; i++) {
        // Add the current element to the queue
        rear++;
        q[rear] = arr[i];

        // Check if the current element is smaller than or equal to the top element of the queue
        while (front <= rear && q[front] < arr[i]) {
            sum++; // Increment the sum if the condition is true
            front++; // Move the front of the queue to the next element
        }
    }

    // Free the memory allocated for the array and the queue
    free(arr);
    free(q);

    // Print the sum as the solution
    printf("%d\n", sum);

    // Return 0 to indicate successful execution
    return 0;
}

