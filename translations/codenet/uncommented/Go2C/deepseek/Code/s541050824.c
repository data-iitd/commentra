#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char buf[MAX_LINE_LENGTH];
    size_t pos;
} bufReader;

bufReader reader = { .pos = 0 };

void readLine(bufReader *r) {
    if (r->pos < strlen(r->buf)) {
        return;
    }
    r->pos = 0;
    if (fgets(r->buf, MAX_LINE_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        exit(1);
    }
}

char *next(bufReader *r) {
    readLine(r);
    static char word[MAX_LINE_LENGTH];
    size_t from = r->pos;
    while (r->pos < strlen(r->buf) && r->buf[r->pos] != ' ') {
        r->pos++;
    }
    strncpy(word, r->buf + from, r->pos - from);
    word[r->pos - from] = '\0';
    if (r->pos < strlen(r->buf)) {
        r->pos++; // skip the space
    }
    return word;
}

char *nextLine(bufReader *r) {
    readLine(r);
    char *line = strdup(r->buf);
    r->pos = strlen(r->buf); // set pos to end of buffer
    return line;
}

void out(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int64_t max(int64_t x, int64_t y) {
    return x > y ? x : y;
}

int64_t min(int64_t x, int64_t y) {
    return x < y ? x : y;
}

char *joinInts(int64_t *a, size_t len, const char *sep) {
    char buffer[128];
    char *result = malloc(len * 128);
    result[0] = '\0';
    for (size_t i = 0; i < len; i++) {
        snprintf(buffer, sizeof(buffer), "%" PRId64, a[i]);
        if (i > 0) {
            strcat(result, sep);
        }
        strcat(result, buffer);
    }
    return result;
}

int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

void solve() {
    int64_t N;
    scanf("%" PRId64, &N);
    int64_t T[N], A[N];
    for (int64_t i = 0; i < N; i++) {
        scanf("%" PRId64 " %" PRId64, &T[i], &A[i]);
    }
    int64_t t = T[0], a = A[0];
    for (int64_t i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    out("%" PRId64 "\n", t + a);
}

int main() {
    solve();
    return 0;
}
