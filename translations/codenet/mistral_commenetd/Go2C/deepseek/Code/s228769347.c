#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 500001

typedef struct {
    char buf[MAX_BUF_SIZE];
    size_t pos;
    size_t len;
} Scanner;

Scanner* newScanner(FILE* fp) {
    Scanner* scanner = (Scanner*)malloc(sizeof(Scanner));
    scanner->pos = 0;
    scanner->len = 0;
    fread(scanner->buf, 1, MAX_BUF_SIZE, fp);
    return scanner;
}

void deleteScanner(Scanner* scanner) {
    free(scanner);
}

int scanInt(Scanner* scanner) {
    int num = 0;
    int sign = 1;
    while (scanner->buf[scanner->pos] == ' ') scanner->pos++;
    if (scanner->buf[scanner->pos] == '-') {
        sign = -1;
        scanner->pos++;
    }
    while (scanner->buf[scanner->pos] >= '0' && scanner->buf[scanner->pos] <= '9') {
        num = num * 10 + (scanner->buf[scanner->pos] - '0');
        scanner->pos++;
    }
    return num * sign;
}

long long scanLongLong(Scanner* scanner) {
    long long num = 0;
    int sign = 1;
    while (scanner->buf[scanner->pos] == ' ') scanner->pos++;
    if (scanner->buf[scanner->pos] == '-') {
        sign = -1;
        scanner->pos++;
    }
    while (scanner->buf[scanner->pos] >= '0' && scanner->buf[scanner->pos] <= '9') {
        num = num * 10 + (scanner->buf[scanner->pos] - '0');
        scanner->pos++;
    }
    return num * sign;
}

unsigned long long scanUnsignedLongLong(Scanner* scanner) {
    unsigned long long num = 0;
    while (scanner->buf[scanner->pos] == ' ') scanner->pos++;
    while (scanner->buf[scanner->pos] >= '0' && scanner->buf[scanner->pos] <= '9') {
        num = num * 10 + (scanner->buf[scanner->pos] - '0');
        scanner->pos++;
    }
    return num;
}

double scanDouble(Scanner* scanner) {
    double num = 0.0;
    int sign = 1;
    int decimal = 0;
    int place = 1;
    while (scanner->buf[scanner->pos] == ' ') scanner->pos++;
    if (scanner->buf[scanner->pos] == '-') {
        sign = -1;
        scanner->pos++;
    }
    while ((scanner->buf[scanner->pos] >= '0' && scanner->buf[scanner->pos] <= '9') || scanner->buf[scanner->pos] == '.') {
        if (scanner->buf[scanner->pos] == '.') {
            scanner->pos++;
            while (scanner->buf[scanner->pos] >= '0' && scanner->buf[scanner->pos] <= '9') {
                decimal = decimal * 10 + (scanner->buf[scanner->pos] - '0');
                place *= 10;
                scanner->pos++;
            }
            num = (double)num + (double)decimal / place;
            break;
        }
        num = num * 10 + (scanner->buf[scanner->pos] - '0');
        scanner->pos++;
    }
    return num * sign;
}

void printInt(FILE* fp, int num) {
    fprintf(fp, "%d\n", num);
}

int main(int argc, char* argv[]) {
    FILE* fp = stdin;
    FILE* wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    Scanner* scanner = newScanner(fp);

    int n = scanInt(scanner);
    int* ll = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        ll[i] = scanInt(scanner);
    }

    qsort(ll, n, sizeof(int), (int (*)(const void*, const void*))compare);

    int ans = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
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

    printInt(wfp, ans);

    fclose(fp);
    if (argc > 2) {
        fclose(wfp);
    }
    deleteScanner(scanner);

    free(ll);

    return 0;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

