#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *fp;
    char *buffer;
    size_t buffer_size;
    size_t buffer_position;
} FastReader;

FastReader* create_fast_reader() {
    FastReader *fr = (FastReader *)malloc(sizeof(FastReader));
    fr->buffer = NULL;
    fr->buffer_size = 0;
    fr->buffer_position = 0;
    fr->fp = stdin;
    return fr;
}

char* next(FastReader *fr) {
    while (fr->buffer == NULL || fr->buffer_position >= fr->buffer_size) {
        fr->buffer_size = fread(fr->buffer, 1, 1024, fr->fp);
        fr->buffer_position = 0;
    }
    return fr->buffer + fr->buffer_position++;
}

int next_int(FastReader *fr) {
    char *token = next(fr);
    while (token == NULL || *token == '\n' || *token == '\r') {
        token = next(fr);
    }
    return atoi(token);
}

long next_long(FastReader *fr) {
    char *token = next(fr);
    while (token == NULL || *token == '\n' || *token == '\r') {
        token = next(fr);
    }
    return atol(token);
}

double next_double(FastReader *fr) {
    char *token = next(fr);
    while (token == NULL || *token == '\n' || *token == '\r') {
        token = next(fr);
    }
    return atof(token);
}

void solve(FastReader *fr) {
    int t = next_int(fr);
    int arr[t];
    for (int i = 0; i < t; i++) {
        arr[i] = next_int(fr);
    }
    int prevWinner = 0;
    for (int i = 0; i < t; i++) {
        if (arr[i] == 1) {
            if (prevWinner == 0) {
                prevWinner = 2;
            }
        }
        if (prevWinner == 2 || prevWinner == 0) {
            if ((arr[i] - 1) % 2 == 0) {
                printf("2\n");
                prevWinner = 2;
            } else {
                printf("1\n");
                prevWinner = 1;
            }
        } else {
            if ((arr[i] - 1) % 2 == 0) {
                printf("1\n");
                prevWinner = 1;
            } else {
                printf("2\n");
                prevWinner = 2;
            }
        }
    }
}

int main() {
    FastReader *fr = create_fast_reader();
    solve(fr);
    free(fr->buffer);
    free(fr);
    return 0;
}
