
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new Scanner for reading input from standard input (stdin)
typedef struct Scanner {
    char *buf;
    int cap;
    int ptr;
} Scanner;

Scanner *newScanner(int cap) {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(cap * sizeof(char));
    s->cap = cap;
    s->ptr = 0;
    return s;
}

void freeScanner(Scanner *s) {
    free(s->buf);
    free(s);
}

void scan(Scanner *s) {
    int c = getchar();
    int i = 0;
    while (c!= EOF && c!= '\n') {
        if (i < s->cap - 1) {
            s->buf[i++] = c;
        }
        c = getchar();
    }
    s->buf[i] = '\0';
    s->ptr = 0;
}

char *next(Scanner *s) {
    char *token = s->buf + s->ptr;
    while (s->buf[s->ptr]!= '\0' && s->buf[s->ptr]!='') {
        s->ptr++;
    }
    s->buf[s->ptr] = '\0';
    s->ptr++;
    return token;
}

int main() {
    Scanner *s = newScanner(1024);
    scan(s);
    int n = atoi(next(s));
    scan(s);
    int k = atoi(next(s));
    if (n % k == 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    freeScanner(s);
    return 0;
}

