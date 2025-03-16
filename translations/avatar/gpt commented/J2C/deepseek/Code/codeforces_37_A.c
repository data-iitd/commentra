#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_position;
} FastScanner;

FastScanner* create_fast_scanner() {
    FastScanner *scanner = (FastScanner *)malloc(sizeof(FastScanner));
    scanner->buffer = (char *)malloc(MAX_LINE_LENGTH);
    scanner->buffer_size = 0;
    scanner->buffer_position = 0;
    return scanner;
}

void free_fast_scanner(FastScanner *scanner) {
    free(scanner->buffer);
    free(scanner);
}

char* next_token(FastScanner *scanner) {
    if (scanner->buffer_position >= scanner->buffer_size) {
        if (fgets(scanner->buffer, MAX_LINE_LENGTH, stdin) != NULL) {
            scanner->buffer_size = strlen(scanner->buffer);
            scanner->buffer_position = 0;
        } else {
            return NULL;
        }
    }
    char *token = scanner->buffer + scanner->buffer_position;
    scanner->buffer_position += strlen(token) + 1;
    return token;
}

int next_int(FastScanner *scanner) {
    char *token = next_token(scanner);
    return token ? atoi(token) : 0;
}

long next_long(FastScanner *scanner) {
    char *token = next_token(scanner);
    return token ? atol(token) : 0;
}

double next_double(FastScanner *scanner) {
    char *token = next_token(scanner);
    return token ? atof(token) : 0.0;
}

char* next_line(FastScanner *scanner) {
    if (scanner->buffer_position >= scanner->buffer_size) {
        if (fgets(scanner->buffer, MAX_LINE_LENGTH, stdin) != NULL) {
            scanner->buffer_size = strlen(scanner->buffer);
            scanner->buffer_position = 0;
        } else {
            return NULL;
        }
    }
    char *line = scanner->buffer + scanner->buffer_position;
    scanner->buffer_position += strlen(line) + 1;
    return line;
}

int main() {
    FastScanner *scanner = create_fast_scanner();

    int n = next_int(scanner);

    int map[100001] = {0};
    for (int i = 0; i < n; i++) {
        int val = next_int(scanner);
        map[val]++;
    }

    int max = 0;
    for (int i = 0; i < 100001; i++) {
        if (map[i] > max) {
            max = map[i];
        }
    }

    printf("%d%lu\n", max, (unsigned long)n);

    free_fast_scanner(scanner);
    return 0;
}
