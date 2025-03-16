
#include <stdio.h>
#include <stdlib.h>

// Initialize a global Scanner instance to read from standard input
typedef struct Scanner {
    FILE *fp;
    char buf[1048576];
    int len;
    int ptr;
} Scanner;

Scanner *in;

void initScanner(Scanner *s, FILE *fp) {
    s->fp = fp;
    s->len = 0;
    s->ptr = 0;
}

void scan(Scanner *s) {
    s->len = fread(s->buf, 1, 1048576, s->fp);
    s->ptr = 0;
}

int isSpace(char c) {
    return c =='' || c == '\n' || c == '\r' || c == '\t';
}

int nextInt(Scanner *s) {
    int n = 0;
    while (s->ptr < s->len && isSpace(s->buf[s->ptr])) {
        s->ptr++;
    }
    for (; s->ptr < s->len &&!isSpace(s->buf[s->ptr]); s->ptr++) {
        n = n * 10 + (s->buf[s->ptr] - '0');
    }
    return n;
}

int main() {
    in = (Scanner *)malloc(sizeof(Scanner));
    initScanner(in, stdin);
    scan(in);
    int n = nextInt(in);
    int k = nextInt(in);
    if (n % k == 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    return 0;
}

// Helper function to print a line of output
void Pln(int n,...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        printf("%d", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

