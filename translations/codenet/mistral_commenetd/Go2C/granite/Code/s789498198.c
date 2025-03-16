
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **buf;
    int cur;
    int r;
} Scanner;

Scanner sc;

void init() {
    sc.buf = malloc(sizeof(char *) * 100);
    sc.cur = 0;
    sc.r = 0;
}

void readln() {
    char buf[1000];
    fgets(buf, 1000, stdin);
    char *p = buf;
    while (*p!= '\n') {
        p++;
    }
    *p = '\0';
    sc.buf[sc.r] = malloc(sizeof(char) * strlen(buf));
    strcpy(sc.buf[sc.r], buf);
    sc.r++;
}

int isFull() {
    if (sc.cur == sc.r) {
        return 1;
    }
    return 0;
}

void resetCur() {
    sc.cur = 0;
}

char *next() {
    if (sc.cur == 0) {
        readln();
    }
    char *res = sc.buf[sc.cur];
    sc.cur++;
    if (isFull()) {
        resetCur();
    }
    return res;
}

int *nextInts() {
    readln();
    int *res = malloc(sizeof(int) * sc.r);
    for (int i = 0; i < sc.r; i++) {
        res[i] = atoi(sc.buf[i]);
    }
    resetCur();
    return res;
}

int digits(int x) {
    return strlen(itoa(x));
}

int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int max(int x, int y) {
    return x > y? x : y;
}

int min(int x, int y) {
    return x < y? x : y;
}

int abs(int x) {
    return x < 0? -x : x;
}

void varDump(int value,...) {
    va_list args;
    va_start(args, value);
    printf("%d\n", value);
    while (1) {
        int v = va_arg(args, int);
        if (v == -1) {
            break;
        }
        printf("%d\n", v);
    }
    va_end(args);
}

void yes() {
    printf("Yes\n");
}

void no() {
    printf("No\n");
}

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    Pair *v;
} Queue;

void push(Queue *q, Pair v) {
    q->v = realloc(q->v, sizeof(Pair) * (q->v? q->v[0].first + 1 : 1));
    q->v[q->v[0].first] = v;
    q->v[0].first++;
}

Pair pop(Queue *q) {
    Pair r = q->v[q->v[0].second];
    q->v[0].second++;
    return r;
}

Pair front(Queue q) {
    return q.v[q.v[0].second];
}

int empty(Queue q) {
    return q.v[0].second == q.v[0].first;
}

int main() {
    init();
    int *AB = nextInts();
    int A = AB[0];
    int B = AB[1];
    if ((A + B) % 2 == 0) {
        printf("%d\n", (A + B) / 2);
    } else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
