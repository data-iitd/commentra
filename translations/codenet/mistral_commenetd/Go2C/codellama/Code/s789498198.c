#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initialize scanner and read the first line
void init() {
	sc.buf = (char**)malloc(sizeof(char*) * 0);
	sc.cur = 0;
	sc.r = fopen("input.txt", "r");
	sc.readln(); // Read the first line
}

// Main function
void main() {
	// Read the first two integers from the input
	int* AB = sc.nextInts();
	int A = AB[0];
	int B = AB[1];

	// Check if the sum of A and B is even
	if ((A+B)%2 == 0) {
		// If it is, print the result (the average)
		printf("%d\n", (A + B) / 2);
		return;
	}
	// If the sum is odd, print "IMPOSSIBLE"
	printf("IMPOSSIBLE\n");
}

// scanner type definition
typedef struct {
	char** buf;
	int cur;
	FILE* r;
} scanner;

// Function to read a line
void readln(scanner* s) {
	char* rbuf = (char*)malloc(sizeof(char) * 0);
	for (;;) {
		char* line = (char*)malloc(sizeof(char) * 0);
		int prefix = fscanf(s->r, "%[^\n]", line);
		rbuf = (char*)realloc(rbuf, sizeof(char) * (strlen(rbuf) + strlen(line) + 1));
		strcat(rbuf, line);
		if (prefix == 0) {
			break;
		}
	}
	s->cur = 0;
	s->buf = (char**)realloc(s->buf, sizeof(char*) * (strlen(rbuf) + 1));
	s->buf[0] = (char*)malloc(sizeof(char) * (strlen(rbuf) + 1));
	strcpy(s->buf[0], rbuf);
	free(rbuf);
}

// Function to check if the scanner is full
int isFull(scanner* s) {
	if (s->cur == strlen(s->buf[0])) {
		return 1;
	}
	return 0;
}

// Function to reset the current index
void resetCur(scanner* s) {
	s->cur = 0;
}

// Function to read next string
char* next(scanner* s) {
	if (s->cur == 0) {
		readln(s);
	}
	char* res = (char*)malloc(sizeof(char) * (strlen(s->buf[0]) + 1));
	strcpy(res, s->buf[0] + s->cur);
	s->cur += strlen(res) + 1;
	if (isFull(s)) {
		resetCur(s);
	}
	return res;
}

// Function to read next integers
int* nextInts(scanner* s) {
	readln(s);
	int* res = (int*)malloc(sizeof(int) * (strlen(s->buf[0]) + 1));
	int i = 0;
	char* p = strtok(s->buf[0], " ");
	while (p != NULL) {
		res[i] = atoi(p);
		i++;
		p = strtok(NULL, " ");
	}
	resetCur(s);
	return res;
}

// Function to calculate the number of digits in an integer
int digits(int x) {
	return (int)log10(x) + 1;
}

// Function to calculate the power of a number
int powInt(int x, int p) {
	int result = 1;
	for (int i = 0; i < p; i++) {
		result *= x;
	}
	return result;
}

// Function to find the maximum of two integers
int max(int x, int y) {
	return (x > y) ? x : y;
}

// Function to find the minimum of two integers
int min(int x, int y) {
	return (x < y) ? x : y;
}

// Function to calculate the absolute value of an integer
int abs(int x) {
	return (x < 0) ? -x : x;
}

// Function to print the values of variables
void varDump(int value) {
	printf("%d\n", value);
}

// Function to print "Yes"
void yes() {
	printf("Yes\n");
}

// Function to print "No"
void no() {
	printf("No\n");
}

// Pair type definition
typedef struct {
	int first;
	int second;
} Pair;

// Queue type definition
typedef struct {
	Pair* v;
} Queue;

// Function to push a pair into the queue
void Push(Queue* q, Pair v) {
	q->v = (Pair*)realloc(q->v, sizeof(Pair) * (q->v + 1));
	q->v[q->v + 1] = v;
}

// Function to pop a pair from the queue
Pair Pop(Queue* q) {
	Pair r = q->v[0];
	q->v = (Pair*)realloc(q->v, sizeof(Pair) * (q->v - 1));
	return r;
}

// Function to get the front pair from the queue
Pair Front(Queue q) {
	return q.v[0];
}

// Function to check if the queue is empty
int Empty(Queue q) {
	return (q.v == NULL);
}

