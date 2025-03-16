#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    FILE *file;
    char buffer[10240];
    size_t pos;
    size_t size;
    int eof;
} SimpleScanner;

SimpleScanner* createScanner(FILE *file) {
    SimpleScanner *scanner = (SimpleScanner *)malloc(sizeof(SimpleScanner));
    scanner->file = file;
    scanner->pos = 0;
    scanner->size = 0;
    scanner->eof = 0;
    return scanner;
}

char readChar(SimpleScanner *scanner) {
    if (scanner->pos >= scanner->size) {
        scanner->size = fread(scanner->buffer, 1, sizeof(scanner->buffer), scanner->file);
        scanner->pos = 0;
        if (scanner->size == 0) {
            scanner->eof = 1;
            return '\0';
        }
    }
    return scanner->buffer[scanner->pos++];
}

void checkEof(SimpleScanner *scanner) {
    if (scanner->eof) {
        fprintf(stderr, "EOF reached\n");
        exit(EXIT_FAILURE);
    }
}

char nextChar(SimpleScanner *scanner) {
    checkEof(scanner);
    char b = readChar(scanner);
    checkEof(scanner);
    return b;
}

char* nextToken(SimpleScanner *scanner) {
    char b;
    do {
        b = readChar(scanner);
        checkEof(scanner);
    } while (isspace(b));

    char *token = (char *)malloc(256);
    size_t len = 0;
    do {
        token[len++] = b;
        b = readChar(scanner);
    } while (!scanner->eof && !isspace(b));
    token[len] = '\0';
    return token;
}

int nextInt(SimpleScanner *scanner) {
    char *token = nextToken(scanner);
    int value = atoi(token);
    free(token);
    return value;
}

long nextLong(SimpleScanner *scanner) {
    char *token = nextToken(scanner);
    long value = atol(token);
    free(token);
    return value;
}

double nextDouble(SimpleScanner *scanner) {
    char *token = nextToken(scanner);
    double value = atof(token);
    free(token);
    return value;
}

int main() {
    SimpleScanner *scanner = createScanner(stdin);
    int r = nextInt(scanner);
    int d = nextInt(scanner);
    long x = nextLong(scanner);

    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        printf("%ld\n", x);
    }

    free(scanner);
    return 0;
}
