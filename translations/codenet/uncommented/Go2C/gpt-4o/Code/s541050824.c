#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t size;
    size_t capacity;
} bufReader;

bufReader reader;

void initBufReader() {
    reader.buf = NULL;
    reader.size = 0;
    reader.capacity = 0;
}

void readLine() {
    size_t len = 0;
    getline(&reader.buf, &len, stdin);
    reader.size = strlen(reader.buf);
}

char* next() {
    readLine();
    char *token = strtok(reader.buf, " \n");
    return token;
}

long long nextInt() {
    char *token = next();
    return atoll(token);
}

void out(long long result) {
    printf("%lld\n", result);
}

long long max(long long x, long long y) {
    return (x > y) ? x : y;
}

long long divUp(long long x, long long y) {
    return (x + y - 1) / y;
}

int main() {
    initBufReader();
    
    long long N = nextInt();
    long long *T = malloc(N * sizeof(long long));
    long long *A = malloc(N * sizeof(long long));
    
    for (long long i = 0; i < N; i++) {
        T[i] = nextInt();
        A[i] = nextInt();
    }
    
    long long t = T[0], a = A[0];
    for (long long i = 1; i < N; i++) {
        long long r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    
    out(t + a);
    
    free(T);
    free(A);
    free(reader.buf);
    
    return 0;
}

// <END-OF-CODE>
