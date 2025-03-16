#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read a line from standard input
void readLine(char **buffer) {
    size_t size = 128;
    *buffer = (char *)malloc(size * sizeof(char));
    if (*buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }
    if (fgets(*buffer, size, stdin) == NULL) {
        free(*buffer);
        exit(1);
    }
}

// Function to read the next space-separated word from the buffer
char* next(char **buffer) {
    static char *word;
    if (*buffer == NULL) {
        readLine(buffer);
    }
    word = strtok(*buffer, " \n");
    *buffer = NULL;
    return word;
}

// Function to read the next token as an integer
long long nextInt(char **buffer) {
    char *word = next(buffer);
    if (word == NULL) {
        return -1; // Error or end of input
    }
    return atoll(word);
}

// Function to read the entire next line from the buffer
char* nextLine(char **buffer) {
    static char *line;
    if (*buffer == NULL) {
        readLine(buffer);
    }
    line = strdup(*buffer);
    *buffer = NULL;
    return line;
}

// Function to print the arguments to the output with a newline
void out(long long a, ...) {
    va_list args;
    va_start(args, a);
    printf("%lld\n", a);
    va_end(args);
}

// Function to return the maximum of two integers
long long max(long long x, long long y) {
    return (x > y) ? x : y;
}

// Function to return the minimum of two integers
long long min(long long x, long long y) {
    return (x < y) ? x : y;
}

// Function to join an array of integers into a string with a separator
char* joinInts(long long *a, int count, char *sep) {
    char *result = (char *)malloc(1024 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < count; i++) {
        char temp[20];
        sprintf(temp, "%lld", a[i]);
        if (i > 0) {
            strcat(result, sep);
        }
        strcat(result, temp);
    }
    return result;
}

// Function to return the ceiling of the division of x by y
long long divUp(long long x, long long y) {
    return (x + y - 1) / y;
}

// Main function
int main() {
    char *buffer = NULL;
    long long N = nextInt(&buffer);
    long long T[N], A[N];
    for (int i = 0; i < N; i++) {
        T[i] = nextInt(&buffer);
        A[i] = nextInt(&buffer);
    }
    long long t = T[0], a = A[0];
    for (int i = 1; i < N; i++) {
        long long r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    out(t + a);
    free(buffer);
    return 0;
}
