#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1048576

typedef struct {
    char *data;
    size_t size;
    size_t pos;
} Scanner;

Scanner* newScanner(FILE *r) {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->data = (char *)malloc(MAX_INPUT_SIZE);
    s->size = fread(s->data, 1, MAX_INPUT_SIZE, r);
    s->pos = 0;
    return s;
}

int scanInt(Scanner *s) {
    while (s->pos < s->size && (s->data[s->pos] == ' ' || s->data[s->pos] == '\n' || s->data[s->pos] == '\r' || s->data[s->pos] == '\t')) {
        s->pos++;
    }
    int val = 0;
    int sign = 1;
    if (s->pos < s->size) {
        if (s->data[s->pos] == '-') {
            sign = -1;
            s->pos++;
        }
        while (s->pos < s->size && s->data[s->pos] >= '0' && s->data[s->pos] <= '9') {
            val = val * 10 + (s->data[s->pos] - '0');
            s->pos++;
        }
    }
    return val * sign;
}

void pln(int s, ...) {
    va_list args;
    va_start(args, s);
    for (int i = 0; i < s; i++) {
        int arg = va_arg(args, int);
        printf("%d\n", arg);
    }
    va_end(args);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    if (!input) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    Scanner *s = newScanner(input);
    int n = scanInt(s);
    int k = scanInt(s);

    if (n % k == 0) {
        pln(1, 0);
    } else {
        pln(1, 1);
    }

    free(s->data);
    free(s);
    fclose(input);
    return 0;
}

