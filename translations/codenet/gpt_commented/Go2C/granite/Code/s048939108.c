
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    int p;
    int size;
    FILE *r;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->r = stdin;
    s->buf = (char *)malloc(1000 * sizeof(char));
    s->p = 0;
    s->size = 1000;
    return s;
}

char *next(Scanner *s) {
    int i;
    for (i = s->p; i < s->size; i++) {
        if (s->buf[i] =='') {
            break;
        }
    }
    char *result = (char *)malloc((i - s->p + 1) * sizeof(char));
    strncpy(result, s->buf + s->p, i - s->p);
    result[i - s->p] = '\0';
    s->p = i + 1;
    return result;
}

char *nextLine(Scanner *s) {
    int i;
    for (i = s->p; i < s->size; i++) {
        if (s->buf[i] == '\n') {
            break;
        }
    }
    char *result = (char *)malloc((i - s->p + 1) * sizeof(char));
    strncpy(result, s->buf + s->p, i - s->p);
    result[i - s->p] = '\0';
    s->p = i + 1;
    return result;
}

int nextInt(Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

int *nextIntArray(Scanner *s) {
    char *str = next(s);
    char *token = strtok(str, " ");
    int *result = (int *)malloc(100 * sizeof(int));
    int i = 0;
    while (token!= NULL) {
        result[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    free(str);
    return result;
}

void pre(Scanner *s) {
    if (s->p >= s->size) {
        readLine(s);
        s->p = 0;
    }
}

void readLine(Scanner *s) {
    free(s->buf);
    s->size = 1000;
    s->buf = (char *)malloc(s->size * sizeof(char));
    int i = 0;
    while (1) {
        s->buf[i] = fgetc(s->r);
        if (s->buf[i] == '\n') {
            break;
        }
        i++;
        if (i >= s->size) {
            s->size *= 2;
            s->buf = (char *)realloc(s->buf, s->size * sizeof(char));
        }
    }
}

int main() {
    Scanner *s = newScanner();
    char *S = next(s);
    if (strncmp(S, "YAKI", 5) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
