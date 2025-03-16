
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
    char *word = (char *)malloc(sizeof(char) * 1024);
    int i = 0;
    while (1) {
        char c = sc->buf[sc->idx];
        if (c =='' || c == '\n' || c == '\0') {
            break;
        }
        word[i] = c;
        i++;
        sc->idx++;
        if (sc->idx == 1024) {
            fread(sc->buf, sizeof(char), 1024, sc->fp);
            sc->idx = 0;
        }
    }
    word[i] = '\0';
    return word;
}

int readInt(Scanner *sc) {
    char *word = readWord(sc);
    int num = atoi(word);
    free(word);
    return num;
}

int main() {
    Scanner *sc = newScanner();
    int n = readInt(sc);
    int k = readInt(sc);
    long long total = 0;
    for (int i = k; i <= n + 1; i++) {
        long long combi = combi(n, i);
        total += combi;
        total %= 100000007;
    }
    printf("%lld\n", total);
    return 0;
}

long long combi(int n, int k) {
    long long min = (long long)(k - 1) * k / 2;
    long long max = (long long)(2 * n - k + 1) * k / 2;
    return max - min + 1;
}

int abs(int x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int pow(int base, unsigned int exponent) {
    int answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

long long abs64(long long x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

long long min64(long long a, long long b) {
    if (a < b) {
        return a;
    }
    return b;
}

long long max64(long long a, long long b) {
    if (a > b) {
        return a;
    }
    return b;
}

long long pow64(long long base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

