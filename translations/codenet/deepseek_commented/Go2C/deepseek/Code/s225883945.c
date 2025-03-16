#include <stdio.h>
#include <stdlib.h>

// Reads a single line of input from the standard input.
char* next() {
    char *line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    return line;
}

// Reads the next input as an integer.
int nextInt() {
    char *line = next();
    return atoi(line);
}

// Reads the next input as a float64.
double nextFloat64() {
    char *line = next();
    return atof(line);
}

// Reads `n` integers from input and returns them as a dynamically allocated array.
int* nextInts(int n) {
    int *slice = (int*)malloc(n * sizeof(int));
    if (slice == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        char *line = next();
        slice[i] = atoi(line);
    }
    return slice;
}

int main() {
    int n = nextInt();
    int k = nextInt();
    int *a = nextInts(n);
    // Set the first element of `a` to 0 to avoid unused variable error.
    a[0] = 0;

    int sum = k;
    int ans = 1;
    // Loop to increment `sum` and `ans` until `sum` is less than `n`.
    while (sum < n) {
        sum = sum - 1 + k;
        ans++;
    }
    printf("%d\n", ans);

    // Free the allocated memory for `a`.
    free(a);
    return 0;
}
