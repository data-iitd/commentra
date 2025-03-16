
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int N;
    scanf("%d", &N);
    
    // Initialize an array to hold the input values
    int a[N];
    
    // Populate the array with input values
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    
    // Arrays to hold the counts of elements to the left and right of each element
    int leftl[N];
    int rightl[N];
    
    // Deque to help with calculating the left and right counts
    int que[N];
    int front = 0;
    int rear = -1;
    
    // Calculate the right counts for each element
    int index = 0;
    while (index < N) {
        // While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while (front <= rear && a[que[front]] > a[index]) {
            // Pop the index from the deque and calculate the right count
            int ind = que[front++];
            rightl[ind] = index - ind - 1;
        }
        // Push the current index onto the deque
        que[++rear] = index++;
    }
    
    // For any remaining indices in the deque, calculate the right counts
    while (front <= rear) {
        int ind = que[front++];
        rightl[ind] = N - ind - 1;
    }
    
    // Reset index to calculate left counts
    index = N - 1;
    
    // Calculate the left counts for each element
    while (index >= 0) {
        // While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while (front <= rear && a[que[front]] > a[index]) {
            // Pop the index from the deque and calculate the left count
            int ind = que[front++];
            leftl[ind] = ind - index - 1;
        }
        // Push the current index onto the deque
        que[++rear] = index--;
    }
    
    // For any remaining indices in the deque, calculate the left counts
    while (front <= rear) {
        int ind = que[front++];
        leftl[ind] = ind - index - 1;
    }
    
    // Calculate the final answer based on the left and right counts
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        // For each element, multiply its value by the number of valid subarrays it can form
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    
    // Output the final result
    printf("%ld\n", ans);
    
    return 0;
}
