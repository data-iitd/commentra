
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned int capacity;
    int* array;
};

// Function to create a stack of given capacity. It initializes size of stack as 0
struct Stack* createStack(unsigned int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the top item from stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// Function to calculate the length of the left segment for each element
void calculateLeftLength(int* a, int* leftl, int N) {
    struct Stack* stack = createStack(N);
    int index = 0;
    while (index < N) {
        while (!isEmpty(stack) && a[peek(stack)] > a[index]) {
            int ind = pop(stack);
            leftl[ind] = index - ind - 1;
        }
        push(stack, index++);
    }
    while (!isEmpty(stack)) {
        int ind = pop(stack);
        leftl[ind] = ind - index - 1;
    }
}

// Function to calculate the length of the right segment for each element
void calculateRightLength(int* a, int* rightl, int N) {
    struct Stack* stack = createStack(N);
    int index = N - 1;
    while (index >= 0) {
        while (!isEmpty(stack) && a[peek(stack)] > a[index]) {
            int ind = pop(stack);
            rightl[ind] = index - ind - 1;
        }
        push(stack, index--);
    }
    while (!isEmpty(stack)) {
        int ind = pop(stack);
        rightl[ind] = index - ind - 1;
    }
}

// Function to calculate the final answer
long calculateAnswer(int* a, int* leftl, int* rightl, int N) {
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    return ans;
}

// Driver function to test the above functions
int main() {
    int N;
    scanf("%d", &N);
    int* a = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    int* leftl = (int*) malloc(N * sizeof(int));
    int* rightl = (int*) malloc(N * sizeof(int));
    calculateLeftLength(a, leftl, N);
    calculateRightLength(a, rightl, N);
    long ans = calculateAnswer(a, leftl, rightl, N);
    printf("%ld\n", ans);
    return 0;
}

