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
    s->buf = (char*)malloc(1000);
    fgets(s->buf, 1000, stdin);
}

char* next(Scanner *s) {
    while (s->pos < s->len && s->buf[s->pos] != ' ' && s->buf[s->pos] != '\n') {
        s->pos++;
    }
    char *token = (char*)malloc(s->pos - s->pos + 1);
    strncpy(token, s->buf, s->pos);
    token[s->pos] = '\0';
    s->pos++;
    return token;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int value = atoi(token);
    free(token);
    return value;
}

int main() {
    Scanner *s = newScanner();
    readLine(s);

    int n = nextInt(s);
    double arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    double prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }

    printf("%f\n", prev);

    free(s->buf);
    free(s);
    return 0;
}
