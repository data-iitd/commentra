
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
    s->buf = (char *)malloc(sizeof(char) * 1000);
    s->size = 1000;
    s->p = 0;
    return s;
}

char *next(Scanner *s) {
    s->pre(s);
    int start = s->p;
    for (; s->p < s->size; s->p++) {
        if (s->buf[s->p] =='') {
            break;
        }
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    s->pre(s);
    int start = s->p;
    s->p = s->size;
    char *result = (char *)malloc(sizeof(char) * (s->p - start));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

int nextInt(Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

int *nextIntArray(Scanner *s) {
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    s->pre(s);
    int start = s->p;
    for (; s->p < s->size + 1; s->p++) {
        if (s->p == s->size || s->buf[s->p] =='') {
            char *str = (char *)malloc(sizeof(char) * (s->p - start));
            strncpy(str, s->buf + start, s->p - start);
            str[s->p - start] = '\0';
            result[i] = atoi(str);
            free(str);
            i++;
            start = s->p + 1;
        }
    }
    return result;
}

void pre(Scanner *s) {
    if (s->p >= s->size) {
        s->readLine(s);
        s->p = 0;
    }
}

void readLine(Scanner *s) {
    s->buf = (char *)realloc(s->buf, sizeof(char) * (s->size * 2));
    s->size *= 2;
    int c;
    int i = 0;
    while ((c = fgetc(s->r))!= '\n' && c!= EOF) {
        s->buf[i] = c;
        i++;
    }
    s->buf[i] = '\0';
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
