
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Constants and variables declaration
const int inf = 2147483647; // Constants for maximum signed integer value

// var mod = 1000000007; // Unused constant, can be removed

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0}; // 8 directions for movement
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

// Global variables declaration
char *N; // Global string for reading input
int m, n; // Global integers for storing input values

// init function initializes the program
void init() {
    srand(time(NULL)); // Seed random number generator with current time
}

// main function is the entry point of the program
void main() {
    // Read input N as a string
    N = (char *)malloc(sizeof(char) * 100);
    scanf("%s", N);
    // Convert N to an integer
    int b = 0;
    for (int i = 0; i < strlen(N); i++) {
        b += N[i] - '0'; // Convert each digit to an integer and add to the sum
    }
    // Read input m as an integer
    scanf("%d", &m);
    // Check if m is divisible by n
    if (m % n == 0) {
        printf("Yes\n"); // Print "Yes" if m is divisible by n
    } else {
        printf("No\n"); // Print "No" if m is not divisible by n
    }
}

// ---------------------------------------------------------

// Pair type definition for storing two integers
typedef struct {
    int a, b;
} Pair;

// Pairs type definition for storing a slice of Pair
typedef struct {
    Pair *pairs;
    int size;
} Pairs;

// Implement Len, Swap, and Less methods for sorting Pairs based on the second element
int Len(Pairs *p) {
    return p->size;
}
void Swap(Pairs *p, int i, int j) {
    Pair temp = p->pairs[i];
    p->pairs[i] = p->pairs[j];
    p->pairs[j] = temp;
}
int Less(Pairs *p, int i, int j) {
    return p->pairs[i].b < p->pairs[j].b; // Sort based on the second element
}

// ------int methods-------------------------
int in(int c, int a, int z) {
    return c >= a && c < z; // Check if c is within the range [a, z)
}
int out(int c, int a, int z) {
    return !in(c, a, z); // Check if c is outside the range [a, z)
}
int btoi(bool b) {
    if (b) {
        return 1; // Convert boolean to integer: 1 for true, 0 for false
    }
    return 0;
}
bool itob(int a) {
    return a != 0; // Convert integer to boolean: true for non-zero, false for zero
}
int max(int a, int b) {
    if (a > b) {
        return a; // Find the maximum integer among the given integers
    }
    return b;
}
int min(int a, int b) {
    if (a < b) {
        return a; // Find the minimum integer among the given integers
    }
    return b;
}
int sum(int *a, int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i]; // Calculate the sum of all integers in the given slice
    }
    return r;
}
int pro(int *a, int n) {
    int r = a[0];
    for (int i = 1; i < n; i++) {
        r *= a[i]; // Calculate the product of all integers in the given slice
    }
    return r;
}

void fill(int *a, int n, int v) {
    for (int i = 0; i < n; i++) {
        a[i] = v; // Fill the given slice with the given integer value
    }
}
int minmax(int a, int b) {
    if (a > b) {
        return b, a; // Return the minimum and maximum integers among the given integers
    }
    return a, b;
}

int abs(int a) {
    if (a < 0) {
        return -a; // Calculate the absolute value of an integer
    }
    return a;
}

// ---------- buffered scanner -----------------------------------------
typedef struct {
    char *buf;
    int p;
} scanner;

scanner *newScanner() {
    scanner *s = (scanner *)malloc(sizeof(scanner));
    s->buf = (char *)malloc(sizeof(char) * 10000);
    s->p = 0;
    return s;
}
char *next(scanner *s) {
    s->pre();
    int start = s->p;
    for (; s->p < strlen(s->buf); s->p++) {
        if (s->buf[s->p] == ' ') {
            break; // Find the position of the next whitespace character
        }
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}
char *Line(scanner *s) {
    s->pre();
    int start = s->p;
    s->p = strlen(s->buf);
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}
char *String(scanner *s) {
    return next(s); // Call next() method to read the next token as a string
}
int Int(scanner *s) {
    char *v = next(s);
    int result = atoi(v);
    free(v);
    return result;
}
int *Ints(scanner *s, int n) {
    int *r = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        r[i] = Int(s); // Read and store n integers in the slice
    }
    return r;
}
int Int64(scanner *s) {
    char *v = next(s);
    int result = atoi(v);
    free(v);
    return result;
}
int Uint64(scanner *s) {
    char *v = next(s);
    int result = atoi(v);
    free(v);
    return result;
}
int Float64(scanner *s) {
    char *v = next(s);
    int result = atoi(v);
    free(v);
    return result;
}
void pre(scanner *s) {
    if (s->p >= strlen(s->buf)) {
        s->readLine(); // Read a new line if the buffer is empty
        s->p = 0;
    }
}
void readLine(scanner *s) {
    s->buf = (char *)malloc(sizeof(char) * 10000);
    for (;;) {
        char *l = (char *)malloc(sizeof(char) * 10000);
        int p = 0;
        int err = scanf("%s", l);
        if (err != 1) {
            log(err); // Log an error and exit the program if an error occurs during reading
        }
        strcat(s->buf, l); // Append the read line to the buffer
        if (!p) {
            break; // Exit the loop if the end of the input is reached
        }
    }
}

// 