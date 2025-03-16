#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} ArrayDeque;

// Function to create a deque
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

// Function to peek the front element of the deque
int peek(ArrayDeque* deque) {
    if (isEmpty(deque)) {
        return -1; // Deque is empty
    }
    return deque->data[deque->front];
}

// Function to free the deque
void freeDeque(ArrayDeque* deque) {
    free(deque->data);
    free(deque);
}

int main() {
    int N;
    scanf("%d", &N); // Reading the number of elements N
    int* a = (int*)malloc(N * sizeof(int)); // Initializing the array a with size N

    // Reading N elements and storing them in the array a
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    // Initializing arrays to store the distances to the nearest smaller elements
    int* leftl = (int*)malloc(N * sizeof(int));
    int* rightl = (int*)malloc(N * sizeof(int));

    // Using a deque to find the nearest smaller element to the right
    ArrayDeque* que = createDeque(N);
    int index = 0;
    while (index < N) {
        while (!isEmpty(que) && a[peek(que)] > a[index]) {
            int ind = pop(que);
            rightl[ind] = index - ind - 1; // Calculating the distance
        }
        push(que, index++); // Adding the current index to the deque
    }
    while (!isEmpty(que)) {
        int ind = pop(que);
        rightl[ind] = N - ind - 1; // Calculating the distance for remaining elements
    }

    // Using a deque to find the nearest smaller element to the left
    index = N - 1;
    while (index >= 0) {
        while (!isEmpty(que) && a[peek(que)] > a[index]) {
            int ind = pop(que);
            leftl[ind] = ind - index - 1; // Calculating the distance
        }
        push(que, index--); // Adding the current index to the deque
    }
    while (!isEmpty(que)) {
        int ind = pop(que);
        leftl[ind] = ind - index - 1; // Calculating the distance for remaining elements
    }

    // Calculating the result by summing up the products
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }

    // Printing the result
    printf("%lld\n", ans);

    // Free allocated memory
    free(a);
    free(leftl);
    free(rightl);
    freeDeque(que);

    return 0;
}

// <END-OF-CODE>
