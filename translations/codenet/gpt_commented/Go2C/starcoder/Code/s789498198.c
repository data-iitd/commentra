

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold a pair of integers
typedef struct {
	int first;
	int second;
} Pair;

// Define a struct to implement a queue of pairs
typedef struct {
	Pair *v;
	int size;
	int front;
	int rear;
} Queue;

// Initialize a queue
Queue *initQueue(int size) {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->v = (Pair *)malloc(sizeof(Pair) * size);
	q->size = size;
	q->front = 0;
	q->rear = 0;
	return q;
}

// Add a new pair to the queue
void push(Queue *q, Pair v) {
	q->v[q->rear] = v;
	q->rear = (q->rear + 1) % q->size;
}

// Remove and return the front pair from the queue
Pair pop(Queue *q) {
	Pair r = q->v[q->front];
	q->front = (q->front + 1) % q->size;
	return r;
}

// Return the front pair without removing it
Pair front(Queue *q) {
	return q->v[q->front];
}

// Check if the queue is empty
int isEmpty(Queue *q) {
	return q->front == q->rear;
}

// Define a struct to hold input data
typedef struct {
	int A;
	int B;
} Input;

// Read input from stdin
Input *readInput() {
	Input *i = (Input *)malloc(sizeof(Input));
	scanf("%d %d", &i->A, &i->B);
	return i;
}

// Print output to stdout
void printOutput(int result) {
	printf("%d\n", result);
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average of A and B
int average(int A, int B) {
	return (A + B) / 2;
}

// Check if the sum of A and B is even
int isEven(int A, int B) {
	return (A + B) % 2 == 0;
}

// Check if the sum of A and B is odd
int isOdd(int A, int B) {
	return (A + B) % 2 == 1;
}

// Calculate the average