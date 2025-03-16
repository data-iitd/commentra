#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *file;
    char *buffer;
    size_t buffer_size;
    size_t buffer_position;
} FastReader;

FastReader* create_fast_reader() {
    FastReader *reader = (FastReader*)malloc(sizeof(FastReader));
    reader->file = stdin;
    reader->buffer = NULL;
    reader->buffer_size = 0;
    reader->buffer_position = 0;
    return reader;
}

char* next(FastReader *reader) {
    while (reader->buffer == NULL || reader->buffer_position >= reader->buffer_size) {
        reader->buffer_size = fread(reader->buffer, 1, 1024, reader->file);
        reader->buffer_position = 0;
    }
    return reader->buffer + reader->buffer_position++;
}

int next_int(FastReader *reader) {
    char *token = next(reader);
    while (token == NULL || *token == '\n' || *token == '\r') {
        token = next(reader);
    }
    return atoi(token);
}

long next_long(FastReader *reader) {
    char *token = next(reader);
    while (token == NULL || *token == '\n' || *token == '\r') {
        token = next(reader);
    }
    return atol(token);
}

double next_double(FastReader *reader) {
    char *token = next(reader);
    while (token == NULL || *token == '\n' || *token == '\r') {
        token = next(reader);
    }
    return atof(token);
}

char* next_line(FastReader *reader) {
    char *line = NULL;
    size_t line_size = 0;
    ssize_t line_length;
    while ((line_length = getline(&line, &line_size, reader->file)) != -1) {
        return line;
    }
    free(line);
    return NULL;
}

int mod_power(int x, int y, int mod) {
    int res = 1;
    x %= mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

typedef struct {
    int first;
    int second;
} pair;

int main() {
    FastReader *reader = create_fast_reader();
    long a[4];
    for (int i = 0; i < 4; i++) {
        a[i] = next_long(reader);
    }
    printf("%ld\n", (long)fmaxl(a[0] * a[2], fmaxl(a[1] * a[3], fmaxl(a[0] * a[3], a[1] * a[2]))));
    free(reader);
    return 0;
}
