
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int p;
    int size;
    FILE *fp;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(sizeof(char) * 1000);
    s->p = 0;
    s->size = 1000;
    s->fp = stdin;
    return s;
}

char *next(Scanner *s) {
    int start = s->p;
    while (s->p < s->size && s->buf[s->p]!='') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    int start = s->p;
    s->p = s->size;
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
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

void pre(Scanner *s) {
    if (s->p >= s->size) {
        fgets(s->buf, s->size, s->fp);
        s->p = 0;
    }
}

void readLine(Scanner *s) {
    s->p = 0;
    fgets(s->buf, s->size, s->fp);
}

int main() {
    Scanner *s = newScanner();
    int x = nextInt(s);
    int y = nextInt(s);
    int xt = -1, yt = -1;
    int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (x == a[i][j]) {
                xt = i;
            }
            if (y == a[i][j]) {
                yt = i;
            }
        }
    }
    if (xt == yt) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
