
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    int i;
} bufReader;

bufReader reader = {NULL, 0};

void initReader(FILE *r) {
    reader.buf = (char *)malloc(1024 * sizeof(char));
    reader.i = 0;
    fread(reader.buf, 1, 1024, r);
}

void freeReader() {
    free(reader.buf);
}

char *readLine() {
    if (reader.i < strlen(reader.buf)) {
        return NULL;
    }
    reader.i = 0;
    fread(reader.buf, 1, 1024, stdin);
    return reader.buf;
}

char *next() {
    static char buf[1024];
    int i = 0;
    char c;
    while (1) {
        c = reader.buf[reader.i++];
        if (c =='' || c == '\n') {
            break;
        }
        buf[i++] = c;
    }
    buf[i] = '\0';
    return buf;
}

int nextInt() {
    int i = 0;
    char c;
    while (1) {
        c = reader.buf[reader.i++];
        if (c =='' || c == '\n') {
            break;
        }
        i = i*10 + (c-'0');
    }
    return i;
}

char *nextLine() {
    static char buf[1024];
    int i = 0;
    char c;
    while (1) {
        c = reader.buf[reader.i++];
        if (c == '\n') {
            break;
        }
        buf[i++] = c;
    }
    buf[i] = '\0';
    return buf;
}

void out(char *s) {
    printf("%s", s);
}

int max(int a, int b) {
    return a > b? a : b;
}

int main() {
    FILE *r = fopen("input.txt", "r");
    FILE *w = fopen("output.txt", "w");
    initReader(r);
    int N = nextInt();
    int M = nextInt();
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = nextInt();
    }
    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        int profit = max(0, maxA-A[i]);
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        maxA = max(maxA, A[i]);
    }
    out(maxCnt);
    fclose(r);
    fclose(w);
    return 0;
}

