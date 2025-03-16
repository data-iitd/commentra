#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastReader struct to read input efficiently
typedef struct {
    FILE *fp;
    char *buffer;
    size_t buffer_size;
    ssize_t buffer_position;
} FastReader;

FastReader* createFastReader(FILE *fp) {
    FastReader *reader = (FastReader *)malloc(sizeof(FastReader));
    reader->fp = fp;
    reader->buffer_size = 1024;
    reader->buffer = (char *)malloc(reader->buffer_size);
    reader->buffer_position = 0;
    return reader;
}

char* next(FastReader *reader) {
    while (reader->buffer_position >= reader->buffer_size || reader->buffer[reader->buffer_position] == '\0') {
        size_t bytes_read = fread(reader->buffer, sizeof(char), reader->buffer_size - 1, reader->fp);
        if (bytes_read == 0) {
            return NULL;
        }
        reader->buffer[bytes_read] = '\0';
        reader->buffer_position = 0;
    }
    char *token = strtok(reader->buffer + reader->buffer_position, " \t\n");
    if (token == NULL) {
        return NULL;
    }
    reader->buffer_position += (token - (reader->buffer + reader->buffer_position)) + strlen(token);
    return token;
}

int nextInt(FastReader *reader) {
    char *token = next(reader);
    return token == NULL ? 0 : atoi(token);
}

long nextLong(FastReader *reader) {
    char *token = next(reader);
    return token == NULL ? 0 : atoll(token);
}

double nextDouble(FastReader *reader) {
    char *token = next(reader);
    return token == NULL ? 0.0 : atof(token);
}

char* nextLine(FastReader *reader) {
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, reader->fp) != -1) {
        return line;
    }
    free(line);
    return NULL;
}

void destroyFastReader(FastReader *reader) {
    free(reader->buffer);
    free(reader);
}

// Function to calculate x^y mod mod using efficient exponentiation by squaring
int modPower(int x, int y, int mod) {
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

// Generic pair struct to hold two elements of type T1 and T2
typedef struct {
    int first;
    int second;
} Pair;

Pair createPair(int first, int second) {
    Pair p;
    p.first = first;
    p.second = second;
    return p;
}

// Main function to read input, calculate the maximum product, and print the result
int main() {
    FastReader *reader = createFastReader(stdin);
    long a[4];
    for (int i = 0; i < 4; i++) {
        a[i] = nextLong(reader);
    }
    long max_product = a[0] * a[2];
    if (a[1] * a[3] > max_product) max_product = a[1] * a[3];
    if (a[0] * a[3] > max_product) max_product = a[0] * a[3];
    if (a[1] * a[2] > max_product) max_product = a[1] * a[2];
    printf("%ld\n", max_product);
    destroyFastReader(reader);
    return 0;
}
