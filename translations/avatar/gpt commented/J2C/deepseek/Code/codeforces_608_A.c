#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_position;
} FastScanner;

FastScanner* createFastScanner() {
    FastScanner *scanner = (FastScanner *)malloc(sizeof(FastScanner));
    scanner->buffer = NULL;
    scanner->buffer_size = 0;
    scanner->buffer_position = 0;
    return scanner;
}

void freeFastScanner(FastScanner *scanner) {
    if (scanner->buffer) {
        free(scanner->buffer);
    }
    free(scanner);
}

void ensureBufferCapacity(FastScanner *scanner, size_t new_size) {
    if (new_size > scanner->buffer_size) {
        scanner->buffer = (char *)realloc(scanner->buffer, new_size);
        scanner->buffer_size = new_size;
    }
}

void readLine(FastScanner *scanner) {
    size_t new_size = 128;
    ensureBufferCapacity(scanner, new_size);
    scanner->buffer_position = 0;
    while (1) {
        char c = getchar();
        if (c == '\n' || c == EOF) {
            scanner->buffer[scanner->buffer_position] = '\0';
            break;
        }
        scanner->buffer[scanner->buffer_position++] = c;
        if (scanner->buffer_position >= new_size - 1) {
            new_size *= 2;
            ensureBufferCapacity(scanner, new_size);
        }
    }
}

char* nextToken(FastScanner *scanner) {
    if (scanner->buffer_position == 0) {
        readLine(scanner);
    }
    char *token = (char *)malloc(scanner->buffer_position + 1);
    strncpy(token, scanner->buffer, scanner->buffer_position);
    token[scanner->buffer_position] = '\0';
    scanner->buffer_position = 0;
    return token;
}

int nextInt(FastScanner *scanner) {
    char *token = nextToken(scanner);
    int value = atoi(token);
    free(token);
    return value;
}

long nextLong(FastScanner *scanner) {
    char *token = nextToken(scanner);
    long value = atol(token);
    free(token);
    return value;
}

double nextDouble(FastScanner *scanner) {
    char *token = nextToken(scanner);
    double value = atof(token);
    free(token);
    return value;
}

int main() {
    FastScanner *scanner = createFastScanner();
    int n = nextInt(scanner);
    int s = nextInt(scanner);

    int max = 0;

    for (int i = 0; i < n; i++) {
        int f = nextInt(scanner);
        int t = nextInt(scanner);
        if (max < f + t) {
            max = f + t;
        }
    }

    printf("%d\n", max > s ? max : s);

    freeFastScanner(scanner);
    return 0;
}
