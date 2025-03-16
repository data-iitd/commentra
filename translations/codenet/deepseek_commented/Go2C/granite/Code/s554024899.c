
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize logger to include short file names
void initLogger() {
    setvbuf(stdout, NULL, _IOLBF, 0);
    setvbuf(stderr, NULL, _IOLBF, 0);
}

// Custom scanner struct to read input
typedef struct Scanner {
    FILE *r;
    char buf[1000];
    int p;
} Scanner;

// Function to create a new scanner
Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->r = stdin;
    s->p = 0;
    return s;
}

// Function to read the next word
char *next(Scanner *s) {
    s->pre(s);
    int start = s->p;
    while (s->p < 1000 && s->buf[s->p]!='') {
        s->p++;
    }
    char *result = (char *)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

// Function to read the next line
char *nextLine(Scanner *s) {
    s->pre(s);
    int start = s->p;
    s->p = 1000;
    char *result = (char *)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

// Function to read the next integer
int nextInt(Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

// Function to preprocess the buffer
void pre(Scanner *s) {
    if (s->p >= 1000) {
        s->readLine(s);
        s->p = 0;
    }
}

// Function to read a line from the input
void readLine(Scanner *s) {
    int c;
    int i = 0;
    while ((c = fgetc(s->r))!= EOF) {
        s->buf[i] = (char)c;
        i++;
        if (c == '\n') {
            break;
        }
    }
}

int main() {
    initLogger();
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

