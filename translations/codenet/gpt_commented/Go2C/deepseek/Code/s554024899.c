#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char buf[MAX_LINE_LENGTH];
    int p;
} Scanner;

Scanner newScanner() {
    Scanner s;
    s.p = 0;
    return s;
}

char* next(Scanner* s) {
    while (s->p < strlen(s->buf) && s->buf[s->p] == ' ') {
        s->p++;
    }
    int start = s->p;
    while (s->p < strlen(s->buf) && s->buf[s->p] != ' ') {
        s->p++;
    }
    char* result = (char*)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

char* nextLine(Scanner* s) {
    int start = s->p;
    s->p = strlen(s->buf);
    char* result = (char*)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

int nextInt(Scanner* s) {
    char* token = next(s);
    int result = atoi(token);
    free(token);
    return result;
}

void pre(Scanner* s) {
    if (s->p >= strlen(s->buf)) {
        readLine(s);
        s->p = 0;
    }
}

void readLine(Scanner* s) {
    s->buf[0] = '\0';
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        int len = strlen(s->buf);
        s->buf[len] = ch;
        s->buf[len + 1] = '\0';
    }
}

int main() {
    Scanner sc = newScanner();
    readLine(&sc);

    int x = nextInt(&sc);
    int y = nextInt(&sc);

    int xt = -1, yt = -1;

    int a[3][7] = {
        {1, 3, 5, 7, 8, 10, 12},
        {4, 6, 9, 11},
        {2}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sizeof(a[i]) / sizeof(a[i][0]); j++) {
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
