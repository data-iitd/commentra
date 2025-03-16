#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char buf[MAX_LINE_LENGTH];
    size_t i;
} bufReader;

bufReader reader = { .i = 0 };

void readLine(bufReader *r) {
    if (r->i < strlen(r->buf)) {
        return;
    }
    r->i = 0;
    fgets(r->buf, MAX_LINE_LENGTH, stdin);
}

char *next(bufReader *r) {
    readLine(r);
    static char *token;
    token = strtok(r->buf + r->i, " ");
    while (token != NULL) {
        r->i += strlen(token);
        return token;
    }
    return NULL;
}

char *nextLine(bufReader *r) {
    readLine(r);
    r->i = 0;
    return r->buf;
}

void out(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

long long max(long long x, long long y) {
    return x > y ? x : y;
}

long long min(long long x, long long y) {
    return x < y ? x : y;
}

char *joinInts(long long *a, size_t len, const char *sep) {
    static char buffer[MAX_LINE_LENGTH];
    buffer[0] = '\0';
    for (size_t i = 0; i < len; i++) {
        char temp[20];
        sprintf(temp, "%lld", a[i]);
        if (i > 0) {
            strcat(buffer, sep);
        }
        strcat(buffer, temp);
    }
    return buffer;
}

long long divUp(long long x, long long y) {
    return (x + y - 1) / y;
}

void solve() {
    long long N;
    scanf("%lld", &N);
    getchar(); // Consume newline
    long long T[N], A[N];
    for (long long i = 0; i < N; i++) {
        T[i] = atoll(next(&reader));
        A[i] = atoll(next(&reader));
    }
    long long t = T[0], a = A[0];
    for (long long i = 1; i < N; i++) {
        long long r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    out("%lld\n", t + a);
}

int main() {
    solve();
    return 0;
}
