
#include <stdio.h>

// Function to read a line from standard input and remove trailing whitespace
char* rs() {
    char* s = NULL;
    size_t n = 0;
    getline(&s, &n, stdin);
    char* p = s + strlen(s) - 1;
    while (p >= s && *p == ' ') {
        *p-- = '\0';
    }
    return s;
}

// Function to read an integer from standard input
int ri() {
    char* s = rs();
    return s ? atoi(s) : 0;
}

// Function to read a line from standard input and return a list of strings
char** rs_(int* n) {
    char* s = rs();
    if (!s) {
        *n = 0;
        return NULL;
    }
    char** a = malloc(strlen(s) * sizeof(char*));
    char* p = s;
    int i = 0;
    while (*p) {
        while (*p == ' ') {
            *p++ = '\0';
        }
        if (*p) {
            a[i++] = p;
            while (*p && *p != ' ') {
                p++;
            }
        }
    }
    *n = i;
    return a;
}

// Function to read a line from standard input and return a list of integers
int* ri_(int* n) {
    char** a = rs_(n);
    int* b = malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++) {
        b[i] = a[i] ? atoi(a[i]) : 0;
    }
    free(a);
    return b;
}

// Read the integer N from input
int N = ri();

// Initialize the answer variable to accumulate the result
int ans = 0;

// Loop through each integer from 1 to N (inclusive)
for (int i = 1; i <= N; i++) {
    // Calculate the contribution of the current integer i to the answer
    ans += i * (N / i) * (N / i + 1) / 2;
}

// Print the final result
printf("%d\n", ans);

