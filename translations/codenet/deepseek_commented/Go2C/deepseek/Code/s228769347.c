#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 500001

typedef struct {
    char buffer[MAX_LINE_LENGTH];
    size_t pos;
    size_t len;
} Scanner;

void initScanner(Scanner *scanner) {
    scanner->pos = 0;
    scanner->len = 0;
}

void fillBuffer(Scanner *scanner, FILE *fp) {
    scanner->len = fread(scanner->buffer, 1, MAX_LINE_LENGTH, fp);
    scanner->pos = 0;
}

char nextChar(Scanner *scanner, FILE *fp) {
    if (scanner->pos >= scanner->len) {
        fillBuffer(scanner, fp);
    }
    return scanner->buffer[scanner->pos++];
}

char* nextString(Scanner *scanner, FILE *fp) {
    char *str = (char*)malloc(MAX_LINE_LENGTH);
    size_t i = 0;
    char ch;
    while ((ch = nextChar(scanner, fp)) != ' ' && ch != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0';
    return str;
}

int nextInt(Scanner *scanner, FILE *fp) {
    char *str = nextString(scanner, fp);
    return atoi(str);
}

long long nextInt64(Scanner *scanner, FILE *fp) {
    char *str = nextString(scanner, fp);
    return atoll(str);
}

unsigned long long nextUint64(Scanner *scanner, FILE *fp) {
    char *str = nextString(scanner, fp);
    return strtoull(str, NULL, 10);
}

double nextFloat64(Scanner *scanner, FILE *fp) {
    char *str = nextString(scanner, fp);
    return atof(str);
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    Scanner scanner;
    initScanner(&scanner);

    int n = nextInt(&scanner, fp);
    int *ll = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        ll[i] = nextInt(&scanner, fp);
    }

    qsort(ll, n, sizeof(int), (int (*)(const void *, const void *))compare);

    int ans = 0;

    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) >> 1;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            ans += l - (j + 1);
        }
    }

    fprintf(wfp, "%d\n", ans);

    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    free(ll);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
