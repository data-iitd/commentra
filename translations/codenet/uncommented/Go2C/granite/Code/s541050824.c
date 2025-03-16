
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    int i;
    int size;
} bufReader;

bufReader *reader;

void initReader() {
    reader = (bufReader *)malloc(sizeof(bufReader));
    reader->buf = (char *)malloc(1024 * sizeof(char));
    reader->i = 0;
    reader->size = 1024;
}

void freeReader() {
    free(reader->buf);
    free(reader);
}

void readLine() {
    if (reader->i < reader->size) {
        return;
    }
    reader->i = 0;
    reader->size = fread(reader->buf, sizeof(char), 1024, stdin);
    if (reader->size == 0) {
        reader->buf[0] = '\n';
        reader->size = 1;
    }
}

char *next() {
    readLine();
    int from = reader->i;
    while (reader->i < reader->size && reader->buf[reader->i]!='') {
        reader->i++;
    }
    char *s = (char *)malloc((reader->i - from + 1) * sizeof(char));
    memcpy(s, reader->buf + from, reader->i - from);
    s[reader->i - from] = '\0';
    reader->i++;
    return s;
}

char *nextLine() {
    readLine();
    char *s = (char *)malloc((reader->size - reader->i + 1) * sizeof(char));
    memcpy(s, reader->buf + reader->i, reader->size - reader->i);
    s[reader->size - reader->i] = '\0';
    reader->i = reader->size;
    return s;
}

int64_t nextInt() {
    char *s = next();
    int64_t n = atoll(s);
    free(s);
    return n;
}

void out(char *s) {
    printf("%s", s);
}

int64_t max(int64_t x, int64_t y) {
    return x > y? x : y;
}

int64_t min(int64_t x, int64_t y) {
    return x < y? x : y;
}

char *joinInts(int64_t *a, int n, char *sep) {
    char *s = (char *)malloc((n * 10 + 1) * sizeof(char));
    int i;
    for (i = 0; i < n; i++) {
        sprintf(s + i * 10, "%lld", a[i]);
        if (i < n - 1) {
            strcat(s, sep);
        }
    }
    s[n * 10] = '\0';
    return s;
}

int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

int main() {
    initReader();
    int64_t N = nextInt();
    int64_t *T = (int64_t *)malloc(N * sizeof(int64_t));
    int64_t *A = (int64_t *)malloc(N * sizeof(int64_t));
    int i;
    for (i = 0; i < N; i++) {
        T[i] = nextInt();
        A[i] = nextInt();
    }
    int64_t t = T[0], a = A[0];
    for (i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    out(joinInts(&t, 1, " ") + joinInts(&a, 1, "\n"));
    freeReader();
    return 0;
}
