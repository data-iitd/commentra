#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} ArrayDeque;

// Function to create a new ArrayDeque
ArrayDeque* createDeque(int capacity) {
    ArrayDeque* deque = (ArrayDeque*)malloc(sizeof(ArrayDeque));
    deque->capacity = capacity;
    deque->front = -1;
    deque->rear = -1;
    deque->data = (int*)malloc(capacity * sizeof(int));
    return deque;
}

// Function to check if the deque is empty
int isEmpty(ArrayDeque* deque) {
    return deque->front == -1;
}

// Function to push an element to the front of the deque
void push(ArrayDeque* deque, int value) {
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->data[deque->rear] = value;
}

// Function to pop an element from the front of the deque
int pop(ArrayDeque* deque) {
    if (isEmpty(deque)) {
        return -1; // Deque is empty
    }
    int value = deque->data[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front++;
    }
    return value;
}

// Function to free the deque
void freeDeque(ArrayDeque* deque) {
    free(deque->data);
    free(deque);
}

int main() {
    int N;
    scanf("%d", &N); // Reading the number of elements in the array
    int* a = (int*)malloc(N * sizeof(int)); // Creating an integer array of size N

    // Reading the elements of the array
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    int* leftl = (int*)malloc(N * sizeof(int)); // Array for left segment lengths
    int* rightl = (int*)malloc(N * sizeof(int)); // Array for right segment lengths
    ArrayDeque* que = createDeque(N); // Creating a deque
    int index = 0; // Index variable

    // Finding the length of the right segments
    while (index < N) {
        while (!isEmpty(que) && a[que->data[que->rear]] > a[index]) {
            int ind = pop(que);
            rightl[ind] = index - ind - 1;
        }
        push(que, index++);
    }

    // Calculating the length of the right segment for the last elements
    while (!isEmpty(que)) {
        int ind = pop(que);
        rightl[ind] = N - ind - 1;
    }

    index = N - 1; // Traversing the array in reverse order

    // Finding the length of the left segments
    while (index >= 0) {
        while (!isEmpty(que) && a[que->data[que->rear]] > a[index]) {
            int ind = pop(que);
            leftl[ind] = ind - index - 1;
        }
        push(que, index--);
    }

    // Calculating the length of the left segment for the first elements
    while (!isEmpty(que)) {
        int ind = pop(que);
        leftl[ind] = ind - index - 1;
    }

    long long ans = 0; // Variable to store the final answer

    // Calculating the answer
    for (int i = 0; i < N; ++i) {
        ans += (long long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }

    // Printing the final answer
    printf("%lld\n", ans);

    // Freeing allocated memory
    free(a);
    free(leftl);
    free(rightl);
    freeDeque(que);

    return 0;
}

// <END-OF-CODE>
