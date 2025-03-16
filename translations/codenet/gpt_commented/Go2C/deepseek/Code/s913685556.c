#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return a < b ? b : a;
}

// Scanner struct to handle input reading
typedef struct {
    char *buf; // Buffer to hold the input data
    size_t p;  // Current position in the buffer
    size_t bufSize; // Size of the buffer
} Scanner;

// NewScanner initializes and returns a new Scanner
Scanner* NewScanner() {
    Scanner *sc = (Scanner*)malloc(sizeof(Scanner));
    sc->bufSize = 1000;
    sc->buf = (char*)malloc(sc->bufSize);
    sc->p = 0;
    return sc;
}

// Next reads the next token from the input
char* Next(Scanner *sc) {
    while (sc->p < strlen(sc->buf) && sc->buf[sc->p] == ' ') {
        sc->p++;
    }
    if (sc->p >= strlen(sc->buf)) {
        return NULL;
    }
    size_t start = sc->p;
    while (sc->p < strlen(sc->buf) && sc->buf[sc->p] != ' ') {
        sc->p++;
    }
    char *result = (char*)malloc(sc->p - start + 1);
    strncpy(result, sc->buf + start, sc->p - start);
    result[sc->p - start] = '\0';
    return result;
}

// NextLine reads the next line from the input
char* NextLine(Scanner *sc) {
    char *result = (char*)malloc(strlen(sc->buf) - sc->p + 1);
    strcpy(result, sc->buf + sc->p);
    sc->p = strlen(sc->buf);
    return result;
}

// NextInt reads the next integer from the input
int NextInt(Scanner *sc) {
    char *token = Next(sc);
    int value = atoi(token);
    free(token);
    return value;
}

// NextInt64 reads the next int64 from the input
long long NextInt64(Scanner *sc) {
    char *token = Next(sc);
    long long value = atoll(token);
    free(token);
    return value;
}

// NextFloat reads the next float64 from the input
double NextFloat(Scanner *sc) {
    char *token = Next(sc);
    double value = atof(token);
    free(token);
    return value;
}

// NextIntArray reads a space-separated array of integers from the input
int* NextIntArray(Scanner *sc, int *size) {
    while (sc->p < strlen(sc->buf) && sc->buf[sc->p] == ' ') {
        sc->p++;
    }
    if (sc->p >= strlen(sc->buf)) {
        return NULL;
    }
    size_t start = sc->p;
    while (sc->p < strlen(sc->buf) && sc->buf[sc->p] != ' ') {
        sc->p++;
    }
    *size = sc->p - start;
    int *result = (int*)malloc(*size);
    for (int i = 0; i < *size; i++) {
        result[i] = sc->buf[start + i] - '0';
    }
    return result;
}

// NextInt64Array reads a space-separated array of int64 from the input
long long* NextInt64Array(Scanner *sc, int *size) {
    while (sc->p < strlen(sc->buf) && sc->buf[sc->p] == ' ') {
        sc->p++;
    }
    if (sc->p >= strlen(sc->buf)) {
        return NULL;
    }
    size_t start = sc->p;
    while (sc->p < strlen(sc->buf) && sc->buf[sc->p] != ' ') {
        sc->p++;
    }
    *size = sc->p - start;
    long long *result = (long long*)malloc(*size);
    for (int i = 0; i < *size; i++) {
        result[i] = sc->buf[start + i] - '0';
    }
    return result;
}

// NextMap reads a space-separated map of integers to booleans from the input
int* NextMap(Scanner *sc, int *size) {
    while (sc->p < strlen(sc->buf) && sc->buf[sc->p] == ' ') {
        sc->p++;
    }
    if (sc->p >= strlen(sc->buf)) {
        return NULL;
    }
    size_t start = sc->p;
    while (sc->p < strlen(sc->buf) && sc->buf[sc->p] != ' ') {
        sc->p++;
    }
    *size = sc->p - start;
    int *result = (int*)malloc(*size);
    for (int i = 0; i < *size; i++) {
        result[i] = sc->buf[start + i] - '0';
    }
    return result;
}

// pre checks if more data needs to be read into the buffer
void pre(Scanner *sc) {
    if (sc->p >= strlen(sc->buf)) {
        fgets(sc->buf, sc->bufSize, stdin);
        sc->p = 0;
    }
}

int main() {
    Scanner *sc = NewScanner();
    int A = NextInt(sc);
    int B = NextInt(sc);

    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    printf("%d\n", mx);

    free(sc->buf);
    free(sc);
    return 0;
}
