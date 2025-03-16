#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    FILE *in;
    char buffer[10240];
    size_t pos;
    size_t size;
    bool eof;
} SimpleScanner;

void init_scanner(SimpleScanner *scanner, FILE *in) {
    scanner->in = in;
    scanner->pos = 0;
    scanner->size = 0;
    scanner->eof = false;
}

char read_char(SimpleScanner *scanner) {
    if (scanner->pos >= scanner->size) {
        scanner->size = fread(scanner->buffer, 1, sizeof(scanner->buffer), scanner->in);
        scanner->pos = 0;
        if (scanner->size == 0) {
            scanner->eof = true;
            return '\0';
        }
    }
    return scanner->buffer[scanner->pos++];
}

void check_eof(SimpleScanner *scanner) {
    if (scanner->eof) {
        fprintf(stderr, "No such element exception\n");
        exit(EXIT_FAILURE);
    }
}

char next_char(SimpleScanner *scanner) {
    check_eof(scanner);
    char b = read_char(scanner);
    check_eof(scanner);
    return b;
}

char *read_line(SimpleScanner *scanner, char *dest, size_t len) {
    size_t i = 0;
    char b;
    while ((b = read_char(scanner)) != '\n' && b != '\0') {
        if (i < len - 1) {
            dest[i++] = b;
        }
    }
    dest[i] = '\0';
    return (b == '\0' && i == 0) ? NULL : dest;
}

int next_int(SimpleScanner *scanner) {
    char b;
    do {
        b = read_char(scanner);
        check_eof(scanner);
    } while (b == ' ' || b == '\t' || b == '\n' || b == '\r');

    int sign = 1;
    if (b == '-') {
        sign = -1;
        b = read_char(scanner);
        check_eof(scanner);
    }

    int result = 0;
    while (b >= '0' && b <= '9') {
        result = result * 10 + (b - '0');
        b = read_char(scanner);
        check_eof(scanner);
    }

    return sign * result;
}

long next_long(SimpleScanner *scanner) {
    char b;
    do {
        b = read_char(scanner);
        check_eof(scanner);
    } while (b == ' ' || b == '\t' || b == '\n' || b == '\r');

    int sign = 1;
    if (b == '-') {
        sign = -1;
        b = read_char(scanner);
        check_eof(scanner);
    }

    long result = 0;
    while (b >= '0' && b <= '9') {
        result = result * 10 + (b - '0');
        b = read_char(scanner);
        check_eof(scanner);
    }

    return sign * result;
}

double next_double(SimpleScanner *scanner) {
    char b;
    do {
        b = read_char(scanner);
        check_eof(scanner);
    } while (b == ' ' || b == '\t' || b == '\n' || b == '\r');

    int sign = 1;
    if (b == '-') {
        sign = -1;
        b = read_char(scanner);
        check_eof(scanner);
    }

    double result = 0.0;
    double factor = 1.0;
    while (b >= '0' && b <= '9') {
        result = result * 10 + (b - '0');
        b = read_char(scanner);
        check_eof(scanner);
    }

    if (b == '.') {
        b = read_char(scanner);
        check_eof(scanner);
        while (b >= '0' && b <= '9') {
            result = result * 10 + (b - '0');
            factor *= 10;
            b = read_char(scanner);
            check_eof(scanner);
        }
    }

    return sign * result / factor;
}

void print_int(int value) {
    printf("%d", value);
}

void print_long(long value) {
    printf("%ld", value);
}

void print_double(double value) {
    printf("%f", value);
}

void print_char(char value) {
    printf("%c", value);
}

void print_string(const char *value) {
    printf("%s", value);
}

void close_scanner(SimpleScanner *scanner) {
    // No need to close the file in C
}

int main() {
    SimpleScanner scanner;
    init_scanner(&scanner, stdin);

    int r = next_int(&scanner);
    int d = next_int(&scanner);
    long x = next_long(&scanner);

    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        print_long(x);
        print_char('\n');
    }

    close_scanner(&scanner);
    return 0;
}

