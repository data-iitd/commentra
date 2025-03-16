#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} ArrayDeque;

ArrayDeque* createDeque(int capacity) {
    ArrayDeque *deque = (ArrayDeque *)malloc(sizeof(ArrayDeque));
    deque->capacity = capacity;
    deque->front = -1;
    deque->rear = -1;
    deque->data = (int *)malloc(capacity * sizeof(int));
    return deque;
}

int isEmpty(ArrayDeque *deque) {
    return deque->front == -1;
}

void push(ArrayDeque *deque, int value) {
    if (deque->rear == deque->capacity - 1) {
        return; // Deque is full
    }
    if (isEmpty(deque)) {
        deque->front = 0;
    }
    deque->data[++deque->rear] = value;
}

int pop(ArrayDeque *deque) {
    if (isEmpty(deque)) {
        return -1; // Deque is empty
    }
    int value = deque->data[deque->front++];
    if (deque->front > deque->rear) {
        deque->front = deque->rear = -1; // Reset deque
    }
    return value;
}

void freeDeque(ArrayDeque *deque) {
    free(deque->data);
    free(deque);
}

int main() {
    // Create a Scanner object to read input from the console
    int N;
    scanf("%d", &N);
    
    // Initialize an array to hold the input values
    int *a = (int *)malloc(N * sizeof(int));
    
    // Populate the array with input values
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    
    // Arrays to hold the counts of elements to the left and right of each element
    int *leftl = (int *)calloc(N, sizeof(int));
    int *rightl = (int *)calloc(N, sizeof(int));
    
    // Deque to help with calculating the left and right counts
    ArrayDeque *que = createDeque(N);
    
    // Calculate the right counts for each element
    int index = 0;
    while (index < N) {
        while (!isEmpty(que) && a[que->data[que->front]] > a[index]) {
            int ind = pop(que);
            rightl[ind] = index - ind - 1;
        }
        push(que, index++);
    }
    
    // For any remaining indices in the deque, calculate the right counts
    while (!isEmpty(que)) {
        int ind = pop(que);
        rightl[ind] = N - ind - 1;
    }
    
    // Reset index to calculate left counts
    index = N - 1;
    
    // Calculate the left counts for each element
    while (index >= 0) {
        while (!isEmpty(que) && a[que->data[que->front]] > a[index]) {
            int ind = pop(que);
            leftl[ind] = ind - index - 1;
        }
        push(que, index--);
    }
    
    // For any remaining indices in the deque, calculate the left counts
    while (!isEmpty(que)) {
        int ind = pop(que);
        leftl[ind] = ind - index - 1;
    }
    
    // Calculate the final answer based on the left and right counts
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    
    // Output the final result
    printf("%lld\n", ans);
    
    // Free allocated memory
    free(a);
    free(leftl);
    free(rightl);
    freeDeque(que);
    
    return 0;
}

// <END-OF-CODE>
