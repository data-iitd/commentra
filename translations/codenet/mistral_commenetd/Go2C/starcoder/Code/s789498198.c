#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize scanner and read the first line
void init() {
	sc = (scanner){
		buf: malloc(sizeof(char*) * 0),
		cur: 0,
		r:   stdin,
	};
	sc.readln(); // Read the first line
}

// Main function
int main() {
	// Read the first two integers from the input
	int *AB = sc.nextInts();
	int A = AB[0];
	int B = AB[1];

	// Check if the sum of A and B is even
	if ((A + B) % 2 == 0) {
		// If it is, print the result (the average)
		printf("%d\n", (A + B) / 2);
		return 0;
	}
	// If the sum is odd, print "IMPOSSIBLE"
	printf("IMPOSSIBLE\n");
	return 0;
}

// scanner type definition
typedef struct {
	char **buf;
	int cur;
	FILE *r;
} scanner;

// Function to read a line
void readln() {
	char *rbuf = malloc(sizeof(char) * 0);
	for (int prefix = 1; prefix; ) {
		char *line = NULL;
		size_t len = 0;
		getline(&line, &len, sc.r);
		if (line == NULL) {
			free(rbuf);
			return;
		}
		rbuf = realloc(rbuf, sizeof(char) * (len + 1));
		strcpy(rbuf, line);
		free(line);
		if (rbuf[len - 1] == '\n') {
			rbuf[len - 1] = '\0';
			prefix = 0;
		}
	}
	sc.cur = 0;
	sc.buf = realloc(sc.buf, sizeof(char*) * (strlen(rbuf) + 1));
	sc.buf[0] = rbuf;
	for (int i = 1; i < strlen(rbuf) + 1; i++) {
		sc.buf[i] = sc.buf[i - 1] + 1;
	}
}

// Function to check if the scanner is full
int isFull() {
	if (sc.cur == strlen(sc.buf[0])) {
		return 1;
	}
	return 0;
}

// Function to reset the current index
void resetCur() {
	sc.cur = 0;
}

// Function to read next string
char *next() {
	if (sc.cur == 0) {
		readln();
	}
	char *res = sc.buf[sc.cur];
	sc.cur++;
	if (isFull()) {
		resetCur();
	}
	return res;
}

// Function to read next integers
int *nextInts() {
	readln();
	int *res = malloc(sizeof(int) * strlen(sc.buf[0]));
	for (int i = 0; i < strlen(sc.buf[0]); i++) {
		res[i] = atoi(sc.buf[0] + i);
	}
	resetCur();
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
	return x > y? x : y;
}

// Function to find the minimum of two integers
int min(int x, int y) {
	return x < y? x : y;
}

// Function to calculate the absolute value of an integer
int abs(int x) {
	return x < 0? -x : x;
}

// Function to print the values of variables
void varDump(int n,...) {
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		printf("%#v\n", va_arg(args, int));
	}
	va_end(args);
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
	Pair *v;
} Queue;

// Function to push a pair into the queue
void push(Queue *q, Pair v) {
	q->v = realloc(q->v, sizeof(Pair) * (q->cur + 1));
	q->v[q->cur] = v;
	q->cur++;
}

// Function to pop a pair from the queue
Pair pop(Queue *q) {
	Pair r = q->v[0];
	q->v = realloc(q->v, sizeof(Pair) * (q->cur - 1));
	q->cur--;
	return r;
}

// Function to get the front pair from the queue
Pair front(Queue q) {
	return q.v[0];
}

// Function to check if the queue is empty
int empty(Queue q) {
	return q.cur == 0;
}

