#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 500001

typedef struct {
    char buffer[MAX_LINE_LENGTH];
    size_t pos;
    size_t size;
} Scanner;

void initScanner(Scanner *scanner, FILE *fp) {
    scanner->pos = 0;
    scanner->size = fread(scanner->buffer, 1, MAX_LINE_LENGTH, fp);
}

char nextChar(Scanner *scanner) {
    if (scanner->pos >= scanner->size) {
        scanner->size = fread(scanner->buffer, 1, MAX_LINE_LENGTH, scanner->fp);
        scanner->pos = 0;
    }
    return scanner->buffer[scanner->pos++];
}

int nextInt(Scanner *scanner) {
    int result = 0;
    char ch;
    while ((ch = nextChar(scanner)) >= '0' && ch <= '9') {
        result = result * 10 + (ch - '0');
    }
    return result;
}

long long nextInt64(Scanner *scanner) {
    long long result = 0;
    char ch;
    while ((ch = nextChar(scanner)) >= '0' && ch <= '9') {
        result = result * 10 + (ch - '0');
    }
    return result;
}

unsigned long long nextUint64(Scanner *scanner) {
    unsigned long long result = 0;
    char ch;
    while ((ch = nextChar(scanner)) >= '0' && ch <= '9') {
        result = result * 10 + (ch - '0');
    }
    return result;
}

double nextFloat64(Scanner *scanner) {
    double result = 0.0;
    char ch;
    while ((ch = nextChar(scanner)) >= '0' && ch <= '9') {
        result = result * 10 + (ch - '0');
    }
    return result;
}

void main() {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    Scanner scanner;
    initScanner(&scanner, fp);
    int n = nextInt(&scanner);
    int ll[n];

    for (int i = 0; i < n; i++) {
        ll[i] = nextInt(&scanner);
    }

    qsort(ll, n, sizeof(int), (int (*)(const void *, const void *))compare);

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) >> 1;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                    continue;
                }
                r = m;
            }
            ans += l - (j + 1);
        }
    }
    fprintf(wfp, "%d\n", ans);

    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);
}
