#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char buf[MAX_LINE_LENGTH];
    int p;
} Scanner;

Scanner* NewScanner() {
    Scanner* s = (Scanner*)malloc(sizeof(Scanner));
    s->p = 0;
    return s;
}

char* Next(Scanner* s) {
    while (s->p < strlen(s->buf) && s->buf[s->p] == ' ') {
        s->p++;
    }
    if (s->p >= strlen(s->buf)) {
        readLine(s);
        s->p = 0;
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

void readLine(Scanner* s) {
    fgets(s->buf, MAX_LINE_LENGTH, stdin);
}

int NextInt(Scanner* s) {
    char* str = Next(s);
    int result = atoi(str);
    free(str);
    return result;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    Scanner* sc = NewScanner();
    int H = NextInt(sc);
    int W = NextInt(sc);
    int N = NextInt(sc);

    int A = max(H, W);

    printf("%d\n", (N + A - 1) / A);

    free(sc);
    return 0;
}
