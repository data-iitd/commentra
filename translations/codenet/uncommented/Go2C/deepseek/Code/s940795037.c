#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t buf_size;
    size_t pos;
} Scanner;

Scanner* newScanner() {
    Scanner *s = (Scanner*)malloc(sizeof(Scanner));
    s->buf_size = 1000;
    s->buf = (char*)malloc(s->buf_size);
    s->pos = 0;
    return s;
}

void readLine(Scanner *s) {
    s->pos = 0;
    fgets(s->buf, s->buf_size, stdin);
}

char* next(Scanner *s) {
    while (s->pos < strlen(s->buf) && s->buf[s->pos] == ' ') {
        s->pos++;
    }
    if (s->pos >= strlen(s->buf)) {
        readLine(s);
    }
    char *start = &s->buf[s->pos];
    while (s->pos < strlen(s->buf) && s->buf[s->pos] != ' ') {
        s->pos++;
    }
    if (s->pos >= strlen(s->buf)) {
        readLine(s);
    }
    s->buf[s->pos] = '\0';
    return start;
}

int nextInt(Scanner *s) {
    return atoi(next(s));
}

int main() {
    Scanner *s = newScanner();
    int n = nextInt(s);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = nextInt(s);
        ans += 1.0 / tmp;
    }
    printf("%f\n", 1.0 / ans);
    free(s->buf);
    free(s);
    return 0;
}
