#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to read integers from input
void readInts(int *A, int *B) {
    scanf("%d %d", A, B);
}

// Function to calculate the average of two integers
int average(int A, int B) {
    return (A + B) / 2;
}

// Main function
int main() {
    int A, B;
    
    // Read the first two integers from the input
    readInts(&A, &B);

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If it is, print the result (the average)
        printf("%d\n", average(A, B));
    } else {
        // If the sum is odd, print "IMPOSSIBLE"
        printf("IMPOSSIBLE\n");
    }

    return 0;
}

// Utility functions (not used in this specific example but included for completeness)
int digits(int x) {
    return (int)log10(x) + 1;
}

int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

int absInt(int x) {
    return (x < 0) ? -x : x;
}

void varDump(int value) {
    fprintf(stderr, "%d\n", value);
}

void yes() {
    printf("Yes\n");
}

void no() {
    printf("No\n");
}

// Pair structure definition
typedef struct {
    int first;
    int second;
} Pair;

// Queue structure definition
typedef struct {
    Pair *v;
    int size;
    int capacity;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q, int capacity) {
    q->v = (Pair *)malloc(capacity * sizeof(Pair));
    q->size = 0;
    q->capacity = capacity;
}

// Function to push a pair into the queue
void push(Queue *q, Pair v) {
    if (q->size < q->capacity) {
        q->v[q->size++] = v;
    }
}

// Function to pop a pair from the queue
Pair pop(Queue *q) {
    Pair r = q->v[0];
    for (int i = 1; i < q->size; i++) {
        q->v[i - 1] = q->v[i];
    }
    q->size--;
    return r;
}

// Function to get the front pair from the queue
Pair front(Queue *q) {
    return q->v[0];
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Function to free the queue
void freeQueue(Queue *q) {
    free(q->v);
}

// Note: The queue functions are included for completeness but are not used in this specific example.

