#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 10240

typedef struct {
    char buffer[BUFFER_SIZE];
    int position;
    int length;
    int eof;
    FILE *in;
} SimpleScanner;

void initScanner(SimpleScanner *scanner, FILE *in) {
    scanner->in = in;
    scanner->position = 0;
    scanner->length = 0;
    scanner->eof = 0;
}

char read(SimpleScanner *scanner) {
    if (scanner->position >= scanner->length) {
        scanner->length = fread(scanner->buffer, 1, BUFFER_SIZE, scanner->in);
        scanner->position = 0;
        if (scanner->length == 0) {
            scanner->eof = 1;
            return '\0';
        }
    }
    return scanner->buffer[scanner->position++];
}

void checkEof(SimpleScanner *scanner) {
    if (scanner->eof) {
        fprintf(stderr, "No such element\n");
        exit(EXIT_FAILURE);
    }
}

char nextChar(SimpleScanner *scanner) {
    checkEof(scanner);
    char b = read(scanner);
    checkEof(scanner);
    return b;
}

char* next(SimpleScanner *scanner) {
    char b;
    while (isspace(b = read(scanner))) {
        checkEof(scanner);
    }
    char *result = malloc(BUFFER_SIZE);
    int index = 0;
    do {
        result[index++] = b;
        b = read(scanner);
        checkEof(scanner);
    } while (!scanner->eof && !isspace(b));
    result[index] = '\0';
    return result;
}

int nextInt(SimpleScanner *scanner) {
    char *str = next(scanner);
    int value = atoi(str);
    free(str);
    return value;
}

long nextLong(SimpleScanner *scanner) {
    char *str = next(scanner);
    long value = atol(str);
    free(str);
    return value;
}

double nextDouble(SimpleScanner *scanner) {
    char *str = next(scanner);
    double value = atof(str);
    free(str);
    return value;
}

int main() {
    SimpleScanner scanner;
    initScanner(&scanner, stdin);
    
    int r = nextInt(&scanner);
    int d = nextInt(&scanner);
    long x = nextLong(&scanner);
    
    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        printf("%ld\n", x);
    }
    
    return 0;
}

// <END-OF-CODE>
