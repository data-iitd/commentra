
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

// Define a scanner structure
typedef struct {
    char *buf;
    int p;
    int size;
} scanner;

// Initialize a new scanner object
scanner newScanner() {
    scanner s;
    s.buf = (char *) malloc(MAX_BUFFER_SIZE * sizeof(char));
    s.p = 0;
    s.size = MAX_BUFFER_SIZE;
    return s;
}

// Function to read a single word from the input
char *next(scanner *s) {
    s->pre();
    int start = s->p;
    for (; s->p < s->size; s->p++) {
        if (s->buf[s->p] == ' ') {
            break;
        }
    }
    char *result = (char *) malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

// Function to read a line from the input
char *nextLine(scanner *s) {
    s->pre();
    int start = s->p;
    s->p = s->size;
    char *result = (char *) malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

// Function to read an integer from the input
int nextInt(scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

// Function to prepare the scanner for the next input
void pre(scanner *s) {
    if (s->p >= s->size) {
        s->readLine();
        s->p = 0;
    }
}

// Function to read a line from the input
void readLine(scanner *s) {
    s->buf = (char *) realloc(s->buf, MAX_BUFFER_SIZE * sizeof(char));
    s->size = MAX_BUFFER_SIZE;
    int i = 0;
    for (; i < s->size; i++) {
        s->buf[i] = '\0';
    }
    for (i = 0; i < s->size; i++) {
        char c = fgetc(stdin);
        if (c == EOF) {
            break;
        }
        s->buf[i] = c;
        if (c == '\n') {
            break;
        }
    }
    s->buf[i] = '\0';
}

// Function to find the maximum of two integers
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    scanner *sc = newScanner();
    int x = nextInt(sc);
    int y = nextInt(sc);
    int xt = 0;
    int yt = 0;
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

