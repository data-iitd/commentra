
#include <stdio.h>
#include <stdlib.h>

// Initialize a global Scanner instance to read from standard input.
typedef struct Scanner {
    FILE *fp;
    char buf[1048576];
    int len;
    int ptr;
} Scanner;

Scanner *newScanner(FILE *fp) {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->fp = fp;
    s->len = 0;
    s->ptr = 0;
    return s;
}

void deleteScanner(Scanner *s) {
    free(s);
}

int scanWords(Scanner *s, char *buf, int max) {
    int i;
    for (i = 0; i < max && s->ptr < s->len; i++) {
        buf[i] = s->buf[s->ptr];
        if (buf[i] =='' || buf[i] == '\n' || buf[i] == '\r' || buf[i] == '\t') {
            break;
        }
        s->ptr++;
    }
    buf[i] = '\0';
    return i;
}

int intScan(Scanner *s) {
    char buf[1024];
    int n;
    sscanf(buf, "%d", &n);
    return n;
}

void Pln(int n,...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

int main() {
    Scanner *s = newScanner(stdin);
    int n = intScan(s);
    int k = intScan(s);
    if (n % k == 0) {
        Pln(1, 0);
    } else {
        Pln(1, 1);
    }
    deleteScanner(s);
    return 0;
}

