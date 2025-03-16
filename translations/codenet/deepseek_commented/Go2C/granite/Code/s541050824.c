
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
typedef struct {
    char *buf;
    size_t size;
    size_t i;
} bufReader;

// bufReader initialization
static bufReader reader = {
   .buf = NULL,
   .size = 0,
   .i = 0,
};

// readLine reads a line from the input and stores it in the buffer.
static void readLine(bufReader *r) {
    if (r->i < r->size) {
        return;
    }
    r->size = 0;
    r->i = 0;
    for (;;) {
        int c = getchar();
        if (c == EOF) {
            exit(1);
        }
        r->buf = (char *)realloc(r->buf, r->size + 1);
        r->buf[r->size++] = c;
        if (c == '\n') {
            break;
        }
    }
}

// next returns the next space-separated word from the buffer.
static char *next(bufReader *r) {
    readLine(r);
    char *from = r->buf + r->i;
    for (; r->i < r->size; r->i++) {
        if (r->buf[r->i] =='') {
            break;
        }
    }
    r->buf[r->i] = '\0';
    r->i++;
    return from;
}

// nextLine returns the entire next line from the buffer.
static char *nextLine(bufReader *r) {
    readLine(r);
    char *s = r->buf + r->i;
    r->i = r->size;
    return s;
}

// bufio Writer initialization
static FILE *writer = stdout;

// nextInt reads the next token as an integer.
static int64_t nextInt(void) {
    char *s = next(&reader);
    char *end;
    int64_t n = strtoll(s, &end, 10);
    if (*end!= '\0') {
        exit(1);
    }
    return n;
}

// nextLine wraps the reader.nextLine() function.
static char *nextLine(void) {
    return nextLine(&reader);
}

// out prints the arguments to the output with a newline.
static void out(int n,...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            putchar(' ');
        }
        switch (va_arg(args, int)) {
            case 'd':
                printf("%lld", va_arg(args, long long));
                break;
            case's':
                printf("%s", va_arg(args, char *));
                break;
        }
    }
    putchar('\n');
    va_end(args);
}

// max returns the maximum of two integers.
static int64_t max(int64_t x, int64_t y) {
    return x > y? x : y;
}

// min returns the minimum of two integers.
static int64_t min(int64_t x, int64_t y) {
    return x < y? x : y;
}

// joinInts joins an array of integers into a string with a separator.
static char *joinInts(int64_t *a, int n, char *sep) {
    char *s = (char *)malloc(1024);
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            strcat(s + len, sep);
            len += strlen(sep);
        }
        sprintf(s + len, "%lld", a[i]);
        len += strlen(s + len);
    }
    return s;
}

// divUp returns the ceiling of the division of x by y.
static int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

// Main function
int main(void) {
    int64_t N = nextInt();
    int64_t *T = (int64_t *)malloc(N * sizeof(int64_t));
    int64_t *A = (int64_t *)malloc(N * sizeof(int64_t));
    for (int i = 0; i < N; i++) {
        T[i] = nextInt();
        A[i] = nextInt();
    }
    int64_t t = T[0], a = A[0];
    for (int i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    out(1, "d", t + a);
    return 0;
}
