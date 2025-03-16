#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *buffer;
    size_t buffer_size;
    ssize_t length;
} LineReader;

void init_line_reader(LineReader *lr, size_t initial_size) {
    lr->buffer = (char *)malloc(initial_size);
    lr->buffer_size = initial_size;
    lr->length = 0;
}

void free_line_reader(LineReader *lr) {
    free(lr->buffer);
}

char *read_line(LineReader *lr) {
    lr->length = getline(&(lr->buffer), &(lr->buffer_size), stdin);
    if (lr->length == -1) {
        return NULL;
    }
    return lr->buffer;
}

int main() {
    LineReader lr;
    init_line_reader(&lr, MAX_LINE_LENGTH);

    int n, s, max = 0;

    char *line = read_line(&lr);
    sscanf(line, "%d", &n);
    line = read_line(&lr);
    sscanf(line, "%d", &s);

    for (int i = 0; i < n; i++) {
        line = read_line(&lr);
        int f, t;
        sscanf(line, "%d %d", &f, &t);
        if (max < f + t) {
            max = f + t;
        }
    }

    printf("%d\n", max > s ? max : s);

    free_line_reader(&lr);
    return 0;
}
