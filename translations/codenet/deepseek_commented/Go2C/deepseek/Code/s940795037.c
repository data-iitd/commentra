#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t len;
    size_t pos;
} Scanner;

Scanner* newScanner() {
    Scanner *s = (Scanner*)malloc(sizeof(Scanner));
    s->buf = NULL;
    s->len = 0;
    s->pos = 0;
    return s;
}

void readLine(Scanner *s) {
    s->len = 0;
    s->buf = (char*)malloc(1000 * sizeof(char));
    fgets(s->buf, 1000, stdin);
    if (s->buf[strlen(s->buf) - 1] == '\n') {
        s->buf[strlen(s->buf) - 1] = '\0';
    }
}

char* next(Scanner *s) {
    while (s->pos < strlen(s->buf) && s->buf[s->pos] == ' ') {
        s->pos++;
    }
    if (s->pos >= strlen(s->buf)) {
        return NULL;
    }
    size_t start = s->pos;
    while (s->pos < strlen(s->buf) && s->buf[s->pos] != ' ') {
        s->pos++;
    }
    char *result = (char*)malloc((s->pos - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->pos - start);
    result[s->pos - start] = '\0';
    return result;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int value = atoi(token);
    free(token);
    return value;
}

int main() {
    Scanner *sc = newScanner();
    readLine(sc);

    int n = nextInt(sc);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = nextInt(sc);
        ans += 1.0 / tmp;
    }
    printf("%f\n", 1.0 / ans);

    free(sc->buf);
    free(sc);
    return 0;
}
