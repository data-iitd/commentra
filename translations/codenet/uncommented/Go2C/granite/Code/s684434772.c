
#include <stdio.h>
#include <stdlib.h>

typedef struct Scanner {
    FILE *fp;
    char buf[1024];
    int idx;
} Scanner;

Scanner *newScanner() {
    Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
    sc->fp = stdin;
    sc->idx = 0;
    return sc;
}

char *readWord(Scanner *sc) {
    if (sc->idx == 0) {
        fgets(sc->buf, 1024, sc->fp);
    }
    char *p = sc->buf + sc->idx;
    char *q = strchr(p,'');
    if (q == NULL) {
        sc->idx = 0;
        fgets(sc->buf, 1024, sc->fp);
        q = strchr(sc->buf,'');
    }
    *q = '\0';
    sc->idx = q - sc->buf + 1;
    return p;
}

int readInt(Scanner *sc) {
    char *s = readWord(sc);
    int n = atoi(s);
    return n;
}

int main() {
    Scanner *sc = newScanner();
    int n = readInt(sc);
    int k = readInt(sc);
    long long total = 0;
    for (int i = k; i <= n + 1; i++) {
        long long combi = combi(n, i);
        total += combi;
        total %= (Pow64(10, 9) + 7);
    }
    printf("%lld\n", total);
    return 0;
}

long long combi(int n, int k) {
    long long min = (long long)(k - 1) * k / 2;
    long long max = (long long)(2 * n - k + 1) * k / 2;
    return max - min + 1;
}

// util
// *   math/simple

int Abs(int x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

int Min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int Max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int Pow(int base, unsigned int exponent) {
    int answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

long long Abs64(long long x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

long long Min64(long long a, long long b) {
    if (a < b) {
        return a;
    }
    return b;
}

long long Max64(long long a, long long b) {
    if (a > b) {
        return a;
    }
    return b;
}

long long Pow64(long long base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

// *   io

