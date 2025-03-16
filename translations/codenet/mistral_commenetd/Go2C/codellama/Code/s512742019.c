
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// I/O
typedef struct Scanner {
    FILE *sc;
} Scanner;

// NewScanner initializes a new Scanner struct with a FILE
Scanner* NewScanner() {
    Scanner *sc = malloc(sizeof(Scanner));
    sc->sc = stdin;
    return sc;
}

// Helper functions for reading different data types from the scanner
char* nextStr(Scanner *sc) {
    char *str = malloc(sizeof(char) * 1024);
    fscanf(sc->sc, "%s", str);
    return str;
}

int nextInt(Scanner *sc) {
    int i;
    fscanf(sc->sc, "%d", &i);
    return i;
}

double nextFloat(Scanner *sc) {
    double f;
    fscanf(sc->sc, "%lf", &f);
    return f;
}

char* nextRuneSlice(Scanner *sc) {
    char *str = malloc(sizeof(char) * 1024);
    fscanf(sc->sc, "%s", str);
    return str;
}

int* nextIntSlice(Scanner *sc, int n) {
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        fscanf(sc->sc, "%d", &arr[i]);
    }
    return arr;
}

double* nextFloatSlice(Scanner *sc, int n) {
    double *arr = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        fscanf(sc->sc, "%lf", &arr[i]);
    }
    return arr;
}

// Arithmetic
int max(int nums[], int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
        if (m < nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int min(int nums[], int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
        if (m > nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return -x;
    }
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int ceil(int a, int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a/b + 1;
    }
}

// Sort
typedef struct RuneSlice {
    char *arr;
    int n;
} RuneSlice;

// Custom sorting function for RuneSlice
int cmp(const void *a, const void *b) {
    char *x = *(char**)a;
    char *y = *(char**)b;
    return *x - *y;
}

// Main
const int MOD = 1e+9 + 7; // Modulus value for modular arithmetic
const int INF = 1 << 60; // Infinite value for comparison

// Mon represents a monster with x-coordinate and height
typedef struct Mon {
    int x, h;
} Mon;

// Mons is a slice of Mon structures
typedef struct Mons {
    Mon *arr;
    int n;
} Mons;

// Custom sorting function for Mons
int cmpMons(const void *a, const void *b) {
    Mon *x = *(Mon**)a;
    Mon *y = *(Mon**)b;
    return x->x - y->x;
}

// Node represents a node in the priority queue with x-coordinate and damage
typedef struct Node {
    int x, h;
} Node;

// Queue is a priority queue implemented as a slice with custom push, pop, and isEmpty functions
typedef struct Queue {
    Node *arr;
    int n;
} Queue;

// Pushes a new Node to the priority queue
void push(Queue *q, Node v) {
    q->arr = realloc(q->arr, sizeof(Node) * (q->n + 1));
    q->arr[q->n++] = v;
}

// Returns the first Node in the priority queue
Node first(Queue *q) {
    return q->arr[0];
}

// Pops and returns the first Node from the priority queue
Node pop(Queue *q) {
    Node res = q->arr[0];
    q->arr = realloc(q->arr, sizeof(Node) * (q->n - 1));
    for (int i = 0; i < q->n - 1; i++) {
        q->arr[i] = q->arr[i + 1];
    }
    q->n--;
    return res;
}

// Checks if the priority queue is empty
bool isEmpty(Queue *q) {
    return q->n == 0;
}

// Main function initializes variables, sorts monsters, and calculates the answer
int main() {
    // Initialize a new Scanner and a FILE for input/output
    Scanner *sc = NewScanner();
    FILE *wtr = stdout;

    // Read input values N, D, and A from the scanner
    int N, D, A = nextInt(sc), nextInt(sc), nextInt(sc);

    // Initialize a slice of Mon structures called M
    Mon *M = malloc(sizeof(Mon) * N);

    // Read x and h values for each Mon and store them in the M slice
    for (int i = 0; i < N; i++) {
        M[i] = (Mon){nextInt(sc), nextInt(sc)};
    }

    // Sort the M slice based on x-coordinates
    qsort(M, N, sizeof(Mon), cmpMons);

    // Initialize an empty priority queue called q
    Queue *q = malloc(sizeof(Queue));
    q->arr = malloc(sizeof(Node) * 0);
    q->n = 0;

    // Initialize answer variable ans to 0 and total variable total to 0
    int ans = 0;
    int total = 0;

    // Iterate through each Mon in the sorted M slice
    for (int i = 0; i < N; i++) {
        // Current Mon
        Mon m = M[i];

        // While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
        while (!isEmpty(q) && first(q).x < m.x) {
            // Pop the first Node from the priority queue
            total -= pop(q).h;
        }

        // If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
        if (total < m.h) {
            int damage = m.h - total;
            ans += damage;
            push(q, (Node){m.x + 2*D, damage});
            total += damage;
        }
    }

    // Print the answer
    fprintf(wtr, "%d\n", ans);

    // Flush the writer to output the answer
    fflush(wtr);

    // Free memory
    free(M);
    free(q->arr);
    free(q);
    free(sc);

    return 0;
}

