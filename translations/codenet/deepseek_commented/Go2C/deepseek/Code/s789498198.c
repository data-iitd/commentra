#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read a line of input and split it into tokens
void readln(char ***buf, int *cur, FILE *r) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    if ((read = getline(&line, &len, r)) != -1) {
        char *line_copy = strdup(line);
        *buf = str_split(line_copy, " ");
        *cur = 0;
        free(line);
    }
}

// Function to check if the current cursor position is beyond the buffer length
int isFull(char **buf, int cur) {
    return cur == strlen(buf);
}

// Function to reset the cursor position to the beginning of the buffer
void resetCur(int *cur) {
    *cur = 0;
}

// Function to get the next token from the buffer
char* next(char ***buf, int *cur, FILE *r) {
    if (*cur == 0) {
        readln(buf, cur, r);
    }
    char* res = (*buf)[*cur];
    (*cur)++;
    if (isFull(*buf, *cur)) {
        resetCur(cur);
    }
    return res;
}

// Function to get all remaining tokens as a slice of strings
char** nexts(char ***buf, int *cur, FILE *r) {
    readln(buf, cur, r);
    resetCur(cur);
    return *buf;
}

// Function to get the next token as an integer
int nextInt(char ***buf, int *cur, FILE *r) {
    if (*cur == 0) {
        readln(buf, cur, r);
    }
    int res = atoi((*buf)[*cur]);
    (*cur)++;
    if (isFull(*buf, *cur)) {
        resetCur(cur);
    }
    return res;
}

// Function to get all remaining tokens as a slice of integers
int* nextInts(char ***buf, int *cur, FILE *r) {
    readln(buf, cur, r);
    int n = strlen(*buf);
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = atoi((*buf)[i]);
    }
    resetCur(cur);
    return res;
}

// Function to get the next token as a float
double nextFloat(char ***buf, int *cur, FILE *r) {
    if (*cur == 0) {
        readln(buf, cur, r);
    }
    double res = atof((*buf)[*cur]);
    (*cur)++;
    if (isFull(*buf, *cur)) {
        resetCur(cur);
    }
    return res;
}

// Function to get all remaining tokens as a slice of floats
double* nextFloats(char ***buf, int *cur, FILE *r) {
    readln(buf, cur, r);
    int n = strlen(*buf);
    double* res = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        res[i] = atof((*buf)[i]);
    }
    resetCur(cur);
    return res;
}

// Function to calculate the number of digits in an integer
int digits(int x) {
    char str[20];
    sprintf(str, "%d", x);
    return strlen(str);
}

// Function to calculate x raised to the power of p
int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

// Function to return the maximum of two integers
int max(int x, int y) {
    return x > y ? x : y;
}

// Function to return the minimum of two integers
int min(int x, int y) {
    return x < y ? x : y;
}

// Function to return the absolute value of an integer
int abs(int x) {
    return x < 0 ? -x : x;
}

// Function to print the variable in a debug-friendly format
void varDump(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        int v = va_arg(args, int);
        printf("%#v\n", v);
    }
    va_end(args);
}

// Function to print "Yes" to standard output
void yes() {
    printf("Yes\n");
}

// Function to print "No" to standard output
void no() {
    printf("No\n");
}

// Struct to hold two integers
typedef struct {
    int first;
    int second;
} Pair;

// Struct to hold a queue of Pairs
typedef struct {
    Pair* v;
    int size;
    int capacity;
} Queue;

// Function to push a Pair onto the queue
void queuePush(Queue* q, Pair v) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->v = (Pair*)realloc(q->v, q->capacity * sizeof(Pair));
    }
    q->v[q->size++] = v;
}

// Function to pop a Pair from the front of the queue
Pair queuePop(Queue* q) {
    Pair r = q->v[0];
    for (int i = 1; i < q->size; i++) {
        q->v[i - 1] = q->v[i];
    }
    q->size--;
    return r;
}

// Function to get the front Pair of the queue without removing it
Pair queueFront(Queue* q) {
    return q->v[0];
}

// Function to check if the queue is empty
int queueEmpty(Queue* q) {
    return q->size == 0;
}

int main() {
    // Read two integers A and B from standard input
    FILE *r = stdin;
    int A = nextInt(&buf, &cur, r);
    int B = nextInt(&buf, &cur, r);

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If even, print the average of A and B
        printf("%d\n", (A + B) / 2);
        return 0;
    }
    // If not even, print "IMPOSSIBLE"
    printf("IMPOSSIBLE\n");
    return 0;
}
