
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t cap;
    size_t len;
} Buffer;

void init_buffer(Buffer *b) {
    b->buf = malloc(1024);
    b->cap = 1024;
    b->len = 0;
}

void free_buffer(Buffer *b) {
    free(b->buf);
}

void append_buffer(Buffer *b, const char *s) {
    size_t n = strlen(s);
    if (b->len + n >= b->cap) {
        b->cap = b->len + n + 1024;
        b->buf = realloc(b->buf, b->cap);
    }
    memcpy(b->buf + b->len, s, n);
    b->len += n;
}

void read_long_lines(Buffer *b, int n) {
    char buf[1024];
    for (int i = 0; i < n; i++) {
        while (fgets(buf, sizeof(buf), stdin)) {
            append_buffer(b, buf);
        }
    }
}

void print_list(int *list, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", list[i]);
        } else {
            printf(" %d", list[i]);
        }
    }
    printf("\n");
}

int main() {
    Buffer buf;
    init_buffer(&buf);
    read_long_lines(&buf, 4);

    char *lines[4];
    char *p = buf.buf;
    for (int i = 0; i < 4; i++) {
        lines[i] = p;
        p += strlen(p) + 1;
    }

    int m[200000];
    int m_size = 0;
    char *a = lines[1];
    char *token = strtok(a, " ");
    while (token) {
        m[m_size++] = atoi(token);
        token = strtok(NULL, " ");
    }

    int result[200000];
    int result_size = 0;
    char *b = lines[3];
    token = strtok(b, " ");
    while (token) {
        int n = atoi(token);
        int found = 0;
        for (int i = 0; i < m_size; i++) {
            if (m[i] == n) {
                found = 1;
                break;
            }
        }
        if (!found) {
            m[m_size++] = n;
            result[result_size++] = n;
        }
        token = strtok(NULL, " ");
    }

    qsort(result, result_size, sizeof(int), cmpfunc);
    for (int i = 0; i < result_size; i++) {
        printf("%d\n", result[i]);
    }

    free_buffer(&buf);
    return 0;
}

