
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    FILE *reader;
    FILE *writer;
    char **tokens;
    int nextToken;
} Io;

Io *newIo() {
    Io *io = (Io *)malloc(sizeof(Io));
    io->reader = stdin;
    io->writer = stdout;
    io->tokens = NULL;
    io->nextToken = 0;
    return io;
}

void flushIo(Io *io) {
    fflush(io->writer);
}

char *readLine(Io *io) {
    int size = 1024;
    char *buffer = (char *)malloc(sizeof(char) * size);
    int index = 0;
    while (1) {
        int c = fgetc(io->reader);
        if (c == EOF) {
            break;
        }
        buffer[index++] = (char)c;
        if (c == '\n') {
            break;
        }
        if (index >= size) {
            size *= 2;
            buffer = (char *)realloc(buffer, sizeof(char) * size);
        }
    }
    buffer[index] = '\0';
    return buffer;
}

char *next(Io *io) {
    if (io->nextToken >= 0) {
        free(io->tokens[io->nextToken]);
        io->tokens[io->nextToken] = NULL;
    }
    while (io->nextToken >= 0 && io->tokens[io->nextToken] == NULL) {
        char *line = readLine(io);
        io->tokens = (char **)realloc(io->tokens, sizeof(char *) * (io->nextToken + 2));
        io->tokens[io->nextToken + 1] = NULL;
        char *token = strtok(line, " ");
        int index = io->nextToken;
        while (token!= NULL) {
            io->tokens[index] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(io->tokens[index], token);
            token = strtok(NULL, " ");
            index++;
        }
        io->nextToken = -1;
    }
    io->nextToken++;
    return io->tokens[io->nextToken - 1];
}

int intNext(Io *io) {
    char *token = next(io);
    int value = atoi(token);
    free(token);
    return value;
}

void printLn(Io *io,...) {
    va_list args;
    va_start(args, io);
    vfprintf(io->writer, "\n", args);
    va_end(args);
    fflush(io->writer);
}

void printf(Io *io, char *format,...) {
    va_list args;
    va_start(args, format);
    vfprintf(io->writer, format, args);
    va_end(args);
    fflush(io->writer);
}

int *cumSum(int *nums, int size) {
    int *sums = (int *)malloc(sizeof(int) * (size + 1));
    sums[0] = 0;
    for (int i = 0; i < size; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

int abs(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

int min(int a, int b) {
    return a < b? a : b;
}

int main() {
    Io *io = newIo();
    int n = intNext(io);
    int *aa = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        aa[i] = intNext(io);
    }
    int *cumsums = cumSum(aa, n);
    int ans = 2020202020;
    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, abs(cumsums[n] - cumsums[i] - (cumsums[i] - cumsums[0])));
    }
    printLn(io, "%d", ans);
    flushIo(io);
    return 0;
}

