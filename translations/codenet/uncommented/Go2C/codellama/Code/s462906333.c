#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 10000

typedef struct {
    int a, b;
} Pair;

typedef struct {
    Pair *p;
    int n;
} Pairs;

int in(int c, int a, int z) {
    return c >= a && c < z;
}

int btoi(int b) {
    if (b) {
        return 1;
    }
    return 0;
}

int itob(int a) {
    if (a == 0) {
        return 0;
    }
    return 1;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int minmax(int a, int b) {
    if (a > b) {
        return b, a;
    }
    return a, b;
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int sum(int a, int b) {
    return a + b;
}

typedef struct {
    char *buf;
    int p;
    int n;
} scanner;

scanner *newScanner() {
    scanner *s = malloc(sizeof(scanner));
    s->buf = malloc(MAX_BUF);
    s->p = 0;
    s->n = 0;
    return s;
}

void pre(scanner *s) {
    if (s->p >= s->n) {
        s->readLine(s);
        s->p = 0;
    }
}

void readLine(scanner *s) {
    s->n = 0;
    while (1) {
        int c = getchar();
        if (c == EOF) {
            break;
        }
        s->buf[s->n++] = c;
        if (c == '\n') {
            break;
        }
    }
}

char *next(scanner *s) {
    pre(s);
    int start = s->p;
    for (; s->p < s->n; s->p++) {
        if (s->buf[s->p] == ' ') {
            break;
        }
    }
    char *result = malloc(s->p - start + 1);
    memcpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *line(scanner *s) {
    pre(s);
    int start = s->p;
    s->p = s->n;
    char *result = malloc(s->p - start + 1);
    memcpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

int int_(scanner *s) {
    char *str = next(s);
    int v = atoi(str);
    free(str);
    return v;
}

int int64(scanner *s) {
    char *str = next(s);
    int64_t v = atoll(str);
    free(str);
    return v;
}

int main() {
    scanner *next = newScanner();
    int n = int_(next);
    int x = int_(next);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = int_(next);
    }
    int *v = malloc(n * sizeof(int));
    memcpy(v, a, n * sizeof(int));
    int ans = 1e14;
    for (int k = 0; k < n; k++) {
        int kans = 0;
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = min(v[i], a[n + i - k]);
            } else {
                v[i] = min(v[i], a[i - k]);
            }
            kans += v[i];
        }
        ans = min(ans, kans + k * x);
    }
    printf("%d\n", ans);
    free(next);
    free(a);
    free(v);
    return 0;
}

