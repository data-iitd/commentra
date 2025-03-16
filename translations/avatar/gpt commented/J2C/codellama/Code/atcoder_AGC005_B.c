#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Create a Scanner object to read input from the console
    int N;
    scanf("%d", &N);
    
    // Initialize an array to hold the input values
    int* a = (int*) malloc(N * sizeof(int));
    
    // Populate the array with input values
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    
    // Arrays to hold the counts of elements to the left and right of each element
    int* leftl = (int*) malloc(N * sizeof(int));
    int* rightl = (int*) malloc(N * sizeof(int));
    
    // Deque to help with calculating the left and right counts
    int* que = (int*) malloc(N * sizeof(int));
    int front = 0;
    int rear = 0;
    
    // Calculate the right counts for each element
    int index = 0;
    while (index < N) {
        // While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while (!(front == rear) && a[que[front]] > a[index]) {
            // Pop the index from the deque and calculate the right count
            int ind = que[front];
            rightl[ind] = index - ind - 1;
            front = (front + 1) % N;
        }
        // Push the current index onto the deque
        que[rear] = index++;
        rear = (rear + 1) % N;
    }
    
    // For any remaining indices in the deque, calculate the right counts
    while (front != rear) {
        int ind = que[front];
        rightl[ind] = N - ind - 1;
        front = (front + 1) % N;
    }
    
    // Reset index to calculate left counts
    index = N - 1;
    
    // Calculate the left counts for each element
    while (index >= 0) {
        // While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while (!(front == rear) && a[que[front]] > a[index]) {
            // Pop the index from the deque and calculate the left count
            int ind = que[front];
            leftl[ind] = ind - index - 1;
            front = (front + 1) % N;
        }
        // Push the current index onto the deque
        que[rear] = index--;
        rear = (rear + 1) % N;
    }
    
    // For any remaining indices in the deque, calculate the left counts
    while (front != rear) {
        int ind = que[front];
        leftl[ind] = ind - index - 1;
        front = (front + 1) % N;
    }
    
    // Calculate the final answer based on the left and right counts
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        // For each element, multiply its value by the number of valid subarrays it can form
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    
    // Output the final result
    printf("%ld\n", ans);
    
    // Free memory
    free(a);
    free(leftl);
    free(rightl);
    free(que);
    
    return 0;
}

