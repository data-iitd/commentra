#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 10240

typedef struct {
    FILE *in;
    char buffer[BUFFER_SIZE];
    size_t pos;
    size_t lim;
    int eof;
} SimpleScanner;

void initScanner(SimpleScanner *scanner, FILE *in) {
    scanner->in = in;
    scanner->pos = 0;
    scanner->lim = 0;
    scanner->eof = 0;
}

char readChar(SimpleScanner *scanner) {
    if (scanner->pos >= scanner->lim) {
        scanner->lim = fread(scanner->buffer, 1, BUFFER_SIZE, scanner->in);
        scanner->pos = 0;
        if (scanner->lim == 0) {
            scanner->eof = 1;
            return '\0';
        }
    }
    return scanner->buffer[scanner->pos++];
}

void checkEof(SimpleScanner *scanner) {
    if (scanner->eof) {
        fprintf(stderr, "No such element exception\n");
        exit(EXIT_FAILURE);
    }
}

char nextChar(SimpleScanner *scanner) {
    checkEof(scanner);
    char b = readChar(scanner);
    checkEof(scanner);
    return b;
}

char* nextString(SimpleScanner *scanner) {
    char b;
    do {
        b = readChar(scanner);
        checkEof(scanner);
    } while (isspace(b));
    char *str = (char*)malloc(1);
    size_t len = 0;
    do {
        str = (char*)realloc(str, len + 2);
        str[len++] = b;
        str[len] = '\0';
        b = readChar(scanner);
    } while (!scanner->eof && !isspace(b));
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
    SimpleScanner scanner;
    initScanner(&scanner, stdin);
    FILE *writer = stdout;

    int r = nextInt(&scanner);
    int d = nextInt(&scanner);
    long x = nextLong(&scanner);

    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        fprintf(writer, "%ld\n", x);
    }

    fclose(writer);
    return 0;
}
