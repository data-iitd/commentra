#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t start;
    size_t end;
    FILE *file;
    int eof;
} SimpleScanner;

SimpleScanner* createScanner(FILE *file) {
    SimpleScanner *scanner = (SimpleScanner *)malloc(sizeof(SimpleScanner));
    scanner->buffer = (char *)malloc(BUFFER_SIZE);
    scanner->buffer_size = BUFFER_SIZE;
    scanner->start = 0;
    scanner->end = 0;
    scanner->file = file;
    scanner->eof = 0;
    return scanner;
}

char readChar(SimpleScanner *scanner) {
    if (scanner->start == scanner->end) {
        scanner->end = fread(scanner->buffer, 1, BUFFER_SIZE, scanner->file);
        if (scanner->end == 0) {
            scanner->eof = 1;
            return '\0';
        }
        scanner->start = 0;
    }
    return scanner->buffer[scanner->start++];
}

void checkEof(SimpleScanner *scanner) {
    if (scanner->eof) {
        fprintf(stderr, "No such element exception\n");
        exit(EXIT_FAILURE);
    }
}

char nextChar(SimpleScanner *scanner) {
    checkEof(scanner);
    char c = readChar(scanner);
    checkEof(scanner);
    return c;
}

char* nextString(SimpleScanner *scanner) {
    char *str = (char *)malloc(BUFFER_SIZE);
    size_t index = 0;
    char c;
    do {
        c = readChar(scanner);
        checkEof(scanner);
        str[index++] = c;
    } while (c != '\0' && c != '\n');
    str[index] = '\0';
    return str;
}

int nextInt(SimpleScanner *scanner) {
    char *str = nextString(scanner);
    int num = atoi(str);
    free(str);
    return num;
}

long nextLong(SimpleScanner *scanner) {
    char *str = nextString(scanner);
    long num = atol(str);
    free(str);
    return num;
}

double nextDouble(SimpleScanner *scanner) {
    char *str = nextString(scanner);
    double num = atof(str);
    free(str);
    return num;
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

    free(scanner->buffer);
    free(scanner);
    return 0;
}

