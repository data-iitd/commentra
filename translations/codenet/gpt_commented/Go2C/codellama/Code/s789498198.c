
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"unsafe"
)

func main() {
	// Read two integers from input
	AB := sc.nextInts()
	A := AB[0]
	B := AB[1]

	// Check if the sum of A and B is even
	if (A+B)%2 == 0 {
		// If even, print the average
		printf("%d\n", (A + B) / 2);
		return;
	}
	// If odd, print "IMPOSSIBLE"
	printf("IMPOSSIBLE\n");
}

// scanner struct to handle input reading
typedef struct {
	char **buf; // buffer to hold split input
	int cur; // current index in the buffer
	FILE *r; // reader for input
} scanner;

// Initialize a scanner for reading input
scanner sc;

// readln reads a line from input and splits it into words
void readln(scanner *s) {
	char *rbuf = malloc(sizeof(char) * 1000); // allocate memory for the buffer
	int i = 0;
	while (1) {
		char *line = fgets(rbuf, 1000, s->r); // read a line from input
		if (line == NULL) {
			printf("Error reading input\n");
			exit(1);
		}
		if (strchr(line, '\n') == NULL) {
			printf("Input line too long\n");
			exit(1);
		}
		if (strchr(line, '\n') != NULL) {
			*strchr(line, '\n') = '\0'; // remove newline character
		}
		s->buf[i] = strdup(line); // copy the line to the buffer
		i++;
		if (strchr(line, '\n') != NULL) {
			break; // exit loop if line is complete
		}
	}
	// Split the read line into words and store in buffer
	s->cur = 0;
}

// isFull checks if the buffer is fully read
int isFull(scanner *s) {
	return s->cur == 1000;
}

// resetCur resets the current index to zero
void resetCur(scanner *s) {
	s->cur = 0;
}

// next returns the next string from the buffer
char *next(scanner *s) {
	if (s->cur == 0) {
		readln(s); // read a new line if current index is zero
	}
	char *res = s->buf[s->cur];
	s->cur++;
	if (isFull(s)) {
		resetCur(s); // reset if buffer is full
	}
	return res;
}

// nexts returns all strings from the current line
char **nexts(scanner *s) {
	readln(s); // read a new line
	resetCur(s); // reset current index
	return s->buf; // return the buffer
}

// nextInt returns the next integer from the buffer
int nextInt(scanner *s) {
	if (s->cur == 0) {
		readln(s); // read a new line if current index is zero
	}
	int res = atoi(s->buf[s->cur]); // convert string to int
	s->cur++;
	if (isFull(s)) {
		resetCur(s); // reset if buffer is full
	}
	return res;
}

// nextInts returns all integers from the current line
int *nextInts(scanner *s) {
	readln(s); // read a new line
	int *res = malloc(sizeof(int) * 1000); // create a slice for integers
	for (int i = 0; i < 1000; i++) {
		res[i] = atoi(s->buf[i]); // convert each string to int
	}
	resetCur(s); // reset current index
	return res; // return the slice of integers
}

// nextFloat returns the next float from the buffer
float nextFloat(scanner *s) {
	if (s->cur == 0) {
		readln(s); // read a new line if current index is zero
	}
	float res = atof(s->buf[s->cur]); // convert string to float
	s->cur++;
	if (isFull(s)) {
		resetCur(s); // reset if buffer is full
	}
	return res;
}

// nextFloats returns all floats from the current line
float *nextFloats(scanner *s) {
	readln(s); // read a new line
	float *res = malloc(sizeof(float) * 1000); // create a slice for floats
	for (int i = 0; i < 1000; i++) {
		res[i] = atof(s->buf[i]); // convert each string to float
	}
	resetCur(s); // reset current index
	return res; // return the slice of floats
}

// digits returns the number of digits in an integer
int digits(int x) {
	return strlen(itoa(x)); // convert int to string and return length
}

// powInt calculates x raised to the power of p
int powInt(int x, int p) {
	int result = 1;
	for (int i = 0; i < p; i++) {
		result *= x; // multiply result by x, p times
	}
	return result;
}

// max returns the maximum of two integers
int max(int x, int y) {
	return (x > y) ? x : y; // use ternary operator for comparison
}

// min returns the minimum of two integers
int min(int x, int y) {
	return (x < y) ? x : y; // use ternary operator for comparison
}

// abs returns the absolute value of an integer
int abs(int x) {
	return (x < 0) ? -x : x; // use ternary operator for absolute value
}

// varDump prints the values of variables for debugging
void varDump(void *value) {
	printf("%s\n", value); // print each value to stderr
}

// yes prints "Yes" to the output
void yes() {
	printf("Yes\n");
}

// no prints "No" to the output
void no() {
	printf("No\n");
}

// Pair struct to hold a pair of integers
typedef struct {
	int first; // first element of the pair
	int second; // second element of the pair
} Pair;

// Queue struct to implement a queue of pairs
typedef struct {
	Pair *v; // slice to hold pairs
} Queue;

// Push adds a new pair to the queue
void Push(Queue *q, Pair v) {
	q->v = realloc(q->v, sizeof(Pair) * (q->v + 1)); // append the pair to the slice
	q->v[q->v] = v;
}

// Pop removes and returns the front pair from the queue
Pair Pop(Queue *q) {
	Pair r = q->v[0]; // get the front pair
	q->v = realloc(q->v, sizeof(Pair) * (q->v - 1)); // remove the front pair from the slice
	return r; // return the removed pair
}

// Front returns the front pair without removing it
Pair Front(Queue q) {
	return q.v[0]; // return the front pair
}

// Empty checks if the queue is empty
int Empty(Queue q) {
	return q.v == NULL; // return true if the slice is empty
}

